#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n;
int main(void) {
	fscanf(stdin, "%d", &n);
	for (int i = n;i >= 1;i--) {
		fprintf(stdout, "%d\n", i);
	}
	return 0;
}