// 숫자 기수 정렬 O(N)
// 코드 최적화 x
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>

using namespace std;

int max(int a, int b) {
	if (a > b) return a;
	return b;
}

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		int N = nums.size();
		if (N == 0) return 0;
		queue<long long> radix[10]; // 자리수에 대한 큐 배열
		long long * arr = new long long[N+1];
		for (int i = 0; i < N; i++) arr[i] = (long long)nums[i] + 2200000000L;
		long long d = 1000000000;
		long long dMin = 1;

		while (dMin <= d) {
			for (int i = 0; i < N; i++) radix[(arr[i] % (dMin * 10)) / dMin].push(arr[i]);
			int j = 0;
			for (int i = 0; i <= 9; i++) {
				while (radix[i].size() > 0) {
					arr[j++] = radix[i].front();
					radix[i].pop(); // pop front
				}
			}
			dMin *= 10;
		}

		int cnt = 1;
		int maxVal = 1;
		long long last = arr[0];
		for (int i = 1; i < N; i++) {
			if (last + 1 == arr[i]) {
				last++;
				cnt++;
				maxVal = max(maxVal, cnt);
			}
			else if (last != arr[i]) {
				last = arr[i];
				cnt = 1;
			}
		}
		return maxVal;
	}
};



int main(void) {
	vector<int> nums;

	nums.push_back(1);
/*	nums.push_back(1);
	nums.push_back(4);
	nums.push_back(7);
	nums.push_back(3);
	nums.push_back(-1);
	nums.push_back(0);
	nums.push_back(5);
	nums.push_back(8);
	nums.push_back(-1);
	nums.push_back(6);
*/
	Solution sol;
	int result = sol.longestConsecutive(nums);
	printf("max length = %d", result);

	return 0;
}