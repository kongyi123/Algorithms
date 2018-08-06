#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 2000000000
//#define in stdin
//#define out stdout

FILE *in = fopen("input.txt", "r");
FILE *out = fopen("output.txt", "w");

int kongyi(int score[]) {
	int score[200] = { 0, };
	int N, S, P;
	fscanf(in, "%d %d %d", &N, &S, &P);

	for (int i = 0;i < 100;i++)
		score[i] = -MAX;

//	for (int i = 1;i <= N;i++) {
//		fscanf(in, "%d", &score[i]);
//	}

	int pivot = -1;
	for (int i = 1;i <= P;i++) {
		if (S > score[i]) {
			for (int j = P + 1;j >= i + 1;j--) {
				score[j] = score[j - 1];
			}
			score[i] = S;
			pivot = i;
			break;
		}
	}

	if (pivot == -1) fprintf(out, "-1");
	else {
		int dap = 1, t = score[1];
		int cnt = 1;
		for (int i = 2;i <= pivot;i++) {
			cnt++;
			if (t > score[i]) {
				t = score[i];
				dap = cnt;
			}
		}
		fprintf(out, "%d", dap);
	}

}