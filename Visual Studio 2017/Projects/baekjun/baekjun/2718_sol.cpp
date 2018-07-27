#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <memory.h>

using namespace std;

int dp[501][13];

int f(int n, char bit) {
	if (n < 0) return 0;		// ���� ���� 0 ��ȯ
	if (n < 1) return bit == 0;	
	
	int& r = dp[n][bit];
	if (r != -1) return r;		// cache�� �ִٸ� �� ���� ��ȯ

	r = 0;
	if (bit == 0) {				// ���� ���� ����� ��
		r += f(n - 1, 0);
		r += f(n - 1, 3);
		r += f(n - 1, 9);
		r += f(n - 1, 12);
		r += f(n - 2, 0);	
	}
	if (bit == 3) {				// ���� ���� �ؿ� �ΰ��� �� ����
		r += f(n - 1, 0);
		r += f(n - 1, 12);
	}
	if (bit == 6) {				// ���� ���� �߰� �ΰ��� �� ����
		r += f(n - 1, 9);
	}
	if (bit == 9) {				// ���� ���� ù ĭ ������ ĭ�� �� ����
		r += f(n - 1, 0);
		r += f(n - 1, 6);
	}
	if (bit == 12) {			// ���� ���� �� ��ĭ�� �� ����
		r += f(n - 1, 0);
		r += f(n - 1, 3);
	}
	return r;					// ���� �� ���� n���� index�� bit�� �����϶��� ī��Ʈ(��) �̴�.
}

int main() {
	int t, n;
	scanf("%d", &t);
	memset(dp, -1, sizeof(dp));
	while (t--) {
		scanf("%d", &n);
		printf("%d\n", f(n, 0)); // �湮 ������ ����.
	}
	return 0;
}