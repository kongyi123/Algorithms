#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

char str[100000];

int main(void) {
	int n;
	fscanf(stdin, "%s %d", &str[1], &n);
	int len = strlen(&str[1]);
	int t = 1;
	int sum = 0;
	for (int i = len;i >= 1;i--) {
		if (str[i] >= '0' && str[i] <= '9') {
			sum = sum + (str[i] - '0')*t;
		}
		else sum = sum + (str[i] - 'A' + 10)*t;
		t = t * n;
	}

	fprintf(stdout, "%d", sum);

	return 0;
}