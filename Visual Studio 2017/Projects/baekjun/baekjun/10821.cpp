#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char str[120];

int main(void) {
	fscanf(stdin, "%s", &str);
	int len = strlen(str);
	int cnt = 0;
	int is_num = 0;
	for (int i = 0;i < len;i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			if (is_num == 0) {
				cnt++;
				is_num = 1;
			}
		}
		else {
			is_num = 0;
		}
	}

	fprintf(stdout, "%d", cnt);

	return 0;
}