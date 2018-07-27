#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 600
#define INPUT stdin
#define OUTPUT stdout

//FILE *in = fopen("input.txt", "r");
//FILE *out = fopen("output.txt", "w");

int table[MAX];
int count[MAX];
int path[MAX];
int data[10];
int n = 0;

int dap[MAX];
int dcnt = 0;

void input() {
	for (int i = 1;i <= 9;i++) {
		fscanf(INPUT, "%d", &data[i]);
	}
	
}

void process() {
	int cnt;
	int i, j;
	for (i = 1;i <= 9;i++) {
		cnt = 0;
		for (j = 0;j <= n;j++) {
			++cnt;
			table[n + cnt] = table[j] + data[i];
			count[n + cnt] = count[j] + 1;
			path[n + cnt] = j;
		}
		n += cnt;
	}
}

void output() {
	int i;
	for (i = 1;i <= n;i++) {
		if (count[i] == 7 && table[i] == 100) {
			break;
		}
	}

	int temp;

	while (i != 0) {
		temp = path[i];
		dap[++dcnt] = table[i] - table[temp];
		i = temp;
	}

	for (i = 1;i <= dcnt;i++) {
		for (int j = i + 1;j <= dcnt;j++) {
			if (dap[i] > dap[j]) {
				int t = dap[i];
				dap[i] = dap[j];
				dap[j] = t;
			}
		}
	}


	for (i = 1;i <= dcnt;i++) {
		fprintf(OUTPUT, "%d\n", dap[i]);
	}
}	

int main(void) {
	input();
	process();
	output();
}