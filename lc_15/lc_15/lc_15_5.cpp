/*
	이 솔루션은 입력 원소의 min 과 max가 충분히 작다는 가정하에 적합할 수 있음
	가령 원소에다가 아래 두 숫자를 섞어서 포함 시키면 메모리 오류가 나옴
	-2000000000, 2000000000 

	Given an array nums of n integers  <- 문제를 이렇게 제시했는데... 테케가 확실히 형편없었음.

	다른 부분은 그대로 다 두고, 이전 코드에서 map처리 했던 부분 (혹은 이분검색) 으로 3번째 인자의 존재 유무를 찾아냈던 부분만
	배열 direct access로 바꾸니 충분히 빠르게 나온다. 

	아마 이전에 map 처리할때 필요했던 쓸모 없는 코드를 지우면 거의 상위 100%에 가까운 속도가 나올거라고 예상됨.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#define MAIN_DEBUG 1
#define INF 2000000000
#define DEBUG 2

using namespace std;
/*
struct node {
	int a, b;
	node(int p, int q) {
		a = p;
		b = q;
	}
	node() {}
};*/

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		int n = nums.size();
		if (n == 0) return result;
		int m = 0;
		vector<int> t;
		int* arr = new int[n];
		//		vector<node> map;
		sort(nums.begin(), nums.end()); // use/don't use?
		int i, j;
		arr[0] = nums[0];
		for (i = 1; i < n; i++) {
			if (arr[m] != nums[i]) {
				arr[++m] = nums[i];
			}
		}
		m++;

		int min = 0, max = 0;
		for (int i = 0; i < n; i++) {
			if (min > nums[i]) min = nums[i];
			if (max < nums[i]) max = nums[i];
		}
		vector<int> check(max - min + 1, 0);
		for (int i = 0; i < n; i++) {
			check[nums[i] + -min] ++;
		}

		if (check[-min] >= 3) result.push_back({ 0, 0, 0 });

		// 이 코드랑. 중복되는거 최소 2개씩 배열에 남겨놓고 돌리는거랑 별 차이 없다는거.. 차라리 이 코드가 더 깔끔해서 좋은듯.
		int k;
		for (i = 0; i < m; i++) { 
			if (arr[i] > 0) break; // 이것도 가지치기..
			for (j = i; j < m; j++) {
				if (i == j && check[-min + arr[j]] < 2) continue;
				if (!(-min + -(arr[i] + arr[j]) >= 0 && (-min + -(arr[i] + arr[j])) <= max - min)) continue;
				k = check[-min + -(arr[i] + arr[j])];
				if (k == 0) continue;
				if (arr[i] <= -(arr[i] + arr[j]) && arr[j] <= -(arr[i] + arr[j])) {
					if (arr[i] == 0 && arr[j] == 0) continue;
					if ((arr[i] == -(arr[i] + arr[j]) || arr[j] == -(arr[i] + arr[j])) && check[-min - (arr[i] + arr[j])] <= 1) continue;
					result.push_back({ arr[i], arr[j], -(arr[i] + arr[j]) });
				}
			}
		}
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

	vector<int> nums;
	nums.push_back(5);
	nums.push_back(-2);
	nums.push_back(-1);
//	nums.push_back(2);
//	nums.push_back(-1);
//	nums.push_back(-4);
//	nums.push_back(-1);
	//	nums.push_back(4);
	//	nums.push_back(2);
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

	//	}

	printf("%0.5f", (float)(clock() - start) / CLOCKS_PER_SEC);
	return 0;
}
