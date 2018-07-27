// 연습용. quciksort 내장함수는 백준저지 사이트 컴파일러에서는 인식 안된다.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define IN in
#define OUT out

FILE *in = fopen("input.txt", "r");
FILE *out = fopen("output.txt", "w");

int N;
int data[1000010][2];

int cmp(const void *p, const void *q) {
	int* a = (int*)p;
	int* b = (int*)q;

	if (*a > *b) {		// data[i][0] > data[j][0]
		return 1;
	}
	else if (*a == *b) {			
		if (*(a + 1) > *(b + 1)) {			// data[i][1] > data[j][1]
			return 1;
		}
	}

	return -1;
}

int main() {
	int i;
	fscanf(IN, "%d", &N);
	for (i = 1;i <= N;i++) {
//		fscanf(IN, "%d", &data[i]);
		fscanf(IN, "%d%d", &data[i][0], &data[i][1]);
	}

//	qsort(&data[1], N, sizeof(&data[1]), cmp);
	qsort(&data[1], N, sizeof(&data[1])*2, cmp);

	for (i = 1;i <= N;i++) {
		fprintf(OUT, "%d\n", data[i]);
	}
}