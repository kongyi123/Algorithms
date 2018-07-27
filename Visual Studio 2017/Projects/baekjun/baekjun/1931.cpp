// 그냥 퀵소트로 코딩하면 시간초과남
// 예외 처리.... 어떻게 발견할 것인가.
// 불편한 부분에 대한 데이터를 반드시 만들어봐야....

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int n;
int data[200010][2];
int table[100010][2];

void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;

	t = *(a + 1);
	*(a + 1) = *(b + 1);
	*(b + 1) = t;
}

int compare(int* a, int *b) {
	if (*(a+1) < *(b+1)) return -1;
	else if (*(a+1) > *(b+1)) return 1;
	return *a - *b;
}

int main(void) {
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		int a, b;
		fscanf(stdin, "%d %d", &a, &b);
		if (a > b) {
			int t = a;
			a = b;
			b = t;
		}
		
		data[i][0] = a; data[i][1] = b;
		for (int j = i;j > 1;j = j >> 1) {
			if (compare(&data[j][0], &data[j >> 1][0]) > 0) {
				swap(&data[j][0], &data[j >> 1][0]);
			}			
		}
	}
	
	for (int i = 1;i <= n;i++) {
		swap(&data[1][0], &data[n - i + 1][0]);

		for (int j = 1;;) {
			int k = j << 1;
			if (k > n - i) break;
			if (k + 1 <= n - i && compare(&data[k][0], &data[k+1][0]) < 0) k++;
			if (compare(&data[j][0], &data[k][0]) < 0) {
				swap(&data[j][0], &data[k][0]);
				j = k;
			}
			else break;
		}
	}


	int cnt = 1;
	table[1][0] = data[1][0];
	table[1][1] = data[1][1];
	for (int i = 2;i <= n;i++) {
		if (table[cnt][1] <= data[i][0]) {
			cnt++;
			table[cnt][0] = data[i][0];
			table[cnt][1] = data[i][1];
		}
	}

	fprintf(stdout, "%d", cnt);
	return 0;
}