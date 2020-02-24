#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void) {
	int a, b;
	scanf("%d %d", &a, &b);
	if (a > b) {
		for (int i = 1; i <= a;i++)
			printf("%d", b);

	}
	else {
		for (int i = 1; i <= b; i++)
			printf("%d", a);
	}
	return 0;
}