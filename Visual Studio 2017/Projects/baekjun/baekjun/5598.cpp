#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

char str[2000];

int main(void) {
	fscanf(stdin, "%s", &str[1]);
	int len = strlen(&str[1]);
	for (int i = 1;i <= len;i++) {
		if (str[i] >= 'D' && str[i] <= 'Z') {
			fprintf(stdout, "%c", str[i] - 3);
		}
		else fprintf(stdout, "%c", str[i] - 'A' + 'X');
	}
	return 0;
}