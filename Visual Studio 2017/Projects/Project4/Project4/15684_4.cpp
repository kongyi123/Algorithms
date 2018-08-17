// ����ġ��� �����̰�... ����ġ�⸦ ������ ��쿡 ����� ������ Ǯ�̰� �Ƿ���
// check�Լ��� ȿ�������� �����ؾ�.

// �����忡���� ��� �Ұ��ΰ�?.... �ִ��� ����ġ�⸦ �ϴ°� ����������..�ƴϸ� 
// Ȯ���� �ַ���� ���ø��°�...??
// ���ѽð��� ���س��� ����ؼ� �ȵǸ� �ִ��� ����ġ�⸦�ϴ�������...

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define INF 0x7fffffff

int N, H, M;
int table[300][20];
int min = INF;
int newladder[10][2];
int state[300][20];
int pos[20];

int check(int newladder_cnt) { // ¦�� �ٸ����� ���� ��ȯ
	int a, b;
	int temp[10][2];
	for (int i = 1;i <= N;i++) pos[i] = state[H][i];
	for (int i = 0;i < newladder_cnt;i++) {
		temp[i][0] = newladder[i][0];
		temp[i][1] = newladder[i][1];
	}
	
	for (int i = 0;i < newladder_cnt;i++) {
		a = temp[i][0];
		b = temp[i][1];
		for (int j = 1;j <= N;j++) {
			if (pos[j] == a) pos[j] = b;
			else if (pos[j] == b) pos[j] = a;
		}
		
		for (int j = i + 1;j < newladder_cnt;j++) {
			if (temp[j][0] == a) temp[j][0] = b;
			else if (temp[j][0] == b) temp[j][0] = a;
			if (temp[j][1] == a) temp[j][1] = b;
			else if (temp[j][1] == b) temp[j][1] = a;
		}
	}

	int diff_cnt = 0;
	for (int i = 1;i <= N;i++) {
		if (pos[i] != i) diff_cnt++;
	}

	return diff_cnt;
}

void back(int cnt, int row) {
//	if (min < cnt) return;
	if (cnt <= 3) {
		int t;
		if ((t = check(cnt)) == 0) {
			if (min > cnt) {
				min = cnt;
			}
		}
//		if (t > (3 - cnt) * 2) return;


		for (int i = row;i <= H;i++) {			// ���� �����
			for (int j = 1;j <= N - 1;j++) {
				if (table[i][j] == 0 && table[i][j + 1] == 0) {
					table[i][j] = 1; table[i][j + 1] = -1;
					newladder[cnt][0] = state[i][j];
					newladder[cnt][1] = state[i][j + 1];
					back(cnt + 1, i);
					table[i][j] = table[i][j + 1] = 0;
				}
			}
		}

	}
	else return;
}

void swap(int &a, int &b) {
	int t;
	t = a;
	a = b;
	b = t;
}

int main(void) {
	int a, b;
	scanf("%d %d %d", &N, &M, &H);

	for (int i = 1;i <= M;i++) {
		scanf("%d %d", &a, &b);
		table[a][b] = 1;
		table[a][b + 1] = -1;
	}
	
	for (int i = 1;i <= N;i++) state[0][i] = i;
	for (int i = 1;i <= H;i++) {
		for (int j = 1;j <= N;j++) state[i][j] = state[i - 1][j];
		for (int j = 1;j <= N;j++) {
			if (table[i][j] == 1 && table[i][j + 1] == -1) {
				swap(state[i][j], state[i][j + 1]);
			}
		}
	}
	

	back(0, 1);

	if (min == INF) {
		printf("-1");
	}
	else printf("%d", min);
	return 0;
}