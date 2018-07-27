#include <stdio.h>

int main(void) {
	int n;
	int scorea = 100;
	int scoreb = 100;
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i ++) {
		int a, b;
		fscanf(stdin, "%d %d", &a, &b);
		if (a == b) continue;
		if (a < b) scorea = scorea - b;
		if (a > b) scoreb = scoreb - a;
	}

	fprintf(stdout, "%d\n%d", scorea, scoreb);
	return 0;
}