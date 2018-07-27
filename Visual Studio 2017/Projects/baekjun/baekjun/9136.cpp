#include <stdio.h>

int main(void) {
	int n;
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i ++) {
		fprintf(stdout, "Hello World, Judge %d!\n", i);
	}
	return 0;
}