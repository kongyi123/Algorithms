#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100000

int check[1000010];

int main(void) {
	int n;
	int max = -1;
	int t;
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		fscanf(stdin, "%d", &t);
		check[t] = check[t - 1] + 1;
		if (max < check[t])
			max = check[t];
	}

	fprintf(stdout, "%d", max);
	return 0;
}
