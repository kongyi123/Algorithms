#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n;
	fscanf(stdin, "%d", &n);
	int sum = 0;
	for (int i = 1;i <= n;i++) {
		int a;
		fscanf(stdin, "%d", &a);
		if (a < 0) sum = sum + -a;
		else sum = sum + a;
	}	
	
	for (int i = 1;i <= n;i++) {
		int a;
		fscanf(stdin, "%d", &a);
		if (a < 0) sum = sum + -a;
		else sum = sum + a;
	}

	fprintf(stdout, "%d", sum);

	return 0;
}
