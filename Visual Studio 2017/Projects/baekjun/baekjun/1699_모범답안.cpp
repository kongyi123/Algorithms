#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define IN stdin
#define OUT stdout

//FILE *in = fopen("input.txt", "r");
//FILE *out = fopen("output.txt", "w");


int n;
int m;
int num[100010];
int dp[100010];

int main(void) {
	fscanf(IN, "%d", &n);
	for (int i = 1;i*i <= n;i++) {
		num[++m] = i*i;
	}

	for (int i = 0;i <= n;i++) {
		dp[i] = 1000000000;
	}

	dp[0] = 0;
	for (int i = 1;i <= m;i++) {	// 제곱수 유형의 수
		int cur_num = num[i];
		for (int j = cur_num;j <= n;j++) {			// 앞에서 부터 세는 냅색은 중복사용을 용인하는 것.
			if (dp[j - cur_num] + 1 < dp[j]) {		// 뒤에서 부터 세는 냅색은 중복사용을 용인하지 않는. 
				dp[j] = dp[j - cur_num] + 1;
			}
		}
	}

	fprintf(OUT, "%d", dp[n]);
	return 0;
}
