#include <stdio.h>
int N, M, H, a, b, arr[31][10], ans = 4;
void cf(int val) {
	int i, x, y;
	if (ans<val) return;
	for (i = 1;i<N;i++) {
		x = i; y = 1;
		while (y <= H) {
			if (x<N && arr[y][x] == 1) {
				x++; y++;
			}
			else if (x>1 && arr[y][x - 1] == 1) {
				x--; y++;
			}
			else y++;
		}
		if (x != i) return;
	}
	ans = val;
}
void BT(int n) {
	int i, j;
	if (n >= ans) return;
	for (j = 1;j<N;j++) {
		for (i = 1;i <= H;i++) {
			if (arr[i][j]) continue;
			if (j>1 && arr[i][j - 1]) continue;
			if (j<N - 1 && arr[i][j + 1]) continue;
			if (n >= ans) return;
			arr[i][j] = 1;
			cf(n);
			BT(n + 1);
			arr[i][j] = 0;
			while (1) {
				if (i >= H) break;
				if (j>1 && arr[i + 1][j - 1]) break;
				if (j<N - 1 && arr[i + 1][j + 1]) break;
				i++;
			}
		}
	}
}
int main() {
	int i;
	scanf("%d%d%d", &N, &M, &H);
	for (i = 1;i <= M;i++) {
		scanf("%d%d", &a, &b);
		arr[a][b] = 1;
	}
	cf(0);
	BT(1);
	if (ans == 4) printf("-1");
	else printf("%d", ans);
}