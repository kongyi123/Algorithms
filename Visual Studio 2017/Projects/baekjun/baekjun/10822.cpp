#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#define IN stdin

//FILE *in = fopen("input.txt", "r");

int len;

int main(void) {
	int sum = 0;
	int a;
	char ch;
	fscanf(IN, "%d", &sum);
	while (1) {
		ch = '-';
		fscanf(IN, "%c", &ch);
		if (feof(IN)) break;
		if (ch == '\n') break;
		if (ch != ',') break;

		fscanf(IN, "%d", &a);
		sum = sum + a;
	}
	fprintf(stdout, "%d", sum);
	return 0;
}