// sort O(NlogN)
// 코드 최적화 x
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

int max(int a, int b) {
	if (a > b) return a;
	return b;
}

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		int N = nums.size();
		if (N == 0) return 0;
		queue<long long> radix[10]; // 자리수에 대한 큐 배열
		sort(nums.begin(), nums.end());
		int cnt = 1;
		int maxVal = 1;
		long long last = nums[0];
		for (int i = 1; i < N; i++) {
			if (last + 1 == nums[i]) {
				last++;
				cnt++;
				maxVal = max(maxVal, cnt);
			}
			else if (last != nums[i]) {
				last = nums[i];
				cnt = 1;
			}
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