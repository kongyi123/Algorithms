// 정렬하여 2중 for + map
// 중복이 3개 이상 있는 것은 skip

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
		if (n == 0) {
#if DEBUG==1
			printf("nums.size() == 0\n");
#endif
			return result;
		}
		int m = 0;
		int* arr = new int[n];
		sort(nums.begin(), nums.end());
		int same_count = 0;
		arr[0] = nums[0]; map[nums[0]] = 0;
		for (int i = 1; i < n; i++) {
			if (arr[m] == nums[i]) {
				same_count++;
				if (same_count <= 2) {
					arr[++m] = nums[i]; map[nums[i]] = m;
					continue;
				}
				else continue;
			}
			else {
				same_count = 0;
				arr[++m] = nums[i]; map[nums[i]] = m;
			}
		}
		m++;
#if DEBUG==1
		printf("arr[].size : %d\n", m);
		for (int i = 0; i < m; i++) {
			printf("%3d", arr[i]);
		}
		printf("\n\n");

#endif
		int k;
		for (int i = 0; i < m; i++) {
			if (i > 0 && arr[i] == arr[i - 1]) continue;
			for (int j = i + 1; j < m; j++) {
				if (j > i + 1 && arr[j] == arr[j - 1]) continue;
				k = map[-(arr[i] + arr[j])];
#if DEBUG==1
				printf("%d + %d + %d = 0 ", arr[i], arr[j], arr[k]);
#endif
				if (0 != k && j < k) {
					vector<int> t;
					t.push_back(arr[i]);
					t.push_back(arr[j]);
					t.push_back(arr[k]);
					result.push_back(t);
#if DEBUG==1
					printf(">> added\n");
#endif
				}
#if DEBUG==1
				else printf("\n");
#endif
			}
		}
		delete[]arr;

#if DEBUG==1
		printf("finish\n");

		for (int i = 0; i < result.size(); i++) {
			for (int j = 0; j < result[i].size(); j++) {
				printf("%3d ", result[i][j]);
			}
			printf("\n");
		}

		printf("\n");
#endif


		return result;
	}
};
