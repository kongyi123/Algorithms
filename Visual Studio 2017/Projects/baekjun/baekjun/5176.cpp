#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int check[600];

int main(void) {
	int t;
	fscanf(stdin, "%d", &t);
	for (int i = 1;i <= t;i++) {
		int p, m;
		fscanf(stdin, "%d %d", &p, &m);
		int cnt = 0;
		for (int j = 1;j <= p;j++) {
			int a;
			fscanf(stdin, "%d", &a);
			if (check[a] != i) {
				check[a] = i;
			}
			else cnt++;
		}

		fprintf(stdout, "%d\n", cnt);
	}
	return 0;
}
