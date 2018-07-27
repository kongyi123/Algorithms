#define _CRT_SECURE_NO_WARNINGS	
#include <stdio.h>

int main(void) {
	int n;
	fscanf(stdin, "%d", &n);
	int cnt = 0;
	
	for (int i = 1;i <= n;i++) {
		if (1 <= i && i <= 99) cnt++;
		else if (100 <= i && i <= 999) {
			int a = i % 10;
			int b = (i / 10) % 10;
			int c = (i / 100) % 10;
			if (c - b == b - a) cnt++;

		} 
	}

	fprintf(stdout, "%d", cnt);
	return 0;
}
