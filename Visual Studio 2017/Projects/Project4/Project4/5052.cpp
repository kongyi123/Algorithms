// <�Է°� ���ÿ� ó���ϴ� ��� ����� ����>
// �Է� ������ ���ÿ� ó������ �� �� - �Է¹޴� �����͸� ������ �� ���Ǳ� ���� ���� ������ ������ ��쿡�� break �ߴٰ� �Է��� Ʋ������ ��Ȳ�� �߻��ϱ⵵��.
// ���� �ݵ�� �Է� ����� process ���� ������ �ε��� ����.

// <���ڿ� �񱳽� ���� ��Ÿ�ӿ����� �߻��ϴ� ����>
// ���ڿ� ���ϴ� ��� ���̰� �ٸ� �� ���ڿ��� ���ϴ� ��찡 ����� ���� �߻�.
// strcmp�� ������� �ʰ� ���� for������ �����ϴ� ��쿡 �� ���ڿ��� �� ª�� ���� ������ �� => �̷� ��� ��Ÿ�� ������ �߻��� �� �ִ�.
// ���ڿ��� ���̰� ���� �ٸ��� �� ���ڴ� �ٸ� ���ڶ�� ������ �̸� ���� ����.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <string.h>
#define MOD 10003

using namespace std;

int N;
vector<int> v[MOD];
char d[10005][12];

inline int mod(long long a) {
	return a % MOD;
}

int main(void) {
	int T;
	int len, NO;
	int t;
	int H, er;
	int len2;
	scanf("%d", &T);
	for (int i = 1;i <= T;i++) {
		for (int j = 0;j < MOD;j++) v[j].clear();
		scanf("%d", &N);
		NO = 0;
		for (int j = 1;j <= N;j++) {
			scanf("%s", d[j]);
			H = 0;
			len = strlen(d[j]);
			t = 1;
			for (int k = 0;k < len;k++) {
				H = mod(H + 1LL * d[j][k] * t);
				t = mod(t * 2);
			}
			v[H].push_back(j);
		}

		for (int j = 1;j <= N;j++) {
			H = 0;
			len = strlen(d[j]);
			t = 1;
			for (int k = 0;k < len;k++) {
				H = mod(H + 1LL * d[j][k] * t);
				if (!v[H].empty()) {
					for (int p : v[H]) {
						if (p == j) continue;
						er = 0;
						len2 = strlen(d[p]);
						if (len2 != k + 1) er = 1;
						else {
							for (int l = 0;l <= k;l++) {
								if (d[p][l] != d[j][l]) {
									er = 1; break;
								}
							}
						}
						if (er == 0) {
							NO = 1;
							break;
						}
					}
				}
				if (NO) break;
				t = mod(t * 2);
			}

			if (NO) break;
		}


		if (NO == 0) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}