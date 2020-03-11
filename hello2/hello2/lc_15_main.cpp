#include "lc_15_1.cpp"
#include <stdio.h>
#include <ctime>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#define MAIN_DEBUG 0
#define TCNT 1000

using namespace std;

int main(void) {
	srand(time(0));
	int val;
	int n, i, tc;
	vector<vector<int>> ans;
	Solution sol;
	clock_t start = clock();
	for (tc = 1; tc <= TCNT; tc++) {
#if MAIN_DEBUG==1
		printf("tc count = %d\n", tc);
#endif
		vector<int> nums;
		n = rand() % 100;
		for (i = 1; i <= n; i++) {
			val = (rand() % 12) - 6;
			nums.push_back(val);
		}
		ans = sol.threeSum(nums);
#if MAIN_DEBUG==1
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

	printf("%0.5f", (float)(clock() - start) / CLOCKS_PER_SEC);
	return 0;
}


