#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include <string.h>
#include <memory.h>

char str[1100000];

int main(void) {
	int t;
	int a, b;
	fscanf(stdin, "%d", &t);
	for (int i = 1;i <= t;i++) {
		fscanf(stdin, "%d %d", &a, &b);
		fscanf(stdin, "%s", &str[1]);
		int len = strlen(&str[1]);
		for (int j = 1;j <= len;j++) {
			fprintf(stdout, "%c", ((str[j] - 'A')*a + b) % 26 + 'A');
		}
		fprintf(stdout, "\n");
		memset(str, 0, sizeof(str));
	}

	return 0;
}