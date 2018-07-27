#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void) {
	int t;
	fscanf(stdin, "%d", &t);
	for (int i = 1;i <= t;i++) {
		int s = 0;
		int n;
		int p, q;
		fscanf(stdin, "%d%d", &s,&n);
		for (int j = 1;j <= n;j++) {
			fscanf(stdin, "%d%d", &p, &q);
			s = s + (p*q);
		}

		fprintf(stdout, "%d\n", s);


	}
	return 0;
}