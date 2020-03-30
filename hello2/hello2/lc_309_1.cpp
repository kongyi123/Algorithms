/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Best Time to Buy and Sell Stock with Cooldown.
Memory Usage: 6.4 MB, less than 100.00% of C++ online submissions for Best Time to Buy and Sell Stock with Cooldown.

added else break;

*/
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
	int* dy;
	int temp;
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		if (n == 0) return 0;
		dy = new int[n];

		for (int i = 0; i < n; i++) {
			dy[i] = 0;
			for (int j = i - 1; j >= 0; j--) {
				if (prices[i] > prices[j]) {
					if (j - 2 >= 0 && dy[j - 2] > 0) temp = dy[j - 2];
					else temp = 0;
					if (dy[i] < temp + prices[i] - prices[j]) {
						dy[i] = temp + prices[i] - prices[j];
					}
				}
				else break;
			}
			if (i > 0 && dy[i] < dy[i - 1]) dy[i] = dy[i - 1];
		}


		return dy[n - 1];
	}
};

int main(void) {
	Solution sol;
	vector<int> prices;
	//prices.push_back(1);
	//prices.push_back(2);
	//prices.push_back(3);
	//prices.push_back(0);
	//prices.push_back(2);
	prices.push_back(1);
	prices.push_back(6);
	prices.push_back(7);
	prices.push_back(4);
	prices.push_back(5);
	prices.push_back(8);
	prices.push_back(9);
	prices.push_back(2);

	printf("%d\n", sol.maxProfit(prices));
	return 0;
}



