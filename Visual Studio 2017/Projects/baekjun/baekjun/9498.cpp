#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int score;
	fscanf(stdin, "%d", &score);
	if (90 <= score) fprintf(stdout, "A");
	else if (80 <= score) fprintf(stdout, "B");
	else if (70 <= score) fprintf(stdout, "C");
	else if (60 <= score) fprintf(stdout, "D");
	else {
		fprintf(stdout, "F");
	}
	return 0;
}
