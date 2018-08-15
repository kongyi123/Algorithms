// <입력과 동시에 처리하는 경우 생기는 오류>
// 입력 받음과 동시에 처리하지 말 것 - 입력받는 데이터를 끝까지 다 살피기 전에 답이 나오는 문제의 경우에는 break 했다가 입력이 틀어지는 상황이 발생하기도함.
// 따라서 반드시 입력 모듈은 process 모듈과 별개로 두도록 하자.

// <문자열 비교시 종종 런타임에러가 발생하는 이유>
// 문자열 비교하는 경우 길이가 다른 두 문자열을 비교하는 경우가 상당히 많이 발생.
// strcmp를 사용하지 않고 직접 for문으로 구현하는 경우에 두 문자열중 더 짧은 길이 까지만 비교 => 이런 경우 런타임 에러가 발생할 수 있다.
// 문자열의 길이가 서로 다를때 두 문자는 다른 문자라는 조건을 미리 달지 않음.

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