#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#define INPUT stdin
#define OUTPUT stdout

//FILE *in = fopen("input.txt", "r");
//FILE *out = fopen("output.txt", "w");

int main(void) {
	char buf[201];

	while (!feof(INPUT)) {
		memset(buf, 0, sizeof(buf));
		fgets(buf, sizeof(buf), INPUT);
		fprintf(OUTPUT, "%s", buf);
		//fputs(buf, out);
	}
}