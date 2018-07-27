#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	while (!feof(stdin)) {
		int val;
		fscanf(stdin, "%d", &val);
		if (val == 42) break;
		fprintf(stdout, "%d\n", val);
	}
	return 0;

}


