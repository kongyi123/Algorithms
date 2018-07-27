#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int cnt[2002];

int main(void) {
	int n;
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		int data;
		fscanf(stdin, "%d", &data);
		cnt[data+1000] = 1;
	}

	for (int i = 0;i <= 2000;i++) {
		if (cnt[i] > 0) {
			fprintf(stdout, "%d ", i-1000);
		}
	}
	return 0;
}