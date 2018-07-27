#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <memory.h>

char str[100];

int main(void) {
	while (1) {
		fscanf(stdin, "%s", &str[1]);
		if (str[1] == '#') break;
		int len = strlen(&str[1]);
		int cnt = 0;
		for (int i = 1;i < len;i++) {
			if (str[i] == '1') cnt++;
		}
		char ch = str[len];
		str[len] = 0;

		if (ch == 'o' && cnt % 2 == 1) fprintf(stdout, "%s0\n", &str[1]);
		else if (ch == 'o' && cnt % 2 == 0) fprintf(stdout, "%s1\n", &str[1]);
		else if (ch == 'e' && cnt % 2 == 1) fprintf(stdout, "%s1\n", &str[1]);
		else if (ch == 'e' && cnt % 2 == 0) fprintf(stdout, "%s0\n", &str[1]);

	}
	return 0;
}