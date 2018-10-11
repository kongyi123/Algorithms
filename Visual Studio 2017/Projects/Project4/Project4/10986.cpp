// 40 - 99% Fail - 질문 보고 ... 48 AC


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, M;
int dat[1000001];

long long back(int s, int e) {
	if (s > e) return 0;
	if (s == e) {
		if (dat[s] % M == 0) return 1;
		return 0;
	}

	int mid = (s + e) / 2;
	long long cnt = 0;

	int sum = 0;
	int *count_a = new int[M+1](), *count_b = new int[M+1](); // 만들면서 0으로 초기화
	
	for (int i = mid;i >= s;i--) {
		sum = (sum + dat[i]) % M;
		count_a[sum] ++;
	}

	sum = 0;
	for (int i = mid + 1;i <= e;i++) {
		sum = (sum + dat[i]) % M;
		count_b[sum] ++;
		cnt += count_a[M - sum];
	}

	cnt += (long long)count_a[0] * (long long)count_b[0];

	delete[] count_a; // 삭제.. 실수 포인트
	delete[] count_b;
	return back(s, mid) + back(mid + 1, e) + cnt;
}

int main(void) {
//	freopen("input.txt", "r", stdin);
	scanf("%d%d", &N, &M);
	for (int i = 1;i <= N;i++) {
		scanf("%d", &dat[i]);
	}

	printf("%lld", back(1, N));
	return 0;
}