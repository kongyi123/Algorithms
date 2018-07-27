#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define IN stdin
#define OUT stdout

//FILE *in = fopen("input.txt", "r");
//FILE *out = fopen("output.txt", "w");

int n;
char word[20010][62];
int num[20010];

int type;

void swap(char a[], char b[]) {
	char t;
	int lena = strlen(a);
	if (lena < strlen(b)) lena = strlen(b);
	for (int i = 0;i < lena;i++) {
		t = a[i];
		a[i] = b[i];
		b[i] = t;
	}
}

int compare(char a[], char b[]) {
	if (type == 0) {
		int lena = strlen(a);
		int lenb = strlen(b);
		return lena - lenb;
	}
	else {
/*		int i;
		for (i = 0;a[i] == b[i] && i <= lena; i++);
		return (a[i] - b[i]);		
		*/

		return strcmp(a, b);
	}
}

int compare2(char a[], char b[]) {
	int flag = 0;
	int lena = strlen(a);
	int lenb = strlen(b);
	if (lena != lenb) return 1;
	if (lena < lenb) lena = lenb;
/*	for (int i = 0;i < lena;i++) {
		if (a[i] != b[i]) {
			flag = 1; break;
		}
	}
	return flag;*/
	return strcmp(a, b);
}

void quicksort(int s, int e, char arr[][62]) {
	int pivotI = s + 1;
	int pivotJ = e;
	
	if (s < e) {
		while (1) {
			while (compare(arr[num[pivotI]], arr[num[s]]) <= 0 && pivotI <= e) pivotI++;
			while (compare(arr[num[pivotJ]], arr[num[s]]) > 0) pivotJ--;
			if (pivotI < pivotJ) {
//				swap(arr[num[pivotI]], arr[num[pivotJ]]);
				int t = num[pivotJ];
				num[pivotJ] = num[pivotI];
				num[pivotI] = t;
			}
			else break;
		}
		//swap(arr[num[pivotJ]], arr[num[s]]);
		int t = num[pivotJ];
		num[pivotJ] = num[s];
		num[s] = t;
		quicksort(s, pivotJ - 1, arr);
		quicksort(pivotJ + 1, e, arr);
	}
}

int main(void) {
	fscanf(IN, "%d", &n);
	for (int i = 1;i <= n;i++) {
		fscanf(IN, "%s", &word[i]);
		num[i] = i;
	}

	type = 0;
	quicksort(1, n, word);

	type = 1;
	int len = strlen(word[num[1]]), s = 1, e;
	for (int i = 2;i <= n;i++) {
		int t = strlen(word[num[i]]);
		if (len != t) {
			quicksort(s, i-1, word);
			s = i; len = t;
		}
	}
	quicksort(s, n, word);
	


	fprintf(OUT, "%s\n", word[num[1]]);
	for (int i = 2;i <= n;i++) {
		if (compare2(word[num[i]], word[num[i - 1]]) == 0) continue;
		fprintf(OUT, "%s\n", word[num[i]]);
	}


	return 0;
}
