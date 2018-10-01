// 23 - 28 - ������ ������ �ִٴ� ��. ���� ����صѰ�.
// ó���� �� �߰��� Ȯ���ض�.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

inline int abs(int a) {
	if (a > 0) return a;
	return -a;
}

int n, m;
int dat[25][25];
int cost[25];


void calc_cost() {
	int y = 20;
	int x = 20;
	int cnt = 0;
	for (int k = 0;k <= 20;k++) {
		cnt = 0;
		for (int i = 1;i <= 20 * 2;i++) {
			for (int j = 1;j <= 20 * 2;j++) {
				if (abs(y - i) + abs(x - j) <= k) {
					cnt++;
				}
			}
		}
		cost[k] = cnt;
	}
}

int process() {
	int house_cnt;
	int max = 0;
	for (int k = 0;k <= n;k++) { // �߽ɿ��������� �Ÿ�
		for (int i = 1;i <= n;i++) { // ��ġ ��ġ
			for (int j = 1;j <= n;j++) {
				house_cnt = 0;
				for (int y = 1;y <= n;y++) { // ��� ������ ���� ��ȸ
					for (int x = 1;x <= n;x++) {
						if (abs(i - y) + abs(j - x) <= k) {
							if (dat[y][x] == 1) {
								house_cnt++;
							}
						}
					}
				}

				if (house_cnt * m >= cost[k]) {
					if (max < house_cnt)
						max = house_cnt;
				}
			}
		}
	}

	return max;
}

int main(void) {
	int T;
	scanf("%d", &T);
	calc_cost();
	for (int tc = 1;tc <= T;tc++) {
		scanf("%d%d", &n, &m);
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) {
				scanf("%d", &dat[i][j]);
			}
		}

		printf("#%d %d\n", tc, process());
	}
	return 0;
}