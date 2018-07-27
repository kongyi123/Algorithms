#include <cstdio>
#include <cstring>

int dp[31][4][16];
int n;

int f(int x, int y, int bit) {
	if (x == 0) return 1;
	if (y == 4) return f(x - 1, 0, bit);
	if (~dp[x][y][bit]) return dp[x][y][bit];
	if (bit&(1 << y)) return f(x, y + 1, bit ^ (1 << y));
	int ret = 0;
	if (x != 1) ret += f(x, y + 1, bit | (1 << y));
	if (y == 0 && (bit & 3) == 0) {
		ret += f(x, y + 2, bit);
	}
	if (y == 1 && (bit & 6) == 0) {
		ret += f(x, y + 2, bit);
	}
	if (y == 2 && (bit & 12) == 0) {
		ret += f(x, y + 2, bit);
	}
	return dp[x][y][bit] = ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		printf("%d\n", f(n, 0, 0));
	}
}