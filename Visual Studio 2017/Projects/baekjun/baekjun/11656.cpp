#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char str[1002];
char a[1002][1002];
int n;

int compare(char s1[], char s2[]) {
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	if (len1 < len2) len1 = len2;

	for (int i = 0;i < len1;i++) {
		if (s1[i] > s2[i]) {
			return 1;
		}
		else if (s1[i] < s2[i]) {
			return -1;
		} 
	}

	return 0;
}

void swap(char s1[], char s2[]) {
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	if (len1 < len2) len1 = len2;
	for (int i = 0;i < len1;i++) {
		char t = s1[i];
		s1[i] = s2[i];
		s2[i] = t;
	}
}

void quicksort(int s, int e, char arr[][1002]) {
	int pivotI = s + 1;
	int pivotJ = e;
	if (s < e) {
		while (1) {
			while (compare(arr[pivotI], arr[s]) <= 0 && pivotI <= e) pivotI++;
			while (compare(arr[pivotJ], arr[s]) > 0) pivotJ--;
			if (pivotI < pivotJ) swap(arr[pivotI], arr[pivotJ]);
			else break;
		}
		swap(arr[pivotJ], arr[s]);
		quicksort(s, pivotJ - 1, arr);
		quicksort(pivotJ + 1, e, arr);
	}
}

int main(void) {
	fscanf(stdin, "%s", &str);
	int len = strlen(str);
	n = len;
	for (int i = 0;i < len;i++) {
		for (int j = i;j < len;j++) {
			a[i+1][j-i] = str[j];
		}
	}

	quicksort(1, n, a);
	for (int i = 1;i <= n;i++) {
		fprintf(stdout, "%s\n", a[i]);
	}

	return 0;
}