/*

class Solution {
public:
	int jump(vector<int>& nums) {
		int n = nums.size();
		int* arr = new int[n];
		int maxIdx = 0, before_maxIdx = 0;
		int step = 0;
		arr[0] = 0;
		for (int i = 0; i < n; i++) {
			if (step != arr[i]) {
				before_maxIdx = maxIdx;
				step = arr[i];
			}
			if (maxIdx < i + nums[i]) {
				maxIdx = i + nums[i];
				if (maxIdx > n - 1)
					maxIdx = n - 1;
			}

			for (int j = before_maxIdx + 1; j <= maxIdx; j++) {
				arr[j] = arr[i] + 1;
			}
		}

		return arr[n - 1];
	}
};
*/

// step 변수 필요 없음. code optimization 포함
#include <vector>

using namespace std;


class Solution {
public:
	int jump(vector<int>& nums) {
		int i, n = nums.size();
		int* arr = new int[n];
		int maxIdx = 0, before_maxIdx = 0;
		arr[0] = 0;
		for (i = 0; i < n; i++) {
			if (maxIdx < i + nums[i]) {
				if (i + nums[i] > n - 1)
					maxIdx = n - 1;
				else maxIdx = i + nums[i];
			}
			for (int j = before_maxIdx + 1; j <= maxIdx; j++) arr[j] = arr[i] + 1;
			before_maxIdx = maxIdx;
		}

		return arr[n - 1];
	}
};



int main(void) {
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(4);
//	nums.push_back(2);
	//nums.push_back(5);
	//	nums.push_back(4);

	Solution sol;
	int result = sol.jump(nums);
	printf("\nresult = %d\n", result);
	return 0;
}
