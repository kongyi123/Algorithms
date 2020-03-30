/*
	optimyze lc_315_0
	(removed map)
Runtime: 24 ms, faster than 97.19% of C++ online submissions for Count of Smaller Numbers After Self.
Memory Usage: 8.4 MB, less than 100.00% of C++ online submissions for Count of Smaller Numbers After Self.
*/

#include <stdio.h>
#include <vector>

using namespace std;


class Solution {
public:
	int n;
	int* temp_arr, *arr;
	int* tcnt, *cnt;
	int* idx, *tidx;
	int* map;

	void merge(int s, int e, int* arr) {
		if (s >= e) return;
		int mid = (s + e) / 2;
		merge(s, mid, arr);
		merge(mid + 1, e, arr);

		int p = mid, q = e;
		int t = e;
		while (s <= p && mid + 1 <= q) {
			if (arr[p] > arr[q]) {
				temp_arr[t] = arr[q];
				tidx[t] = idx[q];
				tcnt[t--] = cnt[q--];
			}
			else {
				temp_arr[t] = arr[p];
				tidx[t] = idx[p];
				tcnt[t--] = cnt[p--] + (e - q);
			}
		}

		while (s <= p) {
			temp_arr[t] = arr[p];
			tidx[t] = idx[p];
			tcnt[t--] = cnt[p--] + (e - q);
		}

		while (mid + 1 <= q) {
			temp_arr[t] = arr[q];
			tidx[t] = idx[q];
			tcnt[t--] = cnt[q--];
		}

		for (int i = s; i <= e; i++) {
			arr[i] = temp_arr[i];
			idx[i] = tidx[i];
			cnt[i] = tcnt[i];
		}

	}

	vector<int> countSmaller(vector<int>& nums) {
		vector<int> result;
		n = nums.size();
		arr = new int[n];
		temp_arr = new int[n];
		cnt = new int[n];
		tcnt = new int[n];
		idx = new int[n];
		tidx = new int[n];
		map = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = nums[i];  cnt[i] = 0; idx[i] = i;
		}

		if (n == 0) return result;
		else merge(0, n - 1, arr);

		for (int i = 0; i < n; i++) map[idx[i]] = cnt[i];
		for (int i = 0; i < n; i++) {
			result.push_back(map[i]);
		}
		return result;
	}
};


int main(void) {
	Solution sol;
	vector<int> nums;
	sol.countSmaller(nums);

	return 0;
}