#include <vector>

using namespace std;

int* arr;

void mergesort(int s, int e, vector<int>& nums) {
	if (s >= e) return;
	int mid = (s + e) / 2;
	mergesort(s, mid, nums);
	mergesort(mid + 1, e, nums);
	int p = s, q = mid + 1;
	int t = s;
	while (p <= mid && q <= e) {
		if (nums[p] > nums[q]) arr[t++] = nums[q++];
		else arr[t++] = nums[p++];
	}
	while (p <= mid) arr[t++] = nums[p++];
	while (q <= e) arr[t++] = nums[q++];

	for (int i = s; i <= e; i++) {
		nums[i] = arr[i];
	}
}


class Solution {
public:
	int maximumGap(vector<int>& nums) {
		int max = 0;
		int len = nums.size();
		arr = new int[len];
		mergesort(0, len - 1, nums);


		for (int i = 0; i < len - 1; i++) {
			if (max < nums[i + 1] - nums[i])
				max = nums[i + 1] - nums[i];
		}


		return max;
	}
};

int main() {
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(6);
	nums.push_back(9);
	nums.push_back(1);
	Solution sol;
	int ans = sol.maximumGap(nums);
	printf("ans = %d", ans);
	return 0;
}