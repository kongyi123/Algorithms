// hash O(N)
// 코드 최적화 x
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
//#include <map>
#include <unordered_map> // hash map

// map : treeMap
// unordered_map : hashMap
using namespace std;

int max(int a, int b) {
	if (a > b) return a;
	return b;
}

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {

		unordered_map<int, int> map;
		int maxVal = 0;
		for (auto n : nums) {
			if (!map[n]) {
				int left = map[n - 1] ? map[n - 1] : 0;
				int right = map[n + 1] ? map[n + 1] : 0;
				int sum = left + right + 1;

				map[n] = sum;
				maxVal = max(maxVal, sum);

				map[n - left] = sum;
				map[n + right] = sum;
			}
		}

		return maxVal;
	}
};


int main(void) {
	vector<int> nums;

	nums.push_back(1);
		nums.push_back(1);
		nums.push_back(4);
		nums.push_back(7);
		nums.push_back(3);
		nums.push_back(-1);
		nums.push_back(0);
		nums.push_back(5);
		nums.push_back(8);
		nums.push_back(-1);
		nums.push_back(6);
	
	Solution sol;
	int result = sol.longestConsecutive(nums);
	printf("max length = %d", result);

	return 0;
}