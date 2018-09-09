// heap sort�� ���� ������ �� �ð��ʰ��� �����ΰ�?
// heap sort�� ���ɰ� STL lib�� sort�Լ��� ������ ���غ� ��.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#define INF 0x7fffffff
#define dbg //printf

using namespace std;

inline void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int T, N, M;
int dat[4010][4];
int C[2][16000010], size_;



long long process() {
	// �ϴ� N^2 �� �ð� ���⵵�� A, B�� ���� �� �ִ� ������ �̾Ƴ�
	long long cnt = 0;
	int cur;
	int a = -2, b = -1;
	for (int k = 0;k <= 1;k++) {
		size_ = 0;
		a += 2; b += 2;
		for (int i = 1;i <= N;i++) {
			for (int j = 1;j <= N;j++) {
				size_++;
				cur = size_;
				C[k][cur] = dat[i][a] + dat[j][b];
				while (cur / 2 >= 1 && C[k][cur] > C[k][cur / 2]) {
					swap(C[k][cur], C[k][cur / 2]);
					cur = cur / 2;
				}
			}
		}


		// �� ��Ʈ
		int tval, tidx;
		for (int i = N*N;i >= 1;i--) {
			swap(C[k][1], C[k][i]);
			cur = 1;
			while (1) {
				tval = -INF;
				if (cur * 2 + 1 <= i - 1) {
					if (C[k][cur * 2] < C[k][cur * 2 + 1]) {
						tval = C[k][cur * 2 + 1]; tidx = cur * 2 + 1;
					}
					else {
						tval = C[k][cur * 2]; tidx = cur * 2;
					}
				}
				else if (cur * 2 <= i - 1) {
					tval = C[k][cur * 2]; tidx = cur * 2;
				}

				if (C[k][cur] < tval) {
					swap(C[k][cur], C[k][tidx]);
					cur = tidx;
				}
				else break;
			}
		}
	}

	int p, q;
	int NN = N*N;
	p = 1;
	q = NN;
	int s = 1;
	
	while (p <= NN && q >= 1) {
		if (C[0][p]+C[1][q] < 0) {
			p++;
			if (q != s) q = s;
		} else if (C[0][p]+C[1][q] > 0) {
			q--;
		}
		else {
			s = q; q--;
			cnt++;
		}
	}

	// �� ������ �����ؼ� ���
	return cnt;
}

int main(void) {
	//freopen("inputtxt.", "r", stdin);
	scanf("%d", &N);
	for (int i = 1;i <= N;i++) {
		for (int j = 0;j <= 3;j++) {
			scanf("%d", &dat[i][j]);
		}
	}


	printf("%lld", process());
	return 0;
}