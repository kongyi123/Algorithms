#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char a[40];
char b[40];
char dap[80], dcnt;

int main(void) {
	fscanf(stdin, "%s%s", &a[1], &b[1]);
	int lena = strlen(&a[1]);
	int lenb = strlen(&b[1]);
	long long a10 = 0, b10 = 0;
	long long t = 1;
	for (int i = lena;i >= 1;i--) {
		a10 = a10 + (a[i] - '0')*t;
		t = t * 2;
	}
	t = 1;
	for (int i = lenb;i >= 1;i--) {
		b10 = b10 + (b[i] - '0')*t;
		t = t * 2;
	}

	t = a10*b10;
	while (t) {
		dcnt++;
		dap[dcnt] = t % 2;
		t = t >> 1;
	}

	for (int i = dcnt;i >= 1;i--) {
		fprintf(stdout, "%d", dap[i]);
	}

	return 0;
}