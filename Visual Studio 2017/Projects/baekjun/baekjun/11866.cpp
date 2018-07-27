#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int data[1100];

int main(void) {
	int n, m;
	fscanf(stdin, "%d %d", &n, &m);
	for (int i = 1;i <= n;i++) {
		data[i] = i;
	}

	int p = 0;
	fprintf(stdout, "<");
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			p++;
			if (p == n+1) p = 1;
			if (data[p] == 0) {
				j--;
				continue;
			}
		}
		fprintf(stdout, "%d", data[p]);
		if (i == n) break;
		fprintf(stdout, ", ");
		data[p] = 0;
	}

	fprintf(stdout, ">");
	return 0;
}