#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int data[110000];
int cnt;

int main(void) {
	int n;
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		int input;
		fscanf(stdin, "%d", &input);
		if (input != 0) {
			data[++cnt] = input;
		}
		else if (cnt > 0) {
			cnt--;
		}
	}
	long long sum = 0;
	for (int i = 1;i <= cnt;i++) {
		sum += data[i];
	}

	fprintf(stdout, "%lld", sum);
	return 0;
}