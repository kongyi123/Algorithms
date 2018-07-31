#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

int x[201];
int y[201];

int gcd(int a, int b) {
	if (a == 0 || b == 0) return 1;
	int tmp, n;

	//a�� ū ���� ��ġ��Ű�� ���� ���ǹ��Դϴ�.
	if (a<b) {
		tmp = a;
		a = b;
		b = tmp;
	}

	//��Ŭ���� �˰��� �κ��Դϴ�.
	//b�� 0�� �ɶ�����(a%b), �ݺ����� ���Եǰ�, b�� 0�� ������ a�� GCD�� �Ǵ��ϰ� �����մϴ�.
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
				int t = 0; // ��
				a = x[i] - x[j]; // dx
				b = y[i] - y[j]; // dy
				if (a * b < 0) t = 1; // ��
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