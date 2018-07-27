#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>

char a[1002];
char b[1002];

int dy[1002][1002];

int main(void) {
	fscanf(stdin, "%s", &a[1]);
	fscanf(stdin, "%s", &b[1]);
	int lena = strlen(&a[1]);
	int lenb = strlen(&b[1]);

	for (int i = 1;i <= lena;i++) {
		for (int j = 1;j <= lenb;j++) {
			int max = 0;
			if (max < dy[i][j - 1]) max = dy[i][j - 1];
			if (max < dy[i - 1][j]) max = dy[i - 1][j];
			if (a[i] == b[j]) {
				if (max < dy[i - 1][j - 1] + 1) {
					max = dy[i - 1][j - 1] + 1;
				}
			}
			dy[i][j] = max;
		}
	}

	fprintf(stdout, "%d", dy[lena][lenb]);
	return 0;
}