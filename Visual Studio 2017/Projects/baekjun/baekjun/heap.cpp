#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define IN in
#define OUT out
#define MAX 5005

FILE *in = fopen("input.txt", "r");
FILE *out = fopen("output.txt", "w");

int heap[MAX];

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int main()
{
	int n;
	fscanf(IN, "%d", &n);

	// 힙 구현
	for (int i = 1; i <= n; i++) {
		int m;
		fscanf(IN, "%d", &m);
		heap[i] = m;
		for (int j = i; j > 1; j /= 2) {
			if (heap[j] > heap[j / 2]) {
				swap(&heap[j], &heap[j / 2]);
			}
		}
	}

	// 정렬
	for (int i = 1; i <= n; i++) {
		swap(&heap[1], &heap[n - i + 1]);
		for (int j = 1; ; ) {
			int k = j * 2;
			if (k > n - i) break;
			if (k + 1 <= n - i && heap[k] < heap[k + 1]) k++;
			if (heap[j] < heap[k]) {
				swap(&heap[j], &heap[k]);
				j = k;
			}

			else break;
		}

	}

	// 출력
	for (int i = 1; i <= n; i++)
		fprintf(OUT, "%d ", heap[i]);

	return 0;
}
