#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int data[1001];
int n;

void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}


int main(void) {
	scanf("%d", &n);
	for (int i = 1;i <= n;i++) {
		scanf("%d", &data[i]);
	}

	for (int i = 1;i <= n;i++) {
		for (int j = i + 1;j <= n;j++) {
			if (data[i] < data[j]) swap(data[i], data[j]);
		}
	}

	int sum = 0;
	for (int i = 1;i <= n;i++) {
		sum += data[i] * i;
	}

	printf("%d", sum);

	return 0;
}