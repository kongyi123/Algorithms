#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int fidx[100];
char str[102];

int main(void) {
	fscanf(stdin, "%s", &str);
	int len = strlen(str);
	for (int i = 0;i < 100;i++) {
		fidx[i] = -1;
	}

	for (int i = 0;i < len;i++) {
		if (fidx[str[i]-'a'] == -1) fidx[str[i]-'a'] = i;
	}

	for (char i = 'a';i <= 'z';i++) {
		fprintf(stdout, "%d ", fidx[i - 'a']);
	}
	return 0;
}