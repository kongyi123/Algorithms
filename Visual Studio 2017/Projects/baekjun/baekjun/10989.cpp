#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define IN stdin
#define OUT stdout
#define MAX 10010

//FILE *in = fopen("input.txt", "r");
//FILE *out = fopen("output.txt", "w");

int cnt[MAX];

int main()
{
	int t;
	int n;
	fscanf(IN, "%d", &n);

	for (int i = 1; i <= n; i++) {
		int m;
		fscanf(IN, "%d", &m);
		cnt[m] ++;
	}

	// Ãâ·Â
	for (int i = 1; i <= 10000; i++) {
		if (cnt[i] > 0) {
			for (int j = 1;j <= cnt[i];j++) {
				fprintf(OUT, "%d\n", i);
			}
		}
	}

	return 0;
}
