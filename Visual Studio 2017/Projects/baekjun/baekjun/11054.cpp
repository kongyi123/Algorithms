#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int i;
int pro[1100];
int poo[1100];
int data[1100];

int main(void) {
	int n;
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		fscanf(stdin, "%d", &data[i]);
	}

	for (int i = 1;i <= n;i++) {
		int max = 0;
		for (int j = 1;j <= i - 1;j++) {
			if (data[i] > data[j]) {
				if (max < pro[j])
					max = pro[j];
			}
		}
		pro[i] = max + 1;
	}

	for (int i = n;i >= 1;i--) {
		int max = 0;
		for (int j = n;j >= i + 1;j--) {
			if (data[i] > data[j]) {
				if (max < poo[j])
					max = poo[j];
			}
		}
		poo[i] = max + 1;
	}

	int max = 0;
	for (int i = 1;i <= n;i++) {
		if (max < pro[i] + poo[i])
			max = pro[i] + poo[i];
	}

	fprintf(stdout, "%d", max - 1);
	return 0;
}