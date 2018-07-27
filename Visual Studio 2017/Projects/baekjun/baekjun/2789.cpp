#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char str[110];

int main(void) {
	fscanf(stdin, "%s", &str);
	int len = strlen(str);
	for (int i = 0;i < len;i++) {
		if (str[i] == 'C' || str[i] == 'A' || str[i] == 'M' || str[i] == 'B' || str[i] == 'R' || str[i] == 'I' || str[i] == 'D' || str[i] == 'G' || str[i] == 'E') continue;
		fprintf(stdout, "%c", str[i]);
	}
	return 0;
}