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
		int same_count = 0;
		int i, j;
		// 이 작업을 빼니까 조금더 느려지긴 함.
/*		arr[0] = nums[0]; map.push_back(node(nums[0], 0));
		for (i = 1; i < n; i++) {
			if (arr[m] == nums[i]) {
				same_count++;
				if (same_count <= 2) {
					arr[++m] = nums[i];
					if (map.back().a == nums[i]) map.back().b = m;
				}
			}
			else {
				same_count = 0;
				arr[++m] = nums[i]; map.push_back(node(nums[i], m));
			}
		}
		m++;
		*/
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

		int k;
		for (i = 0; i < n; i++) {
			if (nums[i] > 0) break;
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			for (j = i + 1; j < n; j++) {
				if (j > i + 1 && nums[j] == nums[j - 1]) continue;
				if (!(-min + -(nums[i] + nums[j]) >= 0 && (-min + -(nums[i] + nums[j])) <= max - min)) continue;
				k = check[-min + -(nums[i] + nums[j])];
				if (k == 0) continue;
				if (nums[i] <= -(nums[i] + nums[j]) && nums[j] <= -(nums[i] + nums[j])) {
					if (nums[i] == 0 && nums[j] == 0) continue;
					if ((nums[i] == -(nums[i] + nums[j]) || nums[j] == -(nums[i] + nums[j])) && check[-min - (nums[i] + nums[j])] <= 1) continue;
					result.push_back({ nums[i], nums[j], -(nums[i] + nums[j]) });
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
