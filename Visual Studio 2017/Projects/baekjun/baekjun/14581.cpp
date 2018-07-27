#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

char str[100];

int main(void) {
	fscanf(stdin, "%s", &str[1]);
	fprintf(stdout, ":fan::fan::fan:\n");
	fprintf(stdout, ":fan::%s::fan:\n", &str[1]);
	fprintf(stdout, ":fan::fan::fan:\n");
	return 0;
}