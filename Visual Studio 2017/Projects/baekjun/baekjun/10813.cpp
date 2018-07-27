#include <stdio.h>

int num[110];

void swap(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
}

int main(void) {
	int n, m;
	int a, b;
	fscanf(stdin, "%d %d", &n, &m);
	for (int i = 1;i <= n;i ++) num[i] = i;
	for (int i = 1;i <= m;i ++) {
		fscanf(stdin, "%d %d", &a, &b);
		swap(num[a], num[b]);
	}

	for (int i = 1;i <= n;i ++) {
		fprintf(stdout, "%d ", num[i]);
	}
	return 0;
}