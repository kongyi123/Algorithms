#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define INPUT stdin
#define OUTPUT stdout

//FILE *in = fopen("input.txt", "r");
//FILE *out = fopen("output.txt", "w");

int N, prev;
int cnt[10];					// �� ���� ī��Ʈ �� �迭
int main() {
	fscanf(INPUT, "%d", &N);	// �Է�

	for (int i = 1; N; i *= 10) {
		int now = N % 10; // 1���ڸ���
		N /= 10;		  // �� �̻�
		for (int j = 0; j < now; ++j) {		// j = 0 1...
			cnt[j] += (N + 1) * i;			// 1���ڸ� ���� ������ ��+1  * i
		}
		cnt[now] += N * i + prev + 1;


		for (int j = now + 1; j < 10; ++j) {
			cnt[j] += N * i;
		}
		cnt[0] -= i;
		prev += now * i;
	}
	for (int i = 0; i < 10; ++i) 
		fprintf(OUTPUT, "%d ", cnt[i]);
}