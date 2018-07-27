#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	int t;
	int data;
	fscanf(stdin, "%d", &t);
	for (int i = 1;i <= t;i++) {
		fscanf(stdin, "%d", &data);
		int cnt = 0;
		while (data) {
			if (data % 2 == 1) fprintf(stdout, "%d ", cnt);
			data = data >> 1;
			cnt++;
		}
		fprintf(stdout, "\n");
	}
	return 0;
}