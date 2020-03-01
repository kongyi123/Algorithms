// 정렬 구현도 정말 느리구나 내가..

#define _CRT_SECURE_NO_WARNING
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

class Node {
public:
	int arr[30] = { 0, };
	bool operator>(const Node t) {
		for (int i = 1; i < 30; i++) {
			if (arr[i] > t.arr[i]) return 1;
			else if (arr[i] < t.arr[i]) return 0;
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

		int i = s, j = mid+1, count = 0;
		while (i <= mid && j <= e) {
			if (rank[i] > rank[j]) buf[count++] = rank[i++];
			else buf[count++] = rank[j++];
		}

		while (i <= mid) buf[count++] = rank[i++];
		while (j <= e) buf[count++] = rank[j++];

		for (int i = s; i <= e; i++) rank[i] = buf[i - s];
	}
	else return;
}

class Solution {
public:
	Node rank[30];
	string rankTeams(vector<string>& votes) {
		for (int i = 0; i < votes.size(); i++) {
			for (int j = 0; j < votes[i].size(); j++) {
				rank[votes[i][j] - 'A'].arr[0] = votes[i][j] - 'A' + 1;
				rank[votes[i][j] - 'A'].arr[j+1] ++;
			}
		}
		msort(rank, 0, 27);

		string result;
		for (int i = 0; i < 30; i++) {
			if (rank[i].arr[0]) result += (rank[i].arr[0] + 'A' - 1);
		}

		cout << result;
		return result;
	}
};

int main(void) {
	Solution sol;
	vector<string> nums;
	nums.push_back("M");
	nums.push_back("M");
	nums.push_back("M");
	nums.push_back("M");

	//nums.push_back("BCA");
	//nums.push_back("CAB");
	//nums.push_back("CBA");
	//nums.push_back("ABC");
	//nums.push_back("ACB");
	//nums.push_back("BAC");
	//	nums.push_back("XYZW");


	//nums.push_back("ABC");
	//nums.push_back("ACB");
	//nums.push_back("ABC");
	//nums.push_back("ACB");
	//nums.push_back("ACB");
	sol.rankTeams(nums);

	return 0;
}