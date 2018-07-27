#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define IN stdin
#define OUT stdout

//FILE *in = fopen("input.txt", "r");
//FILE *out = fopen("output.txt", "w");

int cnt[9000];

int main(void) {
	int n;
	int data;
	double sum = 0;
	int min = 9999, max = -9999;
	int mid = -9999;
	int count_max = 0, t;
	int count_max2 = 0, t2;
	fscanf(IN, "%d", &n);
	for (int i = 1;i <= n;i++) {
		fscanf(IN, "%d", &data);
		sum = sum + data;
		if (max < data) max = data;
		if (min > data) min = data;
		cnt[data+4500] ++;
	}

	int count = 0;
	for (int i = 0;i <= 8600;i++) {	// i : data+4500
		if (cnt[i] == 0) continue;
		count = count + cnt[i];
		if (count >= (n + 1) / 2 && mid == -9999) {
			mid = i - 4500;
		}
		if (count_max < cnt[i]) {
			count_max = cnt[i];
			t = i - 4500;
		}
		else if (count_max == cnt[i] && count_max2 != count_max) {
			count_max2 = count_max;
			t2 = i-4500;
		}

	}

	int i_sum = int(sum/n*10);
	if (i_sum % 10 >= 5) i_sum = i_sum / 10 + 1;
	else i_sum = i_sum / 10;

	if (count_max == count_max2) t = t2;
	fprintf(OUT, "%d\n%d\n%d\n%d\n", i_sum, mid, t, max - min);
	return 0;
}