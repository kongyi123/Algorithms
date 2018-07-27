#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define IN stdin
#define OUT stdout

//FILE *in = fopen("input.txt", "r");
//FILE *out = fopen("output.txt", "w");

int main(void) {
	int n, m;
	fscanf(IN, "%d %d", &n, &m);
	fprintf(OUT, "%d", n*m);
}