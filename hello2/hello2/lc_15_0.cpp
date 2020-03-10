#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctime>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#define DEBUG 4
#define TCNT 500

using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		int n = nums.size();
		int m = 0;
		int* arr = new int[n];
		sort(nums.begin(), nums.end());
		arr[0] = nums[0];
		for (int i = 1; i < n; i++) {
#if DEBUG==1
			if (i >= nums.size()) {
				printf("error!!");
				exit(0);
			}
#endif
			if (arr[m] == nums[i]) continue;
			arr[++m] = nums[i];
		}
		m++;
#if DEBUG==1
		printf("arr[].size : %d\n", m);
		for (int i = 0; i < m; i++) {
			printf("%3d", arr[i]);
		}
		printf("\n");
#endif
		
		for (int i = 0; i < m; i++) {
			for (int j = i+1; j < m; j++) {
				for (int k = j + 1; k < m; k++) {
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


int main(void) {
	srand(time(0));
	int val;
	int n, i, tc;
	vector<vector<int>> ans;
	Solution sol;
	clock_t start = clock();
	for (tc = 1; tc <= TCNT; tc++) {
#if DEBUG==1
		printf("tc count = %d\n", tc);
#endif
		vector<int> nums;
		n = rand() % 100;
		if (n == 0) {
			printf("hi");
		}
		for (i = 1; i <= n; i++) {
			val = (rand() % 6) - 3;
			nums.push_back(val);
		}
		ans = sol.threeSum(nums);
#if DEBUG==1
		printf("print ans ans.size() : %d\n", ans.size());
		for (int i = 0; i < ans.size(); i++) {
			for (int j = 0; j < ans[i].size(); j++) {
				printf("%d ", ans[i][j]);
			}
			printf("\n");
		}
		printf("\n\n\n");
#endif

	}

#if DEBUG==3
	printf("%0.5f", (float)(clock() - start) / CLOCKS_PER_SEC);
#endif
	return 0;
}


