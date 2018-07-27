#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <memory.h>

using namespace std;

int dp[501][13];

int f(int n, char bit) {
	if (n < 0) return 0;		// 리프 노드면 0 반환
	if (n < 1) return bit == 0;	
	
	int& r = dp[n][bit];
	if (r != -1) return r;		// cache에 있다면 그 값을 반환

	r = 0;
	if (bit == 0) {				// 현재 상태 비었을 때
		r += f(n - 1, 0);
		r += f(n - 1, 3);
		r += f(n - 1, 9);
		r += f(n - 1, 12);
		r += f(n - 2, 0);	
	}
	if (bit == 3) {				// 현재 상태 밑에 두개만 찬 상태
		r += f(n - 1, 0);
		r += f(n - 1, 12);
	}
	if (bit == 6) {				// 현재 상태 중간 두개만 찬 상태
		r += f(n - 1, 9);
	}
	if (bit == 9) {				// 현재 상태 첫 칸 마지막 칸만 찬 상태
		r += f(n - 1, 0);
		r += f(n - 1, 6);
	}
	if (bit == 12) {			// 현재 상태 위 두칸만 찬 상태
		r += f(n - 1, 0);
		r += f(n - 1, 3);
	}
	return r;					// 리턴 할 값은 n까지 index가 bit의 상태일때의 카운트(해) 이다.
}

int main() {
	int t, n;
	scanf("%d", &t);
	memset(dp, -1, sizeof(dp));
	while (t--) {
		scanf("%d", &n);
		printf("%d\n", f(n, 0)); // 방문 순서는 역순.
	}
	return 0;
}