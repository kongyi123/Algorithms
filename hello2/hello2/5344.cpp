// 5344. How Many Numbers Are Smaller Than the Current Number

#define _CRT_SECURE_NO_WARNING
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

class Solution {
public:
	int rank[110];
	int copy[501];

	vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
		vector<int> result(nums.size());
		for (int i = 0; i < 110; i++) rank[i] = -1;
		for (int i = 0; i < nums.size(); i++) copy[i] = nums[i];
		sort(copy, copy+nums.size());
		for (int i = 0; i < nums.size(); i++) {
			if (rank[copy[i]] == -1) rank[copy[i]] = i;
		}
		for (int i = 0; i < nums.size(); i++) result[i] = rank[nums[i]];
		

		return result;
	}
};

int main(void) {
	Solution sol;
	vector<int> nums;
	nums.push_back(6);
	nums.push_back(5);
	nums.push_back(4);
	nums.push_back(8);

	//nums.push_back(8);
	//nums.push_back(1);
	//nums.push_back(2);
	//nums.push_back(2);
	//nums.push_back(3);


		//nums.push_back(7);
		//nums.push_back(7);
		//nums.push_back(7);
		//nums.push_back(7);
	sol.smallerNumbersThanCurrent(nums);
	
	return 0;
}