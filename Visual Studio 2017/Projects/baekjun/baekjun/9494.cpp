#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#include <string.h>
#define IN stdin
#define OUT stdout

//FILE *in = fopen("input.txt", "r");
//FILE *out = fopen("output.txt", "w");

char buf[120];

int main(void) {
	int n;
	while (1) {
		fscanf(IN, "%d", &n);
		if (n == 0) break;
		fgets(buf, 120, IN);
		int cur = 0;
		for (int i = 1;i <= n;i++) {
			fgets(buf, 120, IN);
			int len = strlen(buf);
			for (int j = 0;j < len;j++) {
				if (j < cur) continue;
				if (buf[j] == ' ' || buf[j] == '\n') {
					cur = j;
					break;
				}
			}
		}
		fprintf(OUT, "%d\n", cur+1);
	}

	return 0;
}