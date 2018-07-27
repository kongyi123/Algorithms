#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int tree[210000];
int pos[210000];
int n, m;

void update(int i, int val) {
	while (i <= n + m) {
		tree[i] += val;
		i += (i&-i);
	}
}

int sum(int i) {
	int ans = 0;
	while (i > 0) {
		ans += tree[i];
		i -= (i&-i);
	}
	return ans;
}


int main(void) {
	int t;
	fscanf(stdin, "%d", &t);
	for (int i = 1;i <= t;i++) {

		fscanf(stdin, "%d %d", &n, &m);
		for (int i = 1;i <= n + m;i++) tree[i] = 0;
		for (int i = m + 1;i < n + m + 1;i++) {
			update(i, 1);
			//tree[i] = 1;
			pos[i - m] = i;
		}

		for (int j = 1;j <= m;j++) {
			int data;
			fscanf(stdin, "%d", &data);
			fprintf(stdout, "%d ", sum(pos[data]-1));
			update(pos[data], -1);
			pos[data] = m - j + 1;
			update(pos[data], 1);
		}
		fprintf(stdout, "\n");
	}
	return 0;
}