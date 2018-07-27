#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#include <string.h>

char str[100];

int main(void) {
	int n;
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		memset(str, 0, sizeof(str));
		fscanf(stdin, "%s", &str[1]);
		int len = strlen(&str[1]);
		if ((str[len] - '0') % 2 == 0) fprintf(stdout, "even\n");
		else fprintf(stdout, "odd\n");
	}
	return 0;
}