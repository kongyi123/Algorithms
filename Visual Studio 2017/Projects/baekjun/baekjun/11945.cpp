#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

char data[20];
char buf[20];

int main(void) {
	int n, m;
	fscanf(stdin, "%d %d", &n, &m);
	for (int i = 1;i <= n;i++) {
		fgets(buf, 20, stdin);
		for (int j = 1;j <= m;j++) {
			fscanf(stdin, "%c", &data[j]);
		}

		for (int j = m;j >= 1;j--) {
			fprintf(stdout, "%c", data[j]);
		}
		fprintf(stdout, "\n");
	}

	return 0;
}