#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define IN stdin
#define OUT stdout

//FILE *in = fopen("input.txt", "r");
//FILE *out = fopen("output.txt", "w");

char str[105];

int main(void) {
	fscanf(IN, "%s", &str);
	int len = strlen(str);
	for (int i = 0;i < len;i++) {
		fprintf(OUT, "%c", str[i]);
		if (i % 10 == 9) fprintf(OUT, "\n");
	}
}