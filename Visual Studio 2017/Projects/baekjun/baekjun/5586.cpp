#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char str[10101];
int joi, ioi;

int main(void) {
	
	fscanf(stdin, "%s", &str[1]);
	int len = strlen(&str[1]);
	for (int i = 1;i <= len-2;i++) {
		if (str[i] == 'I' && str[i + 1] == 'O' && str[i + 2] == 'I') ioi++;
		if (str[i] == 'J' && str[i + 1] == 'O' && str[i + 2] == 'I') joi++;
	}

	fprintf(stdout, "%d\n%d\n", joi, ioi);
	return 0;
}