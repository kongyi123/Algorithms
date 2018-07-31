#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

int x[201];
int y[201];

int gcd(int a, int b) {
	if (a == 0 || b == 0) return 1;
	int tmp, n;

	//a에 큰 값을 위치시키기 위한 조건문입니다.
	if (a<b) {
		tmp = a;
		a = b;
		b = tmp;
	}

	//유클리드 알고리즘 부분입니다.
	//b가 0이 될때까지(a%b), 반복문을 돌게되고, b가 0인 순간의 a를 GCD로 판단하고 리턴합니다.
	while (b != 0) {
		n = a%b;
		a = b;
		b = n;
	}
	return a;
}

int abs(int a) {
	if (a < 0) return -a;
	return a;
}


int check[2001][2001][2];

int main(void) {
	int T;
	scanf("%d", &T);
	for (int tc = 1;tc <= T;tc++) {
		int N;
		scanf("%d", &N);
		for (int i = 1;i <= N;i++) {
			scanf("%d %d", &x[i], &y[i]);
		}

		int cnt = N*(N - 1) / 2;
		for (int i = 1;i <= N;i++) {
			for (int j = i + 1;j <= N;j++) {
				int a, b, c;
				int t = 0; // 양
				a = x[i] - x[j]; // dx
				b = y[i] - y[j]; // dy
				if (a * b < 0) t = 1; // 음
				a = abs(a);
				b = abs(b);
				c = gcd(a, b);
				if (b == 0) a = 1;
				if (a == 0) b = 0;
				if (check[a/c][b/c][t] != tc) {
					check[a/c][b/c][t] = tc;
				}
				else cnt--;


			}
		}

		printf("#%d %d\n", tc, cnt);
	}
	return 0;
}