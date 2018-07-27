#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define IN stdin
#define OUT stdout

//FILE *in = fopen("input.txt", "r");
//FILE *out = fopen("output.txt", "w");

int t;
int n;
int data[1010];

int main(void) {
	fscanf(IN, "%d", &t);
	for (int i = 1;i <= t;i++) {
		fscanf(IN, "%d", &n);
		int sum = 0;
		for (int j = 1;j <= n;j++) {
			fscanf(IN, "%d", &data[j]);
			sum = sum + data[j];
		}

		double ave = (double)sum / n;				// (double)(sum / n) го╦И ╬х╣й.
		int cnt = 0;
		for (int j = 1;j <= n;j++) {
			if (ave < data[j]) cnt++;
		}

		double dap;
		dap = (double)cnt / n  * 100;
		int i_dap = int(dap * 10000);
		if (i_dap % 10 >= 5) i_dap = i_dap / 10 + 1;
		else i_dap = i_dap / 10;


		fprintf(OUT, "%.3lf%%\n", (double)i_dap/1000);
	}
}