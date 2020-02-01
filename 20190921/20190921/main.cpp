#include"user.cpp"



// �켱���� 1 : ���� ī�尡 4��
// �켱���� 2 : ���� ī�尡 3��
// �켱���� 3 : ���� ī�尡 2�� x2
// �켱���� 4 : ���� ī�尡 2��
// �켱���� 5 : ��� �ٸ�ī��
// �켱���� 6 : ��� ����ī��.

// �켱������ ���� ī�尡 �¸�.
// �켱������ ���� ���.
// 1 : ���� ī�� 1���� ū�� �¸�
// 2 : ���� ī�� �� ū �͵��� �¸�, �Ѵ� ������ ���º�
// 3, 4 : ī�带 ū �ͺ��� ���ؼ� ū ���� �¸�.
// 5 : ���º�
// 6 : ���º�

// 10�� �ڸ����� ��.
// 10�� �ڸ��� ���ºθ�, 1�� �ڸ� ��

// 10�� �ڸ��� �켱���� 5�� ���ºΰ�, 1�� �ڸ��� �켱���� 5�� ���º��� ���,
// 10�� �ڸ��� ū ������� ������ ��, ���ؼ� ū ���� �¸�.

#include <stdio.h>
#include <time.h>
static int long seed = 5;

char* A[1000000][5];
char* B[1000000][5];
extern int test(char* A[1000000][5], char* B[1000000][5]);

static int pseudo_rand(void) {
	seed = seed * 214013 + 2531011;
	return (seed >> 16) & 0x7FFF;
}

static const char* cards[25] = {
	  "11","12","13","14","15",
	  "21","22","23","24","25",
	  "31","32","33","34","35",
	  "41","42","43","44","45",
	  "51","52","53","54","55",
};
char num[25];
int main() {
	int score = 0;
	for (int i = 0; i < 25; ++i) num[i] = i;
	for (int tc = 1; tc <= 10; ++tc) {
		for (int c = 0; c < 1000000; ++c) {
			for (int n = 0; n < 10; ++n) {
				int a = pseudo_rand() % 25;
				int b = pseudo_rand() % 25;

				int t = num[a];
				num[a] = num[b];
				num[b] = t;
			}
			for (int n = 0; n < 5; ++n) {
				A[c][n] = (char*)cards[num[n]];
				B[c][n] = (char*)cards[num[n + 5]];
			}
		}
		int start = clock();
		int res = test(A, B);
		score += clock() - start;
		printf("#%d %d\n", tc, res);
	}
	printf("SCORE : %d\n", score);
	return 0;
}