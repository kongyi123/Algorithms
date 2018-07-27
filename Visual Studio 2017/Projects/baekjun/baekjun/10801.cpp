#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a[11];
	int awin = 0, bwin = 0;
	for (int i = 1;i <= 10;i++)
		fscanf(stdin, "%d", &a[i]);
	for (int i = 1;i <= 10;i++) {
		int data;
		fscanf(stdin, "%d", &data);
		if (a[i] > data) awin++;
		else if (a[i] < data) bwin++;
	}
	if (awin > bwin) fprintf(stdout, "A");
	else if (awin == bwin) fprintf(stdout, "D");
	else fprintf(stdout, "B");

	
	return 0;
}