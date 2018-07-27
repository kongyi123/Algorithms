#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <stdio.h>
#include <queue>

using namespace std;

void swap(int &a, int &b) {
	int t;
	t = a;
	a = b;
	b = t;
}

int main(void) {
	int T;
	int N, P, M;
	scanf("%d", &T);
	int data[200010];
	for (int tc = 1;tc <= T;tc++) {
		scanf("%d %d %d", &N, &P, &M);

		long sum;
		scanf("%ld", &sum);
		N -= 1;
		for (int i = 1;i <= N;i++) {
			scanf("%d", &data[i]);
			for (int j = i;j > 1;j = j / 2) {
				if (data[j] > data[j / 2]) swap(data[j], data[j / 2]);
			}
		}

		for (int i = 1;i <= N;i++) {
			swap(data[1], data[N - i + 1]);
			for (int j = 1;;) {
				int k = j * 2;
				if (k > N - i) break;
				if (k + 1 <= N - i && data[k] < data[k + 1]) k++;
				if (data[j] < data[k]) {
					swap(data[j], data[k]);
					j = k;
				}
				else break;
			}
		}

		for (int i = 1;i <= M;i++)
			sum -= data[i];
		for (int i = N;i >= N-P+1;i--)
			sum += data[i];
		
		printf("#%d %ld\n", tc, sum);
	}
}



