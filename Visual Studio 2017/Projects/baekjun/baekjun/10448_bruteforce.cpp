#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int s[210];
int check[1000];

int main(void) {
	for (int i = 1;i <= 50;i++) {
		s[i] = i + s[i - 1];
	}

	for (int i = 1;i <= 50;i++) {
		for (int j = 1;j <= 50;j++) {
			if (s[i] + s[j] > 1000) break;
			for (int k = 1;k <= 50;k++) {
				if (s[i] + s[j] + s[k] > 1000) break;
				check[s[i] + s[j] + s[k]] = 1;
			}
		}
	}

	int n;
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		int data;
		fscanf(stdin, "%d", &data);
		fprintf(stdout, "%d\n", check[data]);
	}
}