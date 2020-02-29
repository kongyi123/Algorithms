// sort O(NlogN)
// 코드 최적화 x
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

int max(int a, int b) {
	if (a > b) return a;
	return b;
}

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		map<int, int> map;
		for (auto n : nums) {
			int val = map.find(n);
		}
		
		return maxVal;
	}
};



int main(void) {
	vector<int> nums;

	nums.push_back(1);
	/*	nums.push_back(1);
		nums.push_back(4);
		nums.push_back(7);
		nums.push_back(3);
		nums.push_back(-1);
		nums.push_back(0);
		nums.push_back(5);
		nums.push_back(8);
		nums.push_back(-1);
		nums.push_back(6);
	*/
	Solution sol;
	int result = sol.longestConsecutive(nums);
	printf("max length = %d", result);

	return 0;
}