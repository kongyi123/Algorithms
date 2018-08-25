// not ¸ÔÈ÷´Âµ¥?

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int ok;
int main(void) {
	int a, b, c;
	scanf("%d %d", &a, &b);
	ok = 0;

//	if (a == 2 || b == 4 || (a == 1 && b == 2)) {
//	if (a != 2 && b != 4 && (a != 1 || b != 2)) return 0;
//	if (!(a != 2 && b != 4 && (a != 1 || b != 2))) {
	if (!(a == 2 || b == 4 || (a == 1 && b == 2))) return 0;

	printf("ok\n");
	
	
	return 0;
}