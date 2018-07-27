#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int data[20000];

int main(void) {
	int n, m;
	fscanf(stdin, "%d %d", &n, &m);
	for (int i = 1;i <= n;i++) {
		fscanf(stdin, "%d", &data[i]);
		data[i] = data[i] + data[i - 1];
	}

	int cnt = 0;
	for (int i = 1;i <= n;i++) {
		for (int j = i;j <= n;j++) {
			if (m == data[j] - data[i - 1]) {
				cnt++;
				break;
			}
		}
	}

	fprintf(stdout, "%d", cnt);

	
	return 0;
}