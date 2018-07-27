// 즉, bitmask dp는
// check[2][2][2][2][2][2][2][2][2][2] = 1;
// 이런식으로 코딩하기는 사실상 불가능 하기 때문에 이것을 2,3진수화 하여 체크를 하는... 그러한 체크 방식을 쓴 다이나믹을 의미한다.

#define _CRT_SECURE_NO_WARNINGS
#include<functional>
#include<algorithm>
#include<iostream>
#include<climits>
#include<cstring>
#include<iomanip>
#include<cstdio>
#include<vector>
#include<string>
#include<limits>
#include<cmath>
#include<stack>
#include<queue>
#include<list>
#include<set>
#include<map>
#define IN in
#define OUT out
using namespace std;

FILE *in = fopen("input.txt", "r");
FILE *out = fopen("output.txt", "w");

int dp[11][1 << 11];
char board[11][11];
int n, m;

int check(int current, int previous) {
	for (int i = 1; i < (1 << m); i <<= 1) {
		if ((current & i)) {	// 이번 행의 i번째 열에 학생이 앉아 있을때
			if ((previous & (i * 2)) || (previous & (i / 2))) // 이전 행의 i-1 or i+1 번째 열에 학생이 앉아 있으면
				return false;	// fail이다.
		}
	}
	return true;
}
int visited[11] = { 0 };

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int t;
	fscanf(IN, "%d", &t);	// 테스트 케이스 입려
	while (t--) {		// 테스트 케이스 반복
		
		// 초기화
		memset(dp, 0, sizeof(dp));		
		memset(dp, 0, sizeof(board));
		
		// 입력
		fscanf(IN, "%d %d", &n, &m);
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < m; j++) {
				fscanf(IN, "%c", &board[i][j]);
			}
		}




		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < (1 << m); j++) { // 1 << m   =>    2의 m승  , 즉, 학생이 있을 수 있는 모든 상태를 의미
				
				
				// 1. 연속된 자리 배정상태 배제
				// 2. 빈공간에 앉아 있는 것인지 체크
				int mmax = 0, bit = 0; 
				bool isPossible = true;
				int idx = m - 1;
				for (int k = 1; k < (1 << m); k <<= 1) {				//		k = 0001, 0010, 0100, 1000
					if ((j & k) && board[i][idx] == '.') bit++;			// 그 자리가 빈공간 이면 ++
					if (j & k && j & (k << 1)) {	// 가능성 확인  (	// k << 1 = 0010, 0100, 1000, ...
						isPossible = false;								// 만약 바로 옆자리에 학생이 있다고 했다면.. 그것은 제외 즉, 0110 이런식으로 자리 배정이 연속으로 된 상태를 배제하고 고려하려고
						break;
					}
					idx--;
				}
				if (!isPossible) continue;	// 연속된 자리배정을 제외
				
				

				int a = 0;
				for (int k = 0; k < (1 << m); k++) {
					if (check(j, k)) {	 // 이번 행에서 가능한 이전 행 체크 후 가능하면 그중에서 max 갱신 받음
						if (mmax < dp[i - 1][k]) {
							mmax = max(dp[i - 1][k], mmax);
							a = k;
						}

					}
				}
				dp[i][j] = mmax + bit; // 이번 행에 앉을 수 있는 최대 학생수 + 이전 행의 max
				ans = max(ans, dp[i][j]);			// 최대값 갱신
			}
		}
		fprintf(OUT, "%d", ans);
	}
}