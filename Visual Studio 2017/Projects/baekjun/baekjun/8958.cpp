#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#include <string.h>

int main(void) {
	int t;
	char str[100];
	int count;
	fscanf(stdin, "%d", &t);
	for (int i = 1;i <= t;i++) {
		fscanf(stdin, "%s", &str);
		int len = strlen(str);
		int cnt = 0;
		count = 0;
		for (int j = 0;j < len;j++) {
			if (str[j] == 'O') {
				cnt++;
				count += cnt;
			}
			else cnt = 0;
		}

		fprintf(stdout, "%d\n", count);
		memset(str, 0, sizeof(str));
	}
	return 0;
}