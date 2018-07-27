#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <memory.h>

char str[1100];

int main(void) {
	int n;
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		fscanf(stdin, "%s", &str[1]);
		int len = strlen(&str[1]);
		if (str[len / 2] == str[len / 2 + 1]) fprintf(stdout, "Do-it\n");
		else fprintf(stdout, "Do-it-Not\n");
		memset(str, 0, sizeof(str));
	}
	return 0;
}