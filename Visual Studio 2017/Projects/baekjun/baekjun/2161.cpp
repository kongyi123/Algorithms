#include <stdio.h>

int a[2001];

int main(void) {
	int n;
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i ++) a[i] = i;
	
	for (int i = 1;i <= n;i += 2) {
		a[++n] = a[i+1];
		fprintf(stdout, "%d ", a[i]);
	}
	return 0;
}