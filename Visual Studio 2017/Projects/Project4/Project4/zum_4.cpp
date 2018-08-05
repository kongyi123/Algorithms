#include <stdio.h>
#include <vector>
#define MAX 100000

using namespace std;

int cnt;
int table[MAX];
int check[MAX];

void back(const vector<int>&A, int s, int e) {
	if (s > e) return;
	if (s == e) {
		if (A[s] == s+1) table[s] = ++cnt;
		return;
	}
	
	int mid = (s + e) / 2;

	back(A, s, mid);
	back(A, mid+1, e);
	
	int min = MAX;
	int max = -MAX;
	int count = 0;
	for (int i = s;i <= e;i++) check[i] = 0;
	for (int i = s;i <= e;i++) {
		if (table[i] == 0) {
			if (min > i) min = i;
			if (max < i) max = i;
			check[i] = 1;
			count++;
		}
	}

	cnt++;
	for (int i = min;i <= max;i++) {
		table[i] = cnt;
	}

}

int main(void) {
	vector<int> A;
	A.push_back(2);
	A.push_back(3);
	A.push_back(1);
	A.push_back(5);
	A.push_back(4);
	A.push_back(7);
	A.push_back(6);
	back(A, 0, 6);
	return 0;
}