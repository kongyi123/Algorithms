#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <memory.h>
#include <string.h>

char str[1100000];

int main(void) {
	while (1) {
		fgets(&str[1], 1000000, stdin);
		if (str[1] == 'E' && str[2] == 'N' && str[3] == 'D') break;
		int len = strlen(&str[1]);
		
		for (int i = len-1;i >= 1;i--) {
			fprintf(stdout, "%c", str[i]);
		}
		fprintf(stdout, "\n");

		memset(str, 0, sizeof(str));
	}
	return 0;
}