#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int dy[5100];
int n;

int main(void) {
	dy[0] = 1;
	fscanf(stdin, "%d", &n);
	for (int i = 0;i <= n;i++) {
		if (dy[i] > 0) {
			if (dy[i+3] == 0 || dy[i + 3] > dy[i] + 1) dy[i + 3] = dy[i] + 1;
			if (dy[i + 5] == 0 || dy[i + 5] > dy[i] + 1) dy[i + 5] = dy[i] + 1;
		}
	}

	fprintf(stdout, "%d", dy[n]-1);
	return 0;
}