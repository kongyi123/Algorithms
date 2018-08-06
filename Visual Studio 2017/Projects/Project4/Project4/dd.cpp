#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

int main() {
	int N, score, P;
	int num[100];
	for (int i = 0; i < 100; i++) {
		num[i] = 0;
	}
	int min = 987654321;
	int rank = 1;

	scanf("%d %d %d", &N, &score, &P);

	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}
	for (int i = 0; i < N; i++) {
		if (num[i] <= score) break;
		else rank++;
	}
	if (score <= num[N - 1] && N == P) {
		printf("-1");
	}
	else printf("%d", rank);

	return 0;
}