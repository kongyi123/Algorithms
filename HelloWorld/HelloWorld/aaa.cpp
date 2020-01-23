#include <vector>

using namespace std;

class Solution {
	int n, m;
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		n = dungeon.size();
		m = dungeon.at(0).size();
		
		int** min = new int* [n];
		int** cur = new int* [n];
		for (int i = 0; i < n; i++) {
			min[i] = new int[m];
			cur[i] = new int[m];
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				min[i][j] = cur[i][j] = dungeon[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int t, temp = -2000000000;
				if (i > 1) {
					if (min[i - 1][j] < cur[i - 1][j] + cur[i][j]) t = min[i - 1][j];
					else t = cur[i - 1][j] + cur[i][j];
					if (t > temp) temp = t;
				}
				if (j > 1) {
					if (min[i][j - 1] < cur[i][j - 1] + cur[i][j]) t = min[i][j - 1];
					else t = cur[i][j - 1] + cur[i][j];
					if (t > temp) temp = t;
				}
				if (temp == -2000000000) continue;
				cur[i][j] = temp;
			}
		}

		return dungeon[n - 1][m - 1];
	}
};

int main(void) {
	Solution sol;
	vector<vector<int>> vect;
	vector<int> col;
	col.push_back(-2);
	col.push_back(-3);
	col.push_back(3);
	vect.push_back(col);
	col.clear();

	col.push_back(-5);
	col.push_back(-10);
	col.push_back(1);
	vect.push_back(col);
	col.clear();

	col.push_back(10);
	col.push_back(30);
	col.push_back(-5);
	vect.push_back(col);
	col.clear();

	int dap = sol.calculateMinimumHP(vect);
	printf("dap = %d\n", dap);
	return 0;
}