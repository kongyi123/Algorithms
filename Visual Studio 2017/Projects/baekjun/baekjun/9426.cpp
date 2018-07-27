#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define IN in
#define OUT out

FILE *in = fopen("input.txt", "r");
FILE *out = fopen("output.txt", "w");

int n, k;
int sum[20];
int last;
int data[250010];
int table[250010];

void add(int a) {
	int temp[20] = { 0, };
	int t = 0;
	while (a) {
		temp[++t] = a % 10;
		a = a / 10;
	}

	for (int i = 1;i <= 15;i++) {
		sum[i] = sum[i] + temp[i];
		sum[i + 1] = sum[i + 1] + (sum[i] / 10);
		sum[i] = (sum[i] % 10);
		if (sum[i] != 0) last = i;
	}
}

void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}

int main(void) {
	fscanf(IN, "%d%d", &n, &k);
	int i;
	for (i = 1;i <= n;i++) {
		fscanf(IN, "%d", &data[i]);
	}


	// 처름 k개의 데이터 heap정렬
	for (i = 1;i <= k;i++) {
		table[i] = data[i];
		for (int j = i;j > 1;j >>= 1) {
			if (table[j] > table[j >> 1]) {
				swap(table[j], table[j >> 1]);
			}
		}
	}

	for (i = 1;i <= k;i++) {
		swap(table[1], table[k - i + 1]);
		for (int j = 1;;) {
			int temp = j << 1;
			if (temp > k - i) break;
			if (temp + 1 <= k - i && table[temp] < table[temp + 1])  temp++;
			if (table[j] < table[temp]) {
				swap(table[j], table[temp]);
				j = temp;
			}
			else break;
		}
	}

	add(table[(k + 1) / 2]);
	for (i = k + 1;i <= n;i++) {
		
	}

	

	for (int i = last;i >= 1;i--) {
		fprintf(OUT, "%d", sum[i]);
	}
	return 0;
}


