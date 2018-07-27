#include <stdio.h>

int main(void) {
	int i;
	int data[21];
	int temp[21];
	for (i = 1;i <= 20;i ++) {
		data[i] = i;
	}

	for (i = 1;i <= 10;i ++) {
		int a, b;
		fscanf(stdin, "%d %d", &a, &b);
		for (int j = a;j <= b;j ++) {
			temp[j] = data[b-j+a];
		}
		for (int j = a;j <= b;j ++) {
			data[j] = temp[j];
		}
	}

	for (i = 1;i <= 20;i ++) fprintf(stdout, "%d ", data[i]);
	return 0;
}