#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char str[105];
int n;

int main(void) {
	fscanf(stdin, "%d", &n);
	fscanf(stdin, "%s", &str);
	int sum = 0;
	for (int i = 0;i < n;i++) {
		sum = sum + str[i] - '0';
	}

	fprintf(stdout, "%d", sum);
	return 0;
}