#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int n;
char data[110][110];

int main(void) {
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		fscanf(stdin, "%s", &data[i][1]);
	}
	int type;
	fscanf(stdin, "%d", &type);

	if (type == 1) {
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= n;j++) {
				fprintf(stdout, "%c", data[i][j]);
			}
			fprintf(stdout, "\n");
		}
	}
	else if (type == 2) {
		for (int i = 1;i <= n;i++) {
			for (int j = n;j >= 1;j--) {
				fprintf(stdout, "%c", data[i][j]);
			}
			fprintf(stdout, "\n");
		}
	}
	else if (type == 3) {
		for (int i = n;i >= 1;i--) {
			for (int j = 1;j <= n;j++) {
				fprintf(stdout, "%c", data[i][j]);
			}
			fprintf(stdout, "\n");
		}
	}

	return 0;
}