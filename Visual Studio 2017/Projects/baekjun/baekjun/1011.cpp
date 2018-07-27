#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define IN stdin
#define OUT stdout

//FILE *in = fopen("input.txt", "r");
//FILE *out = fopen("output.txt", "w");

int n;
unsigned int a, b;

int main(void) {
	fscanf(IN, "%d", &n);
	unsigned int temp;
	unsigned int cnt;
	for (unsigned int i = 1;i <= n;i ++) {
		fscanf(IN, "%d%d", &a, &b);
		cnt = 0;
		for (unsigned int j = 1;;j++) {
			if (j*j <= b - a && b - a < (j + 1) * (j + 1)) {
				temp = (b - a) - (j*j);
				cnt = cnt + (j - 1) * 2 + 1;
				cnt = cnt + (temp / j);
				if (temp %j > 0) cnt = cnt + 1;
				break;
			}
		}

		fprintf(OUT, "%d\n", cnt);
	}

	return 0;
}