#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int check[2000];

int main(void) {
	int t;
	check[1] = check[0] = 1;
	for (int i = 2;i <= 1100;i++) {
		for (int j = i * 2;j <= 1100;j += i) {
			check[j] = 1;
		}
	}

	fscanf(stdin, "%d", &t);
	for (int i = 1;i <= t;i++) {
		int n;
		fscanf(stdin, "%d", &n);
		int flag = 0;
		for (int a = 1;a <= n;a++) {
			if (check[a]) continue;
			for (int b = a;b <= n;b++) {
				if (check[b]) continue;
				int c = n - (a + b);
				if (c < 0) break;
				if (check[c]) continue;
				flag = 1; 
				fprintf(stdout, "%d %d %d\n", a, b, c);
				a = b = n;
				break;
			}
		}
		if (flag == 0) fprintf(stdout, "0\n");
	}
	return 0;
}