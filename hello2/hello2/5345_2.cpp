// 1366. Rank Teams by Votes

// my code revise
// 뭐가 잘못됐길래 서버와 로컬이 다르게 나오는지 모르겠다. 분명히 메모리 관련된 것일텐데...
// 다시보기
#include <string>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int f[30][30] = { 0, };

class Node {
public:
	char ch = 0;
	bool operator>(const Node t) {
		for (int i = 0; i < 27; i++) {
			int idx = ch - 'A', idx2 = t.ch - 'A';
			if (f[idx][i] > f[idx2][i]) return 1;
			else if (f[idx][i] < f[idx2][i]) return 0;
		}
		return 1;
	}
};

Node buf[30];
void msort(Node rank[], int s, int e) {
	if (s < e) {
		int mid = (s + e) / 2;
		msort(rank, s, mid);
		msort(rank, mid + 1, e);

		int i = s, j = mid + 1, count = s;
		while (i <= mid && j <= e) {
			if (rank[i] > rank[j]) buf[count++] = rank[i++];
			else buf[count++] = rank[j++];
		}

		while (i <= mid) buf[count++] = rank[i++];
		while (j <= e) buf[count++] = rank[j++];

		for (int i = s; i <= e; i++) rank[i] = buf[i];
	}
	else return;
}

class Solution {
public:
	int n = 0;
	Node rank[30];
	bool check[100] = { 0, };
	string rankTeams(vector<string>& votes) {
		for (int i = 0; i < votes.size(); i++) {
			for (int j = 0; j < votes[i].size(); j++) {
				if (!check[votes[i][j]]) {
					check[votes[i][j]] = 1;
					rank[n++].ch = votes[i][j];
				}

				f[votes[i][j] - 'A'][j] ++;
			}	
		}
		msort(rank, 0, n-1);

		string result;
		for (int i = 0; i < n; i++) {
			result += (rank[i].ch);
		}

		cout << result;
		return result;
	}
};


int main(void) {
	Solution sol;
	vector<string> nums;


	nums.push_back("ZMNAGUEDSJYLBOPHRQICWFXTVK");
	


	/*nums.push_back("ABC");
	nums.push_back("ACB");
	nums.push_back("ABC");
	nums.push_back("ACB");
	nums.push_back("ACB");
	*/
	sol.rankTeams(nums);

	return 0;
}