#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#define MAX 0x7fffffff
#define out stdout

//FILE *in = fopen("input.txt", "r");
//FILE *out = fopen("ouptut.txt", "w");

int main() {
	int N, score, P;
	int num[100];
	int score_[200] = { 0, };
	for (int i = 0; i < 100; i++) {
		num[i] = -2000000001;
		score_[i] = -MAX;
	}



	int min = 987654321;
	int rank = 1;
	scanf("%d %d %d", &N, &score, &P);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
		score_[i] = num[i];
		if (min > num[i]) min = num[i];
		if (num[i] > score) rank++;
	}

	if ((N - P) == 0) {
		if ((min == score) || (min > score)) printf("-1");
		if (min < score) printf("%d", rank);
	}
	else {
		printf("%d", rank);
	}


	int S = score;

	int pivot = -1;
	for (int i = 1;i <= P;i++) {
		if (S > score_[i]) {
			for (int j = P + 1;j >= i + 1;j--) {
				score_[j] = score_[j - 1];
			}
			score_[i] = S;
			pivot = i;
			break;
		}
	}

	if (pivot == -1) fprintf(out, "-1");
	else {
		int dap = 1, t = score_[1];
		int cnt = 1;
		for (int i = 2;i <= pivot;i++) {
			cnt++;
			if (t > score_[i]) {
				t = score_[i];
				dap = cnt;
			}
		}

		fprintf(out, "%d", dap);
	}

	return 0;
}