#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	int t;
	char buf[15];
	fscanf(stdin, "%d", &t);
	for (int i = 1;i <= t;i++) {
		char ch;
		int m;
		fscanf(stdin, "%d %c", &m, &ch);
		fgets(buf, 10, stdin);
		if (ch == 'C') {
			for (int j = 1;j <= m;j++) {
				fscanf(stdin, "%c", &ch);
				if (ch == ' ') {
					j--; continue;
				}
				fprintf(stdout, "%d ", ch - 'A' + 1);
			}
			fgets(buf, 10, stdin);
		}
		else {
			for (int j = 1;j <= m;j++) {
				int val;
				fscanf(stdin, "%d", &val);
				fprintf(stdout, "%c ", val + 'A' - 1);
			}
		}
		fprintf(stdout, "\n");
	}
	return 0;
}