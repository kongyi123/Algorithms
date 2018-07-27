#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

bool check[500];
char str[500];

int main(void) {
	fgets(&str[1], 200, stdin);
	int len = strlen(&str[1]);
	for (int i = 1;i <= len;i++) {
		if (str[i] == 'p' && str[i - 1] == str[i + 1]) {
			if (check[i - 1] == 1) continue;
			if (str[i-1] == 'a' || str[i-1] == 'e' || str[i-1] == 'i' || str[i-1] == 'o' || str[i-1] == 'u') check[i] = check[i + 1] = 1;
		}
	}

	for (int i = 1;i <= len;i++) {
		if (check[i] == 0) fprintf(stdout, "%c", str[i]);
	}

	return 0;
}