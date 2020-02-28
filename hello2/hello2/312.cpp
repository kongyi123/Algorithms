#include <stdio.h>
#include <vector>

using namespace std;

int max(int a, int b) {
	if (a < b) return b;
	return a;
}

class Solution {
public:
	int dy[502][502] = { 0, };
	int data[502] = { 0, };
	int maxCoins(vector<int>& nums) {
		int n = nums.size();
		data[0] = data[n + 1] = 1;
		for (int i = 1;i <= n; i++) data[i] = nums[i - 1];
		for (int i = 1; i <= n; i++) dy[i][i] = data[i - 1] * data[i] * data[i + 1];
		for (int k = 1; k <= n - 1; k++) { // 간격
			for (int s = 1; s + k <= n; s++) { // 범위의 start
				int e = s + k;
				int maxVal = 0;
				for (int j = s; j <= e; j++) {
					maxVal = max(maxVal, data[j] * data[s - 1] * data[e + 1] + dy[j + 1][e] + dy[s][j - 1]);
				}
				dy[s][e] = maxVal;
			}
		}


		return dy[1][n];
	}
};

int main(void) {
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(1);
	nums.push_back(5);
	nums.push_back(8);


	Solution sol;
	int result = sol.maxCoins(nums);
	printf("%d", result);
	return 0;
}


