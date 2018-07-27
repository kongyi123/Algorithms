#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

FILE *in = fopen("output.txt", "r");
FILE *in2 = fopen("TextFile1.txt", "r");

int main(void) {
	char buf[100];
	char buf2[100];
	int cnt = 0;
	while (1) {
		fgets(buf, 100, in);
		fgets(buf2, 100, in2);
		cnt++;
		if (feof(in)) break;

		if (strcmp(buf, buf2) != 0) {
			fprintf(stdout, "%d\n", cnt);
			break;
		}
		
	}

	return 0;
}