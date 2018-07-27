#include <stdio.h>

int data[110];

int min(int a, int b) {
	if (a > b) return b;
	return a;
}

int main(void) {
	int n;
	int f;
	fscanf(stdin, "%d", &n);
	fscanf(stdin, "%d", &f);
	for (int i = 1;i <= n-1;i ++) {
		fscanf(stdin, "%d", &data[i]);
		for (int j = min(f, data[i]);j >= 1;j --) {
			if (f % j == 0 && data[i] % j == 0) {
				fprintf(stdout, "%d/%d\n", f/j, data[i]/j);
				break;
			}
		}
	}
	return 0;
}