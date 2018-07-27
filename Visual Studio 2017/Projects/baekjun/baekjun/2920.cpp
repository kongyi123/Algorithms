#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int as = 1;
	int ds = 1;
	int val;
	for (int i = 1;i <= 8;i++) {
		fscanf(stdin, "%d", &val);
		if (val != i) as = 0;
		if (val != 8 - i + 1) ds = 0;
	}

	if (as == 1) fprintf(stdout, "ascending");
	else if (ds == 1) fprintf(stdout, "descending");
	else {
		fprintf(stdout, "mixed");
	}

	return 0;
}