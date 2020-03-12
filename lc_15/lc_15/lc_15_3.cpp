// 정렬하여 2중 for + map직접구현
// 중복이 3개 이상 있는 것은 skip
// map 직접 구현 (정렬 + 이분검색, 사실 map과는 약간 다름)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <ctime>
#include <stdlib.h>
#define MAIN_DEBUG 1
#define TCNT 5000
#define DEBUG 1
#define NO_VALUE 2000000000

using namespace std;

struct node {
	int a, b;
	node(int p, int q) {
		a = p;
		b = q;
	}
	node() {}
};

class Solution {
public:
	int search(vector<node>& map, int val) {
		int s = 0;
		int e = map.size() - 1;
		while (s <= e) {
			int mid = (s + e) / 2;
			if (map[mid].a > val) e = mid - 1;
			else if (map[mid].a < val) s = mid + 1;
			else return map[mid].b;
		}
		return NO_VALUE;
	}


	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		vector<int> t;
		int i, j, k;

		int n = nums.size();
		if (n == 0) return result;

		int m = 0;
		int* arr = new int[n];
		vector<node> map;
		sort(nums.begin(), nums.end());
		int zero_cnt = 0;
		for (i = 0; i < n; i++) {
			if (nums[i] == 0) zero_cnt++;
		}

		if (zero_cnt >= 3) { // 3중복
			t.push_back(0);
			t.push_back(0);
			t.push_back(0);
			result.push_back(t);
		}

		int* check = new int[n];
		arr[0] = nums[0]; map.push_back(node(nums[0], 0));
		check[0] = 1;
		for (i = 1; i < n; i++) {
			if (arr[m] == nums[i]) {
				if (map.back().a == nums[i]) map.back().b = m;
				check[m] = 0;
			}
			else {
				arr[++m] = nums[i]; map.push_back(node(nums[i], m));
				check[m] = 1;
			}
		}
		m++;

		// 2중복
		for (i = 0; i < m; i++) {
			if (check[i] == 0) { // 중복이 있다면, 
				k = search(map, -(arr[i] + arr[i]));
				if (arr[i] == 0) continue;
				if (NO_VALUE != k) {
					t.clear();
					t.push_back(arr[i]);
					t.push_back(arr[i]);
					t.push_back(arr[k]);
					result.push_back(t);
				}
			}
		}



		// 중복x
		for (i = 0; i < m; i++) {
			for (j = i + 1; j < m; j++) {
				k = search(map, -(arr[i] + arr[j]));
				if (NO_VALUE == k) continue;
				if (j < k) {
					t.clear();
					t.push_back(arr[i]);
					t.push_back(arr[j]);
					t.push_back(arr[k]);
					result.push_back(t);
				}
				else break;
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
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(-2);
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




