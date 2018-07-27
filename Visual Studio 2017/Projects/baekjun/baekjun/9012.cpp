#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#include <string.h>

char str[60];

int main(void) {
	int t;
	fscanf(stdin, "%d", &t);
	for (int i = 1;i <= t;i++) {
		fscanf(stdin, "%s", &str[1]);
		int len = strlen(&str[1]);
		int cnt = 0;
		int er = 0;
		for (int j = 1;j <= len;j++) {
			if (str[j] == '(') cnt++;
			else if (str[j] == ')') {
				cnt--;
				if (cnt < 0) {
					er = 1;
					break;
				}
			}
		}

		if (er == 0 && cnt == 0) fprintf(stdout, "YES\n");
		else fprintf(stdout, "NO\n");

	}

	return 0;
}