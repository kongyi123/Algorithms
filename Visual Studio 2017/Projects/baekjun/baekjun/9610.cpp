#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void) {
	int n;
	fscanf(stdin, "%d", &n);
	int q1, q2, q3, q4, axis;
	q1 = q2 = q3 = q4 = axis = 0;

	for (int i = 1;i <= n;i++) {
		int x, y;
		fscanf(stdin, "%d %d", &x, &y);
		if (x > 0 && y > 0) q1++;
		else if (x < 0 && y < 0) q3++;
		else if (x < 0 && y > 0) q2++;
		else if (x > 0 && y < 0) q4++;
		else axis++;
	}

	fprintf(stdout, "Q1: %d\n", q1);
	fprintf(stdout, "Q2: %d\n", q2);
	fprintf(stdout, "Q3: %d\n", q3);
	fprintf(stdout, "Q4: %d\n", q4);
	fprintf(stdout, "AXIS: %d\n", axis);
	return 0;

}