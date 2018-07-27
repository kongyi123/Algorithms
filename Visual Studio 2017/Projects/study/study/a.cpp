#include <stdio.h>

void call(int* x, int* y) {
	*x = 3;
	printf("%d\n", *y);
}


int main(void) {
	int a[100];
	int b = 1;

	for (int i = 1;i <= 99;i++) a[i] = i;

	call(&b, &a[b]);
	return 0;
}