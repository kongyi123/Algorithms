// 정렬하여 2중 for + map 
// 중복이 3개 이상 있는 것은 skip 
// + 코드 최적화

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define DEBUG 0

using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		unordered_map<int, int> map;
		int n = nums.size();
		if (n == 0) return result;
		int m = 0;
		int* arr = new int[n];
		vector<int> t;

		sort(nums.begin(), nums.end());
		int same_count = 0;
		arr[0] = nums[0]; 
		map[nums[0]] = 0;
		for (int i = 1; i < n; i++) {
			if (arr[m] == nums[i]) {
				same_count++;
				if (same_count <= 2) {
					arr[++m] = nums[i]; 
					map[nums[i]] = m;
				}
			}
			else {
				same_count = 0;
				arr[++m] = nums[i]; 
				map[nums[i]] = m;
			}
		}
		m++;
		int k;
		for (int i = 0; i < m; i++) {
			if (i > 0 && arr[i] == arr[i - 1]) continue;
			for (int j = i + 1; j < m; j++) {
				if (j > i + 1 && arr[j] == arr[j - 1]) continue;
				k = map[-(arr[i] + arr[j])];
				if (0 != k && j < k) {
					t.clear();
					t.push_back(arr[i]);
					t.push_back(arr[j]);
					t.push_back(arr[k]);
					result.push_back(t);
				}
			}
		}
		return result;
	}
};
