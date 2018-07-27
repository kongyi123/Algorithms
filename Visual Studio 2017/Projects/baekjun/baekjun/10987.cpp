#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char str[102];

int main(void) {
	int len;
	int cnt = 0;
	fscanf(stdin, "%s", &str);
	len = strlen(str);
	for (int i = 0;i < len;i++) {
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') cnt++;
	}

	fprintf(stdout, "%d", cnt);
	return 0;
}