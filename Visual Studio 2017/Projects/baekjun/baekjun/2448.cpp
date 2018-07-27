#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define IN stdin
#define OUT stdout

//FILE *in = fopen("input.txt", "r");
//FILE *out = fopen("output.txt", "w");

char table[4000][8100];

void f(int offset, int sy, int ey, int size) {
	int i;
	if (size == 3) {
		
		table[sy][offset + 3] = '*';
		table[sy + 1][offset + 2] = '*'; table[sy + 1][offset + 4] = '*';
		for (i = offset+1;i <= offset+5;i++) table[sy+2][i] = '*';
		return;
	}
	
	f(offset + size/2, sy, (sy+ey)/2, size / 2);
	f(offset + size, (sy+ey)/2+1, ey, size / 2);
	f(offset, (sy + ey) / 2+1, ey, size / 2);

}

int main(void) {
	int n;
	fscanf(IN, "%d", &n);
	f(0, 1, n, n);

	for (int i = 1;i <= n;i ++) {
		for (int j = 1;j <= n*2;j++) {
			if (table[i][j] == '*') fprintf(OUT, "*");
			else fprintf(OUT, " ");
		}
		fprintf(OUT, "\n");
	}
	return 0;
}
