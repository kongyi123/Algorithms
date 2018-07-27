// 순열 알고리즘 (사전순서)

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int num[10];
int n;

void r_rot(int s, int e) {
	int t = num[e];
	for (int i = e;i > s;i--) {
		num[i] = num[i - 1];
	}
	num[s] = t;
}

void l_rot(int s, int e) {
	int t = num[s];
	for (int i = s;i < e;i++) {
		num[i] = num[i + 1];
	}
	num[e] = t;
}

void permutation(int idx) {
	if (idx > n) {
		for (int i = 1;i <= n;i++) {
			fprintf(stdout, "%d ", num[i]);
		}
		fprintf(stdout, "\n");
	}
	else {
		for (int i = idx;i <= n;i++) {
			r_rot(idx, i);
			permutation(idx + 1);
			l_rot(idx, i);
		}
	}
}

int main(void) {
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) num[i] = i;
	permutation(1);
	return 0;
}