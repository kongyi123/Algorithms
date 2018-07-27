#include <stdio.h>

int check[10];

int main(void) {
	int t;
	fscanf(stdin, "%d", &t);
	for (int i = 1;i <= t;i ++) {
		int x;
		fscanf(stdin, "%d", &x);
		while (x) {
			check[x % 10] = i;
			x = x / 10;
		}

		int cnt = 0;
		for (int j = 0;j <= 9;j ++) {
			if (check[j] == i) cnt ++;
		}

		fprintf(stdout, "%d\n", cnt);
	}
	return 0;
}