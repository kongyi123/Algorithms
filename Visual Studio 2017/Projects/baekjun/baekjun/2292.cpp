#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n;
	int cnt = 1;
	fscanf(stdin, "%d", &n);
	if (n == 1) {
		fprintf(stdout, "1");
		return 0;
	}
	else {
		int a = 2;
		for (int i = 6;;i = i+6) {
			cnt++;
			if (n < a) {
				break;
			}
			a = a + i;			
		}
	}

	fprintf(stdout, "%d", cnt-1);
	return 0;
}
