#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int a[100];
int b[100];

int N;

void push() {
	int temp = a[N];
	for (int i = N;i >= 1;i--) {
		a[i] = a[i - 1];
	}
	a[1] = temp;
}

int main(void) {
	int max = 0;
	int maxa, maxb;
	maxa = maxb = 0;
	srand((unsigned int)time(NULL));
	scanf("%d", &N);
	for (int i = 1;i <= N;i++) {
		//scanf("%d", &a[i]);
		a[i] = rand() % 100;
		if (maxa < a[i]) maxa = a[i];
	}
	for (int i = 1;i <= N;i++) {
		//scanf("%d", &b[i]);
		b[i] = rand() % 100;
		if (maxb < b[i]) maxb = b[i];
	}

	int mm, t;
	for (int i = 1;i <= N-1;i++) {
		push();
		int sum = 0;
		t = 0;
		for (int j = 1;j <= N;j++) {
			sum += a[j] * b[j];
			if (t < a[j] * b[j])
				t = a[j] * b[j];
		}
		if (sum > max) {
			max = sum;
			mm = t;
		}
	}

	printf("%d\n", max);
	printf("%d %d\n", mm, maxa*maxb);
	return 0;
}