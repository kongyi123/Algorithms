// 49Ка

#define _CRT_SECURE_NO_WARNINGS
#define MAX 462144

#include <stdio.h>


int n, m;
int k;
int tree[MAX];
int ind[MAX];
/*
int sum(int a, int b) {
	int x = a + k - 1;
	int y = b + k - 1;
	int tmp = 0;
	while (x <= y) {
		if (x % 2 == 1) tmp += tree[x++];
		if (y % 2 == 0) tmp += tree[y--];
		x = x / 2;
		y = y / 2;
	}
	return tmp;
}
*/

int sum(int a) {
	int x = a + k - 1;
	int tmp = 0;
	while (x > 0) {
		if (x % 2 == 0) tmp += tree[x--];
		x = x / 2;
	}
	return tmp;
}

void update(int i, int val) {
	tree[k + i - 1] += val;
	int tmp = (i + k - 1)/2;
	while (tmp > 0) {
		tree[tmp] = tree[tmp * 2] + tree[tmp * 2 + 1];
		tmp = tmp / 2;
	}
}

int main(void) {
	int t;
	fscanf(stdin, "%d", &t);
	for (int i = 1;i <= t;i++) {
		fscanf(stdin, "%d %d", &n, &m);
		for (int j = 1;j < MAX;j++) tree[j] = 0;
		
		for (k = 1;k < n + m;k *= 2);
		for (int j = k + m;j < k + m + n;j++) {
			//tree[j] = 1;
			update(j - k + 1, 1);
			ind[j - k - m + 1] = j - k + 1;
		}

		//for (int j = k + m - 1;j >= 1;j--) tree[j] = tree[j * 2] + tree[j * 2 + 1];

		for (int j = 1;j <= m;j++) {
			int a;
			fscanf(stdin, "%d", &a);
			fprintf(stdout, "%d ", sum(ind[a]-1));
			update(ind[a], -1);
			ind[a] = m - j + 1;
			update(ind[a], 1);
		}
		
	}

	return 0; 
}
