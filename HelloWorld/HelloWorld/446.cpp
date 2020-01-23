// Arithmetic Slices II - Subsequence

#include <stdio.h>
#include <vector>

using namespace std;

//bool chk[1001][1001];


class Solution {
public:
	int N;
	int cnt = 0;

	int numberOfArithmeticSlices(vector<int>& A) {
		N = A.size();
		for (int i = 0; i < N-1; i++) {
			for (int j = i + 1; j < N; j++) {
				back(A, j, A[j]-A[i], 2);
			}
		}
		return cnt;
	}


	int back(vector<int>&A, int cur, int diff, int len) {
		int visited = 0;
		for (int i = cur + 1; i < N; i++) {
			if (diff != A[i] - A[cur]) continue;
			cnt++;
			back(A, i, diff, len + 1);
//		if (chk[cur][i]) continue;
//		chk[cur][i] = 1;
//			int val = back(A, i, diff, len + 1);
//			if (val != 0) visited = 1;
		}


		return cnt;
	} 

	
};



int main(void) {
	Solution sol;
	vector<int> A;
	A.push_back(2);
	A.push_back(4);
	A.push_back(6);
	A.push_back(8);
	A.push_back(10);
	
	int ans = sol.numberOfArithmeticSlices(A);
	printf("ans = %d", ans);
	return 0;

}