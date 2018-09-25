#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

using namespace std;

int dat[40000];
int n, m;
int dap[40000];
int dcnt;

int main(void) {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 1;i <= n;i++) {
		scanf("%d", &dat[i]);
	}
	scanf("%d", &m);
	for (int i = 1;i <= m;i++) {
		int p, q;
		scanf("%d %d", &p, &q);
		dcnt = 0;
		for (int j = p;j <= q;j++) {
			dap[++dcnt] = dat[j];
		}
		sort(&dap[1], &dap[1] + dcnt);

		for (int i = 1;i <= dcnt;i++) {
			if (dap[i] == dap[i - 1]) continue;
			printf("%d ", dap[i]);
		}
		printf("\n");
	}
	return 0;
}