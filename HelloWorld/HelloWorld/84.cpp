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

	int largestRectangleArea(vector<int>& heights) {
		int n = heights.size();
		int max = 0, acc;
		for (int i = 0; i < n; i++) {
			acc = 0;
			while (isElement() && top().first > heights[i]) {
				acc += top().second;
				if (max < top().first * acc) {
					max = top().first * acc;
				}
				pop();
			}

			push(heights[i], acc+1);
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
};

int main() {
	Solution sol;
	vector<int> heights;
	heights.push_back(3);
	heights.push_back(6);
	heights.push_back(5);
	heights.push_back(7);
	heights.push_back(4);
	heights.push_back(8);
	heights.push_back(1);
	heights.push_back(0);

	printf("max = %d", sol.largestRectangleArea(heights));
	return 0;
}