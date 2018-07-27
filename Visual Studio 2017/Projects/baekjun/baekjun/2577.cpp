#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define IN stdin
#define OUT stdout

//FILE *in = fopen("input.txt", "r");
//FILE *out = fopen("output.txt", "w");

int cnt[10];

int main(void) {
	int a, b, c;
	fscanf(IN, "%d%d%d", &a, &b, &c);
	int t = a * b * c;
	while (t) {
		a = t % 10;
		cnt[a] ++;
		t = t / 10;
	}

	for (int i = 0;i <= 9;i++) {
		fprintf(OUT, "%d\n", cnt[i]);
	}

	return 0;
}