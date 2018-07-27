#include <stdio.h>

template <typename Type>
Type max(Type a, Type b) {
	return a > b ? a : b;
}

int sum(int* &a, int* &b) {
	return *a + *b;
}

int main(void) {
	printf("%lf\n", max<double>(3, 7));
	int *a, *b;
	sum(a, b);
	while (1);
	return 0;
}