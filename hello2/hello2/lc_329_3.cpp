/*
Runtime: 84 ms, faster than 31.47 % of C++ online submissions for Longest Increasing Path in a Matrix.
Memory Usage : 10.3 MB, less than 100.00 % of C++ online submissions for Longest Increasing Path in a Matrix.
*/

class Solution {
public:
	int dfs(vector<vector<int>>& m, int i, int j, int v, vector<vector<int>>& len)
	{
		if (i < 0 || j < 0 || i == m.size() || j == m[0].size() || m[i][j] <= v) return 0;
		return len[i][j] > 0 ? len[i][j] : len[i][j] = 1 + max(
			max(dfs(m, i - 1, j, m[i][j], len), dfs(m, i + 1, j, m[i][j], len)),
			max(dfs(m, i, j - 1, m[i][j], len), dfs(m, i, j + 1, m[i][j], len)));
	}

	int longestIncreasingPath(vector<vector<int>>& m, int res = 0) {
		vector<vector<int>> len(m.size(), vector<int>(m.size() == 0 ? 0 : m[0].size()));
		for (auto i = 0; i < m.size(); ++i)
			for (auto j = 0; j < m[0].size(); ++j) res = max(res, dfs(m, i, j, m[i][j] - 1, len));
		return res;
	}
};
