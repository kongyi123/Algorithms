// (자료구조) 순열 알고르즘 (단, 사전순 아님)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int maxV = 0;
int input[10];

int abs(int a) {
	if (a < 0) return -a;
	return a;
}

void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}

int getValue(int* list, int n) {
	int ans = 0;
	for (int i = 1; i<n; i++) {
		ans += abs(list[i] - list[i - 1]);
	}
	return ans;
}

void permutation(int* list, int k, int m) {
	if (k > m) {
		int a = getValue(list, k);
		maxV = maxV >a ? maxV : a;
	}
	else {
		for (int i = k; i <= m; i++) {
			swap(list[k], list[i]);
			permutation(list, k + 1, m);
			swap(list[k], list[i]);
		}
	}
}

int main() {
	int n; 
	fscanf(stdin, "%d", &n);
	int list[10] = { 0, };
	for (int i = 0; i<n; i++) {
		fscanf(stdin, "%d", &input[i]);
	}
	permutation(input, 0, n - 1);
	fprintf(stdout, "%d", maxV);
}