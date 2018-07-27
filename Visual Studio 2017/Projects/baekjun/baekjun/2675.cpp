#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


int main(void) {
	int t;
	int n;
	char str[100];
	fscanf(stdin, "%d", &t);
	for (int i = 1;i <= t;i++) {
		fscanf(stdin, "%d", &n);
		fscanf(stdin, "%s", &str);
		int len = strlen(str);
		for (int j = 0;j < len;j++) {
			for (int k = 1;k <= n;k++) {
				fprintf(stdout, "%c", str[j]);
			}
		}
		fprintf(stdout, "\n");
	}
	return 0;
}
