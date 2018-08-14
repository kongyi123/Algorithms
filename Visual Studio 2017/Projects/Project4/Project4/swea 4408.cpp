#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 500


int N;
int cnt[MAX];

void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}

int main(void) {
	int T;
	scanf("%d", &T);
	for (int tc = 1;tc <= T;tc ++) {
		scanf("%d", &N);
		for (int i = 0;i < MAX;i ++) cnt[i] = 0;
		

		for (int i = 1;i <= N;i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			if (a % 2 == 1) a = a / 2 + 1;
			else a = a / 2;
			if (b % 2 == 1) b = b / 2 + 1;
			else b = b / 2;
			if (a > b) swap(a, b);
			for (int j = a;j <= b;j++) {
				cnt[j] ++;
			}
		}

		int max = 0;
		for (int i = 1;i < MAX;i++) {
			if (max < cnt[i]) max = cnt[i];
		}

		printf("#%d %d\n", tc, max);
	}

	
	return 0;
}