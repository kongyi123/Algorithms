#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n;
	char ch;
	int awin = 0, bwin = 0;
	fscanf(stdin, "%d\n", &n);
	for (int i = 1;i <= n;i++) {
		fscanf(stdin, "%c", &ch);
		if (ch == 'A') awin++;
		if (ch == 'B') bwin++;
	}

	if (awin == bwin) fprintf(stdout, "Tie");
	else if (awin > bwin) fprintf(stdout, "A");
	else {
		fprintf(stdout, "B");
	}
	return 0;
}