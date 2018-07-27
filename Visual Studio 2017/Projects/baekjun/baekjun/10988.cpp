#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

char str[200];

int main(void) {
	fscanf(stdin, "%s", &str[1]);
	int len = strlen(&str[1]);
	int er = 0;
	for (int i = 1;i <=len;i++) {
		if (str[i] != str[len - i + 1]) er = 1;
	}

	fprintf(stdout, "%d", 1 - er);
	return 0;
}