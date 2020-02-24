#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <map>

using namespace std;

map<pair<int, int>, int> mem;

int comb(int a, int b) {
	if (mem[pair<int, int>(a, b)] == 0) {
		if (b == 0 || a == b) mem[pair<int, int>(a,b)] = 1;
		else {
			mem[pair<int, int>(a, b)] = comb(a - 1, b - 1) + comb(a - 1, b);
		}
	}
	return mem[pair<int, int>(a, b)];
}

int main(void) {
	int n, a, b;
	long val = 1;
	scanf("%d %d %d", &n, &a, &b);
	for (int i = 1; i <= n; i++) {
		val = (val * 2) % 1000000007;
	}

	val -= 1;
	val -= comb(n, a);
	val -= comb(n, b);
	printf("%ld", val);
	return 0;
}