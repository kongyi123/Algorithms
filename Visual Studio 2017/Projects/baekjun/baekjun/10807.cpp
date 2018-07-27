#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n;
int cnt[202];

int main(void) {
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		int data;
		fscanf(stdin, "%d", &data);
		cnt[data + 100] ++;
	}
	int v;
	fscanf(stdin, "%d", &v);
	fprintf(stdout, "%d", cnt[v + 100]);
	return 0;
}