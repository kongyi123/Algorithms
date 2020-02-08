/*

	maximal-rectangle 2 sol

	made by kongyi.

*/


#include <vector>

using namespace std;

class Solution {
public:
	Solution() {
		ans = 0;
	}


	int max(int a, int b) {
		if (a > b) return a;
		return b;
	}


	int maximalRectangle(vector<vector<char>>& matrix) {
		if (matrix.size() == 0)
			return ans;

		const unsigned int n = matrix.size();
		const unsigned int m = matrix[0].size();

		vector<int> heights(m, 0);
		vector<int> left(m, 0);
		vector<int> right(m, m - 1);
		for (unsigned row = 0; row < n; row++) {
			for (unsigned col = 0; col < m; col++)
				if (matrix[row][col] == '0')
					heights[col] = 0;
				else
					heights[col]++;

			init_left(left, heights);
			init_right(right, heights);

			for (unsigned col = 0; col < m; col++)
				ans = max(ans, heights[col] * (right[col] - left[col] + 1));
		}

		return ans;
	}

private:
	int ans;

	void init_left(vector<int>& left, const vector<int>& heights) {
		int i;
		for (unsigned col = 1; col < heights.size(); col++) {
			i = col - 1;
			if (heights[col] > 0)
				while (i >= 0 && heights[i] >= heights[col])
					i = left[i] - 1;

			left[col] = i + 1;
		}
	}
	

	void init_right(vector<int>& right, const vector<int>& heights) {
		int i;
		for (int col = (int)heights.size() - 2; col >= 0; col--) {
			i = col + 1;
			if (heights[col] > 0)
				while (i < heights.size() && heights[i] >= heights[col])
					i = right[i] + 1;

			right[col] = i - 1;

		}
	}
};


int main() {
	Solution sol;
	vector<vector<char>> matrix;
		vector<char> line;
		line.push_back('1');
		line.push_back('0');
		line.push_back('1');
		line.push_back('0');
		line.push_back('0');
		matrix.push_back(line);
		vector<char> line2;
		line2.push_back('1');
		line2.push_back('0');
		line2.push_back('1');
		line2.push_back('1');
		line2.push_back('1');
		matrix.push_back(line2);
		vector<char> line3;
		line3.push_back('1');
		line3.push_back('1');
		line3.push_back('1');
		line3.push_back('1');
		line3.push_back('1');
		matrix.push_back(line3);
		vector<char> line4;
		line4.push_back('1');
		line4.push_back('0');
		line4.push_back('0');
		line4.push_back('1');
		line4.push_back('0');
		matrix.push_back(line4);
		

	//vector<char> line;
	//line.push_back('1');
	//matrix.push_back(line);


	printf("max = %d", sol.maximalRectangle(matrix));
	return 0;
}