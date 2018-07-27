#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void){
	int a, b;
	fscanf(stdin, "%d%d", &a, &b);
	if (a == 2 && b == 18) fprintf(stdout, "Special");
	else if (a < 2 || (a == 2 && b < 18)) fprintf(stdout, "Before");
	else fprintf(stdout, "After");
	return 0;
}