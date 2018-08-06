#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define M 10000000

bool check[M + 1];

int main(void) {
	int n;
	fscanf(stdin, "%d", &n);
	for (int i = 2;i <= M;i++) {
		for (int j = i + i;j <= M;j += i) {
			check[j] = true;
		}
	}

	int cnt = 0;
	for (int i = 2;i <= M;i++) {
		if (check[i] == false) {
			cnt++;
			if (cnt == n) {
				fprintf(stdout, "%d", i);
				break;
			}
		}
	}

	return 0;
}