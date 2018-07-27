#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define IN stdin
#define OUT stdout

//FILE *in = fopen("input.txt", "r");
//FILE *out = fopen("output.txt", "w");

int a, b, c;

int main(void) {
	fscanf(IN, "%d%d%d", &a, &b, &c);
	fprintf(OUT, "%d\n%d\n%d\n%d\n", (a + b) % c, (a%c + b%c) % c, (a*b) % c, ((a%c)*(b%c)) % c);
	return 0;
}