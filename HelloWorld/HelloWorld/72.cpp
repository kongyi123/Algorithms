// 문자열 패턴 문제로써 어떤 풀이 방법이 있는지 관찰하는것으로 풀이 시작해야.


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int min(int a, int b) {
	if (a > b) return b;
	return a;
}

class Solution {
public:
	int minDistance(string word1, string word2) {
		int n = word1.size();
		int m = word2.size();
		int** dy = new int*[n+1];
		for (int i = 0; i < n+1; i++) dy[i] = new int[m+1];
		for (int i = 0; i <= n; i++) dy[i][0] = i;
		for (int i = 0; i <= m; i++) dy[0][i] = i;
		
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				int val = 2000000000;
				dy[i][j] = val;
				if (word1[i-1] == word2[j-1]) {
					val = min(val, dy[i - 1][j - 1]);
				}
				else {
					val = min(val, dy[i - 1][j] + 1);
					val = min(val, dy[i][j - 1] + 1);
					val = min(val, dy[i - 1][j - 1] + 1);
				}
				dy[i][j] = min(dy[i][j], val);
			}
		}

		return dy[n][m];
	}
};


int main(void) {
	Solution sol;
	string stra("intention");
	string strb("execution");
//	string stra("horse");
//	string strb("ros");
	int result = sol.minDistance(stra, strb);
	printf("%d", result);
	return 0;
}
