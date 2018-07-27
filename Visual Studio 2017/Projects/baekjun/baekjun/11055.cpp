#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define IN stdin
#define OUT stdout

//FILE *in = fopen("input.txt", "r");
//FILE *out = fopen("output.txt", "w");

int data[1010];
int n;
int dy[1010];

int main(void) {
	int i, j;
	fscanf(IN, "%d", &n);
	for (i = 1;i <= n;i++) {
		fscanf(IN, "%d", &data[i]);
	}

	int dap = 0;
	for (i = 1;i <= n;i++) {
		int max = 0;
		for (j = 1;j <= i - 1;j++) {
			if (data[i] > data[j]) {
				if (max < dy[j]) max = dy[j];
			}
		}
		dy[i] = max + data[i];
		if (dap < dy[i])
			dap = dy[i];
	}

	fprintf(OUT, "%d", dap);


	return 0;
}