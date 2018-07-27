// 14Ка

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int length(char *a) {
	int len = strlen(a);
	return len;
}

int sum(char *a) {
	int len = strlen(a);
	int tmp = 0;
	for (int i = 0;i < len;i++) {
		if (a[i] >= '0' && a[i] <= '9') {
			tmp += (a[i] - '0');
		}
	}

	return tmp;
}

int compare(char *a, char *b) {
	if (length(a) != length(b)) return length(a) - length(b);
	if (sum(a) != sum(b)) return sum(a) - sum(b);

	// dic
	int len = strlen(a);
	for (int i = 0;i < len;i++) {
		if (a[i] != b[i]) return a[i] - b[i];
	}
}

char data[1100][60];

void swap(char *a, char *b){
	int i;
	char t;
	for (int i = 0;i < 60;i++) {
		t = a[i];
		a[i] = b[i];
		b[i] = t;
	}
}

int main(void) {
	int n;
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		fscanf(stdin, "%s", &data[i]);
	}

	for (int i = 1;i <= n;i++) {
		for (int j = i + 1;j <= n;j++) {
			if (compare(data[i], data[j]) > 0) {
				swap(data[i], data[j]);
			}
		}
	}

	for (int i = 1;i <= n;i++) {
		fprintf(stdout, "%s\n", data[i]);
	}
	return 0;
}