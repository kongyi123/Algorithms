#include <vector>

using namespace std;

class Solution {
public:
	int queue[10000];
	int head, tail;
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		head = tail = 0;
		int len = nums.size();
		vector<int> ans;
		for (int i = 0; i < len; i++) {
			if (head < tail && queue[head] < i - (k - 1)) head++;
			while (head < tail && nums[queue[tail-1]] < nums[i]) tail--;
			
			queue[tail++] = i;
			if (i >= k-1) {
				ans.push_back(nums[queue[head]]);
			}
		}

		return ans;
	}
};

int main(void) {
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(0);
	nums.push_back(5);
/*
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(-1);
	nums.push_back(-3);
	nums.push_back(5);
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(1);
	*/
	Solution sol;
	sol.maxSlidingWindow(nums, 3);
	return 0;
}