#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int n;
int data[110];

int gcd(int a, int b) {
	int t1 = a, t2 = b;
	int t;
	//	a, b = b , a%b
	while (a % b) {
		t = a;
		a = b;
		b = t % b;
	}

	return b;
}

int main(void) {
	int t;
	fscanf(stdin, "%d", &t);
	for (int i = 1;i <= t;i++) {
		fscanf(stdin, "%d", &n);
		for (int j = 1;j <= n;j++) {
			fscanf(stdin, "%d", &data[j]);
		}
		int sum = 0;
		int j, k;
		for (j = 1;j <= n;j++) {
			for (k = j + 1;k <= n;k++) {
				sum = sum + gcd(data[j], data[k]);
			}
		}
		fprintf(stdout, "%d\n", sum);
	}
	return 0;
}