#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>
using namespace std;
struct data {
	int x, y, xx, yy;
	inline bool operator<(const data &temp)const {
		return x < temp.x || (x == temp.x && y<temp.y);
	}
}b[500], bb[500], c[10], ci[10];
int map[20][40], x, y, z, po[50], t = 0, ss, poi[50], mmin = 2147483647;
void asd(int i, int xx) {
	int j, k;
	if (i == 0) {	// ���� �� �� �ִ� ��ٸ��� �� �ֺ� ���
		for (j = 1; j <= t; j++) { // c�� �ӽú����صδ� �迭 ci
			ci[j].x = c[j].x;
			ci[j].y = c[j].y;
		}

		// ��ٸ��� �߰� �� �κ����� ���� �ٲ�� �κи� ó���� �Ѵ�.
		for (j = 1; j <= t; j++) {		// �ϴ�, ��ٸ� ������ �ٲ�� �κ��� �ٲ��ְ�.
			for (k = 1; k <= x; k++) {	// ���� ��ٸ��� ������ �ִ� �κи� ���� ��ٸ� ��ҿ��� �ٲ��ش�.
				if (po[k] == c[j].x) po[k] = c[j].y;
				else if (po[k] == c[j].y) po[k] = c[j].x;
			}
			for (k = j + 1; k <= t; k++) {
				if (c[k].x == c[j].x) c[k].x = c[j].y;
				else if (c[k].x == c[j].y) c[k].x = c[j].x;
				if (c[k].y == c[j].x) c[k].y = c[j].y;
				else if (c[k].y == c[j].y) c[k].y = c[j].x;
			}
		}
		for (i = 1; i <= x; i++) {	// ��ٸ� ������ ����� ���� �ڱ���ġ�� ������� Ȯ��
			if (i != po[i]) break;
		}
		if (i == x + 1 && mmin > t) mmin = t; // ���� �ڱ� ��ġ��� min�� ����
		for (j = 1; j <= t; j++) {	// c�� ����
			c[j].x = ci[j].x;
			c[j].y = ci[j].y;
		}
		for (j = 1; j <= x; j++) po[j] = poi[j];	// �ʱ�ȭ
		return;
	}
	for (j = xx; j <= ss; j++) {	// �߰� ��ٸ��� xx��ġ������ ss��ġ���� ���ƺ��� ���
		if (map[bb[j].x][bb[j].y] == 0) { // ���ڸ��� ��ٸ��� ���������
			map[bb[j].x][bb[j].y]++;
			map[bb[j].x][bb[j].y - 1]++;
			map[bb[j].x][bb[j].y + 1]++;
			t++;
			c[t].x = bb[j].xx;	// �߰��� ��ٸ��� ��ġ�� �����ϴ� �迭  : c
			c[t].y = bb[j].yy;
			asd(i - 1, j); // ��ٸ��� �ϳ� �߰��ϰ� 
			map[bb[j].x][bb[j].y]--;
			map[bb[j].x][bb[j].y - 1]--;
			map[bb[j].x][bb[j].y + 1]--;
			t--;
		}
	}
}

int main() {
	int i, j;
	scanf("%d %d %d", &x, &y, &z);
	for (i = 1; i <= y; i++) {					// map���� ��ٸ��� ���� �� ���� ��ġ�� ǥ��
		scanf("%d %d", &b[i].x, &b[i].y);
		map[b[i].x][b[i].y]++;			
		map[b[i].x][b[i].y - 1]++;
		map[b[i].x][b[i].y + 1]++;
	}
	sort(b + 1, b + y + 1);
	for (i = 1; i <= x; i++) po[i] = i;
	int s = 1;
	for (i = 1; i <= z; i++) { // ���̸�ŭ �ݺ�
		for (j = 1; j < x; j++) { // ���θ�ŭ �ϴµ� (��, ��ĭ�� �� �ٲ� ��츦 ����)
			if (map[i][j] == 0) {	// ����־ ���� ��ٸ��� ���� �� �ִ� �κ��̶��
				ss++;	
				bb[ss].x = i;  // ���� �� �ִ� ������ ��ġ�� ����
				bb[ss].y = j; 
				bb[ss].xx = po[j]; // 
				bb[ss].yy = po[j + 1]; 
			}
			else if (b[s].x == i && b[s].y == j) { // �̹� ��ٸ��� ������ �ִ� ��ġ�� ���
				s++; 
				int t = po[j]; 
				po[j] = po[j + 1]; 
				po[j + 1] = t; 
			}
		}
	}
	for (i = 1; i <= x; i++) poi[i] = po[i]; // ��ٸ��� �߰� ������ �� ��ٸ����� ���
	asd(0, 1);	// ��ٸ��� ���� �ʴ� ���
	asd(1, 1);  // ��ٸ��� �ϳ��� ���� ���
	asd(2, 1);  // ��ٸ��� �ΰ� ���� �δ� ���
	asd(3, 1);  // ��ٸ��� ���� ���� �δ� ���
	if (mmin <= 3) printf("%d", mmin); else printf("-1");
	return 0;
}