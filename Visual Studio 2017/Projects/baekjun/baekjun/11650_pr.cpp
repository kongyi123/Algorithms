// 11Ка

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct node {
	int x;
	int y;
};


node data[110000];

void swap(node &a, node &b) {
	node t = a;
	a = b;
	b = t;
}

int compare(node &a, node &b) {
	if (a.x != b.x) return a.x - b.x;
	return a.y - b.y;
}

int main(void) {
	int n;
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		int a, b;
		fscanf(stdin, "%d %d", &a, &b);
		data[i].x = a;
		data[i].y = b;
		for (int j = i;j > 1;j = j / 2) {
			if (compare(data[j], data[j / 2]) > 0) swap(data[j], data[j / 2]);
		}
	}

	for (int i = 1;i <= n;i++) {
		swap(data[1], data[n - i + 1]);
		for (int j = 1;;) {
			int k = j * 2;
			if (k > n - i) break;
			if (k + 1 <= n - i && compare(data[k], data[k + 1]) < 0) k++;
			if (compare(data[j], data[k]) < 0) {
				swap(data[j], data[k]);
				j = k;
			}
			else break;
		}
	}

	for (int i = 1;i <= n; i++) {
		fprintf(stdout, "%d %d\n", data[i].x, data[i].y);
	}
	return 0;
}