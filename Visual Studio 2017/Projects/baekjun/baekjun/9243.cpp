#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char str1[1100];
char str2[1100];
int n;

int main(void) {
	fscanf(stdin, "%d", &n);
	fscanf(stdin, "%s", &str1[1]);
	int len = strlen(&str1[1]);
	fscanf(stdin, "%s", &str2[1]);

	int flag = 0;
	if (n % 2 == 1) {
		for (int i = 1;i <= len;i++) {
			if (str1[i] == '0' && str2[i] == '0') { flag = 1; break; }
			if (str1[i] == '1' && str2[i] == '1') { flag = 1; break; }
		}
	}
	else {
		for (int i = 1;i <= len;i++) {
			if (str1[i] == '0' && str2[i] == '1') { flag = 1; break; }
			if (str1[i] == '1' && str2[i] == '0') { flag = 1; break; }
		}
	}

	if (flag == 0) fprintf(stdout, "Deletion succeeded");
	else fprintf(stdout, "Deletion failed");
	return 0;
}