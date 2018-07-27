#include <stdio.h>

int fi[40];

int main(void) {
	int n, m;
	fscanf(stdin, "%d %d", &n, &m);
	fi[1] = 0; fi[2] = 1;
	for (int i = 3;i <= n;i ++) {
		fi[i] = fi[i-1] + fi[i-2];
	}

	for (int i = 1;i <= 100000;i ++) {
		int t = (m - (i*fi[n-1]));
		if (t % fi[n] == 0) {
			fprintf(stdout, "%d\n%d", i, t/fi[n]);
			break;
		}
	}
	return 0;
}