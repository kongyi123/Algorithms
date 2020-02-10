// Leetcode 84 를 분할정복으로 푼 것 NlogN


#include <vector>

using namespace std;

class Solution {
public:
	int max(int a, int b) {
		if (a > b) return a;
		return b;
	}

	int getLargestValue(int s, int e, vector<int>& heights) {
		if (s >= e) return heights[s];
		int mid = (s + e) / 2;
		int maxValue;

		maxValue = max(getLargestValue(s, mid, heights), getLargestValue(mid + 1, e, heights));
		int l, r;
		int minHeight = heights[mid];
		l = mid; r = mid;
		while (s <= l && r <= e) {
			if (s < l && r < e) {
				if (heights[l-1] > heights[r+1]) {
					if (minHeight > heights[l-1]) minHeight = heights[l-1];
					l--;
				}
				else {
					if (minHeight > heights[r+1]) minHeight = heights[r+1];
					r++;
				}
			}
			else if (s < l) {
				if (minHeight > heights[l-1]) minHeight = heights[l-1];
				l--;
			}
			else if (r < e) {
				if (minHeight > heights[r+1]) minHeight = heights[r+1];
				r++;				
			}

			if (maxValue < minHeight * (r - l + 1))
				maxValue = minHeight * (r - l + 1);

			if (s == l && r == e) break;
		}
		return maxValue;
	}

	int largestRectangleArea(vector<int>& heights) {
		int len = heights.size();
		if (len == 0) return 0;
		return getLargestValue(0, len-1, heights);
	}
};

int main() {
	Solution sol;
	vector<int> heights;
	/*	heights.push_back(2);
	heights.push_back(1);
	heights.push_back(5);
	heights.push_back(6);
	heights.push_back(2);
	heights.push_back(3);*/

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