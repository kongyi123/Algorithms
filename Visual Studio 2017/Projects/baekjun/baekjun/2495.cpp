#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

char str[20];

int main(void) {
	for (int i = 1;i <= 3;i++) {
		fscanf(stdin, "%s", &str[1]);
		int cnt = 1;
		int max = -1;
		for (int j = 2;j <= 8;j++) {
			if (str[j] == str[j - 1]) {
				cnt++;
			}
			else cnt = 1;
			if (max < cnt) max = cnt;
		}
		fprintf(stdout, "%d\n", max);
	}
	return 0;
}