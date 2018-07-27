#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define IN in
#define MAX 100

FILE *in = fopen("input.txt", "r");

char q[MAX][200];
char a[MAX][200];
int c[MAX];
int n;

int main(void) {
	fprintf(stdout, "1. 문제 추가");
	fprintf(stdout, "2. text");
	fscanf(IN, "%d", &n);
	for (int i = 1;i <= n;i++) {
		fgets(q[i], sizeof(q[i]), IN); // 질
		fgets(a[i], sizeof(a[i]), IN); // 답
		fscanf(IN, "%d", &c[i]);
	}
	return 0;

}

