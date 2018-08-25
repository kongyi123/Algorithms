#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define INF 0x7fffffff

int N;
int dat[110];
int min = INF;
int max = -INF;

void back(int cur, int plus, int minus, int product, int nanugi, int cnt) {
	if (cnt == N) {
		if (max < cur) max = cur;
		if (min > cur) min = cur;
		return;
	}

	if (plus) back(cur + dat[cnt + 1], plus - 1, minus, product, nanugi, cnt + 1);
	if (minus) back(cur - dat[cnt + 1], plus, minus - 1, product, nanugi, cnt + 1);
	if (product) back(cur * dat[cnt + 1], plus, minus, product - 1, nanugi, cnt + 1);
	if (nanugi) back(cur / dat[cnt + 1], plus, minus, product, nanugi - 1, cnt + 1);

}

int main(void) {
	scanf("%d", &N);
	for (int i = 1;i <= N;i++) {
		scanf("%d", &dat[i]);
	}
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	back(dat[1], a, b, c, d, 1);

	printf("%d\n", max);
	printf("%d\n", min);
	return 0;
}