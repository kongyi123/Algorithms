#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n;
	fscanf(stdin, "%d", &n);
	for (int i = n;i >= 1;i--) {
		for (int j = 1;j <= i;j++) {
			fprintf(stdout, "*");
		}
		fprintf(stdout, "\n");
	}
}