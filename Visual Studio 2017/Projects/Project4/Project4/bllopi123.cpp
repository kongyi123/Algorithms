#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;
bool p[2000001];
int n;
bool ck(int *a, int lo, int hi) {
	if (lo >= hi)return 1;
	if (a[lo] != a[hi])return 0;
	return ck(a, lo + 1, hi - 1);
}
bool chk(int x) {
	int c = -1;
	int a[8];
	while (x) {
		a[++c] = x % 10;
		x /= 10;
	}
	return ck(a, 0, c);
}
int main() {
	scanf("%d", &n);
	for (int i = 2; i <= 2000000; i++) {
		if (p[i])continue;
		for (int j = i + i; j <= 2000000; j += i)
			p[j] = true;
	}
	p[1] = true;
	for (int i = n; i <= 2000000; i++) {
		if (p[i])continue;
		if (chk(i)) {
			printf("%d\n", i);
			return 0;
		}
	}
	return 0;
}