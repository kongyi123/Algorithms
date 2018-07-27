#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#include <string.h>

char str[110];
int check[100];

int main(void) {
	int n;
	int len;
	int cnt = 0;
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		fscanf(stdin, "%s", &str);
		len = strlen(str);

		char cur;
		int er = 0;
		cur = str[0];
		check[cur - 'a'] = 1;
		for (int j = 1;j < len;j++) {
			if (cur == str[j]) continue;

			cur = str[j];
			if (check[cur - 'a'] == 1) {
				er = 1;
				break;
			}
			else check[cur - 'a'] = 1;
		}

		if (er == 0) cnt++;


		memset(check, 0, sizeof(check));
		memset(str, 0, sizeof(str));
	}
	fprintf(stdout, "%d", cnt);
	return 0;
}