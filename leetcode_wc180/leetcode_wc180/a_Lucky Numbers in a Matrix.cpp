// 단순 초보적 구현 문제, 다시 안봐도 될 듯

class Solution {


public:
	int cnt[52][52] = { 0, };
	vector<int> luckyNumbers(vector<vector<int>>& matrix) {
		int n = matrix.size();
		int m = matrix[0].size();
		int idx, min, max;
		for (int i = 0; i < n; i++) {
			min = 2000000000;
			for (int j = 0; j < m; j++) {
				if (min > matrix[i][j]) {
					min = matrix[i][j];
					idx = j;
				}
			}
			cnt[i][idx] ++;
		}

		for (int j = 0; j < m; j++) {
			max = 0;
			for (int i = 0; i < n; i++) {
				if (max < matrix[i][j]) {
					max = matrix[i][j];
					idx = i;
				}
			}
			cnt[idx][j] ++;
		}

		vector<int> result;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (cnt[i][j] >= 2) {
					result.push_back(matrix[i][j]);
				}
			}
		}
		return result;
	}


};