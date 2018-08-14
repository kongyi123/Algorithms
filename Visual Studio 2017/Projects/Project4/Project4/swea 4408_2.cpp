#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 202


int N;
int cnt[MAX];
int data[MAX][2];

int main(void) {
	int T;
	scanf("%d", &T);
	for (register int tc = 1;tc <= T;tc++) {
		for (register int i = 1;i <= N;i++) {
			cnt[data[i][0]] = cnt[data[i][1]] = 0;
		}
		scanf("%d", &N);

		for (register int i = 1;i <= N;i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			a = (a + 1) / 2;
			b = (b + 1) / 2;;
			if (a > b) {
				data[i][0] = b;
				data[i][1] = a+1;
				cnt[b] ++;
				cnt[a + 1] --;
			}
			else {
				data[i][0] = a;
				data[i][1] = b + 1;
				cnt[a] ++;
				cnt[b + 1] --;
			}
		}

		int max = 0;
		int t = 0;
		for (register int i = 1;i < MAX;i++) {
			t += cnt[i];
			if (max < t)
				max = t;
		}

		
		printf("#%d %d\n", tc, max);
	}

	return 0;
}