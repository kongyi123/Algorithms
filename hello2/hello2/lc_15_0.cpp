// 정렬하여 3중 for
// 중복이 3개 이상 있는 것은 skip

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
#define DEBUG 0

using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
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
		arr[0] = nums[0];
		for (int i = 1; i < n; i++) {
			if (arr[m] == nums[i]) {
				same_count++;
				if (same_count <= 2) {
					arr[++m] = nums[i];
					continue;
				} 
				else continue;
			}
			else {
				same_count = 0;
				arr[++m] = nums[i];
			}
		}
		m++;
#if DEBUG==5
		printf("arr[].size : %d\n", m);
		for (int i = 0; i < m; i++) {
			printf("%3d", arr[i]);
		}
		printf("\n");
#endif
		
		for (int i = 0; i < m; i++) {
			if (i > 0 && arr[i] == arr[i - 1]) continue;
			for (int j = i+1; j < m; j++) {
				if (j > i + 1 && arr[j] == arr[j - 1]) continue;
				for (int k = j + 1; k < m; k++) {
					if (k > j + 1 && arr[k] == arr[k - 1]) continue;
					if (0 == arr[i] + arr[j] + arr[k]) {
						vector<int> t;
						t.push_back(arr[i]);
						t.push_back(arr[j]);
						t.push_back(arr[k]);
						result.push_back(t);
#if DEBUG==1
						printf("added\n");
#endif
					}
				}
			}
		}
		delete []arr;

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
