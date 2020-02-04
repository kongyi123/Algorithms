#include <vector>

using namespace std;

class Solution {
public:
	pair<int, int> stack[10000];
	int p = -1;

	bool isElement() {
		if (p > -1) return true;
		return false;
	}

	void pop() {
		if (isElement()) p--;
	}

	pair<int, int> top() {
		return stack[p];
	}

	void push(int val, int cnt) {
		stack[++p] = pair<int, int>(val, cnt);
	}

	int largestRectangleArea(vector<char>& heights) {
		int n = heights.size();
		int max = 0, acc;
		for (int i = 0; i < n; i++) {
			acc = 0;
			while (isElement() && top().first > heights[i] - '0') {
				acc += top().second;
				if (max < top().first * acc) {
					max = top().first * acc;
				}
				pop();
			}

			push(heights[i] - '0', acc + 1);
		}

		acc = 0;
		while (isElement()) {
			acc += top().second;
			if (max < top().first * acc) {
				max = top().first * acc;
			}
			pop();
		}

		return max;
	}

	int maximalRectangle(vector<vector<char>>& matrix) {
		int n = matrix.size();
		if (n == 0) return 0;
		int m = matrix[0].size();
		int max = 0;
		for (int i = 0; i < n; i++) {
			if (i > 0) {
				for (int j = 0; j < m; j++) {
					if (matrix[i][j] == '0') continue;
					matrix[i][j] += (matrix[i - 1][j] - '0');
				}
			}
			int val = largestRectangleArea(matrix[i]);
			if (max < val)
				max = val;
		}
		return max;
	}
};

int main() {
	Solution sol;
	vector<vector<char>> matrix;
/*	vector<char> line;
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
	*/

	vector<char> line;
	line.push_back('1');
	matrix.push_back(line);


	printf("max = %d", sol.maximalRectangle(matrix));
	return 0;
}