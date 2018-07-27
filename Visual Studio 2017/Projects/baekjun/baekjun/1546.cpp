#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double data[1010];

int main(void) {
	int n;
	double sum = 0;
	double max;
	fscanf(stdin, "%d", &n);
	max = 0;
	for (int i = 1;i <= n;i++) {
		fscanf(stdin, "%lf", &data[i]);
		if (max < data[i]) max = data[i];
	}

	for (int i = 1;i <= n;i++) {
		sum = sum + (data[i] / max) * 100;
	}

	sum = sum / n;

	// 소수점 이하 3번째 자리에서 반올림
	sum = sum * 1000;						
	int i_sum = int(sum);
	if (i_sum % 10 >= 5) i_sum = i_sum / 10 + 1;
	else i_sum = i_sum / 10;
	// -----------------------------------------
	// 그냥 %.2lf 하면 99.99를 100으로 인식함....


	fprintf(stdout, "%.2lf", (double)i_sum/100);
	return 0;
}
