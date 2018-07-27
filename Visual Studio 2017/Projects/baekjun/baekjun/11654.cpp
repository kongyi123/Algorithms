#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	char ch;
	fscanf(stdin, "%c", &ch);
	fprintf(stdout, "%d", ch);
	return 0;
}