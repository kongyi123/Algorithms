/*
Runtime: 88 ms, faster than 30.84% of C++ online submissions for Longest Increasing Path in a Matrix.
Memory Usage: 10.8 MB, less than 100.00% of C++ online submissions for Longest Increasing Path in a Matrix.
*/
#include <vector>

using namespace std;

const int dr[] = { 0, 0, 1, -1 };
const int dc[] = { 1, -1, 0, 0 };

class Solution {
private:
	int incPath(vector<vector<int>>& matrix, int r, int c, vector<vector<int>>& dp) {
		if (dp[r][c] != 0) {
			return dp[r][c];
		}

		int res = 1;
		int row = matrix.size();
		int col = matrix[0].size();
		for (int i = 0; i < 4; ++i) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr >= 0 && nr < row && nc >= 0 && nc < col && matrix[nr][nc] > matrix[r][c]) {
				res = max(res, 1 + incPath(matrix, nr, nc, dp));
			}
		}

		dp[r][c] = res;
		return res;
	}

public:
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		if (matrix.empty() || matrix[0].empty()) {
			return 0;
		}

		int res = 0;

		int row = matrix.size();
		int col = matrix[0].size();
		vector<vector<int>> dp(row, vector<int>(col, 0));
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				res = max(res, incPath(matrix, i, j, dp));
			}
		}

		return res;
	}
};

#if DEBUG
int main(int argc, char** argv) {
	return 0;
}
#endif