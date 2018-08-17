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
	if (i == 0) {	// 새로 둘 수 있는 사다리를 다 둬본 경우
		for (j = 1; j <= t; j++) { // c를 임시보관해두는 배열 ci
			ci[j].x = c[j].x;
			ci[j].y = c[j].y;
		}

		// 사다리가 추가 된 부분으로 인해 바뀌는 부분만 처리를 한다.
		for (j = 1; j <= t; j++) {		// 일단, 사다리 때문에 바뀌는 부분을 바꿔주고.
			for (k = 1; k <= x; k++) {	// 다음 사다리에 영향을 주는 부분만 다음 사다리 요소에서 바꿔준다.
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
		for (i = 1; i <= x; i++) {	// 사다리 게임의 결과가 각자 자기위치인 경우인지 확인
			if (i != po[i]) break;
		}
		if (i == x + 1 && mmin > t) mmin = t; // 각자 자기 위치라면 min값 갱신
		for (j = 1; j <= t; j++) {	// c를 복구
			c[j].x = ci[j].x;
			c[j].y = ci[j].y;
		}
		for (j = 1; j <= x; j++) po[j] = poi[j];	// 초기화
		return;
	}
	for (j = xx; j <= ss; j++) {	// 추가 사다리를 xx위치서부터 ss위치까지 놓아보는 경우
		if (map[bb[j].x][bb[j].y] == 0) { // 그자리에 사다리가 비어있으면
			map[bb[j].x][bb[j].y]++;
			map[bb[j].x][bb[j].y - 1]++;
			map[bb[j].x][bb[j].y + 1]++;
			t++;
			c[t].x = bb[j].xx;	// 추가된 사다리의 위치를 저장하는 배열  : c
			c[t].y = bb[j].yy;
			asd(i - 1, j); // 사다리를 하나 추가하고 
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
	for (i = 1; i <= y; i++) {					// map에는 사다리를 놓을 수 없는 위치를 표시
		scanf("%d %d", &b[i].x, &b[i].y);
		map[b[i].x][b[i].y]++;			
		map[b[i].x][b[i].y - 1]++;
		map[b[i].x][b[i].y + 1]++;
	}
	sort(b + 1, b + y + 1);
	for (i = 1; i <= x; i++) po[i] = i;
	int s = 1;
	for (i = 1; i <= z; i++) { // 높이만큼 반복
		for (j = 1; j < x; j++) { // 가로만큼 하는데 (즉, 한칸씩 다 바꾼 경우를 만들어봄)
			if (map[i][j] == 0) {	// 비어있어서 새로 사다리를 놓을 수 있는 부분이라면
				ss++;	
				bb[ss].x = i;  // 놓을 수 있는 공간의 위치를 저장
				bb[ss].y = j; 
				bb[ss].xx = po[j]; // 
				bb[ss].yy = po[j + 1]; 
			}
			else if (b[s].x == i && b[s].y == j) { // 이미 사다리가 놓여져 있는 위치인 경우
				s++; 
				int t = po[j]; 
				po[j] = po[j + 1]; 
				po[j + 1] = t; 
			}
		}
	}
	for (i = 1; i <= x; i++) poi[i] = po[i]; // 사다리를 추가 안했을 때 사다리게임 결과
	asd(0, 1);	// 사다리를 두지 않는 경우
	asd(1, 1);  // 사다리를 하나만 쓰는 경우
	asd(2, 1);  // 사다리를 두개 새로 두는 경우
	asd(3, 1);  // 사다리를 세개 새로 두는 경우
	if (mmin <= 3) printf("%d", mmin); else printf("-1");
	return 0;
}