#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int check[110];

int main(void) {
	int a;
	int n;
	int cnt = 0;
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		fscanf(stdin, "%d", &a);
		if (check[a] == 0) {
			check[a] = 1;
		}
		else {
			cnt++;
		}
		

	}

	fprintf(stdout, "%d", cnt);
	return 0;
}