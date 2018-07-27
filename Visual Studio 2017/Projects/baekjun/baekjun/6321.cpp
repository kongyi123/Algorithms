#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <memory.h>

char str[100];

int main(void) {
	int n;
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		fscanf(stdin, "%s", &str[1]);
		int len = strlen(&str[1]);
		fprintf(stdout, "String #%d\n", i);
		for (int j = 1;j <= len;j ++) {
			if (str[j] == 'Z') str[j] = 'A' - 1;
			fprintf(stdout, "%c", str[j] + 1);
		}
		fprintf(stdout, "\n\n");
		memset(str, 0, sizeof(str));
	}
	return 0;
}