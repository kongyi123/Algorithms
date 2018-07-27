#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int check[1001];
int main(void) {
	int n;
	int cnt = 0;
	int data;
	fscanf(stdin, "%d", &n);
	check[1] = 1;
	for (int i = 2;i <= 1000;i++) {
		for (int j = 2;j <= 1000 / i;j++) {
			check[j * i] = 1;
		}
	}


	for (int i = 1;i <= n;i++) {
		fscanf(stdin, "%d", &data);
		if (check[data] == 0) cnt++;
	}


	fprintf(stdout, "%d", cnt);
	return 0;
}