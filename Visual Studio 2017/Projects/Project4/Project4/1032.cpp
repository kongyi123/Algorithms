#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#define in stdin
#define out stdout

//FILE *in = fopen("input.txt", "r");
//FILE *out = fopen("output.txt", "w");

int n;
char str[100];
char o[100];

int main(void) {
	fscanf(in, "%d", &n);
	for (int i = 1;i <= n;i++) {
		fscanf(in, "%s", str);
		for (int j = 0;j < strlen(str);j++) {
			if (o[j] == 0) o[j] = str[j];
			else if (o[j] != str[j]) {
				o[j] = '?';
			}
		}
	}

	fprintf(out, "%s", o);
	return 0;
}