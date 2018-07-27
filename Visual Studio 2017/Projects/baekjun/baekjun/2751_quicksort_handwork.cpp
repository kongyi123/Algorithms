// 퀵정렬 version 별 복습용 : 직접 작성 - 암기.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define IN in
#define OUT out

FILE *in = fopen("input.txt", "r");
FILE *out = fopen("output.txt", "w");

int N;
int data[10000010];
int t;

void quicksort(int s, int e, int data[]) {
	int pivotI = s + 1;
	int pivotJ = e;

	if (s < e) {
		while (1) {
			while (data[pivotI] <= data[s] && pivotI <= e) pivotI++;
			while (data[pivotJ] > data[s]) pivotJ--;

			if (pivotI < pivotJ) {
				t = data[pivotI]; data[pivotI] = data[pivotJ]; data[pivotJ] = t;
			}
			else break;
		}
		t = data[s]; data[s] = data[pivotJ]; data[pivotJ] = t;

		quicksort(s, pivotJ - 1, data);
		quicksort(pivotJ + 1, e, data);
	}
}


int main() {
	int i;
	fscanf(IN, "%d", &N);
	for (i = 1;i <= N;i++) {
		fscanf(IN, "%d", &data[i]);
	}

	quicksort(1, N, data);

	for (i = 1;i <= N;i++) {
		fprintf(OUT, "%d\n", data[i]);
	}
}