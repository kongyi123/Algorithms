// 정렬하여 2중 for + map직접구현
// 중복이 3개 이상 있는 것은 skip
// map 직접 구현 (정렬 + 이분검색, 사실 map과는 약간 다름)
// + 코드 최적화를 약간 더함. 가지치기

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
#define INF 2000000000
#define DEBUG 2

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
		return INF;
	}



	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		int n = nums.size();
		if (n == 0) return result;
		int m = 0;
		vector<int> t;
		int* arr = new int[n];
		vector<node> map;
		sort(nums.begin(), nums.end());
		int same_count = 0;
		int i, j;
		arr[0] = nums[0]; map.push_back(node(nums[0], 0));
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

		int k;
		for (i = 0; i < m; i++) {
			if (i > 0 && arr[i] == arr[i - 1]) continue;
			for (j = i + 1; j < m; j++) {
				if (j > i + 1 && arr[j] == arr[j - 1]) continue;
				k = search(map, -(arr[i] + arr[j]));
				if (k == INF) continue;
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
