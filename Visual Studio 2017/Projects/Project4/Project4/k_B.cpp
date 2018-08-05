#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <cstdlib>

using namespace std;

long long data[502];
long double A[502][502];
long double V[502][502];
long long S[502][502];
long long P[502][502];

int main(void) {
	srand((unsigned int)time(NULL));
//	for (int l = 1;l <= 100;l++) {
		int N, K;
		long double M;
		fscanf(stdin, "%d %d", &N, &K);
//		N = rand() % 500 + 1;
//		K = rand() % N + 1;
		for (int i = 1;i <= N;i++) {
			fscanf(stdin, "%ld", &data[i]);
//			data[i] = rand() % 1000001;
		}

		long long sum;
		long long psum;
		for (int i = 1;i <= N;i++) {
			sum = psum = 0;
			for (int j = i;j <= N;j++) {
				sum += data[j];
				psum += (data[j] * data[j]);
				A[i][j] = (long double)sum / (long double)(j - i + 1);
				S[i][j] = sum;
				P[i][j] = psum;
			}
		}

		for (int i = 1;i <= N;i++) {
			for (int j = i;j <= N;j++) {
				V[i][j] = (long double)((long double)P[i][j] - 2 * A[i][j] * (long double)S[i][j] + (long double)(j - i + 1)*A[i][j] * A[i][j]) / (long double)(j - i + 1);
			}
		}

		long double min = 2000000000000;
		for (int i = K;i <= N;i++) { // 연속된 개수
			for (int j = 1;j <= N - i + 1;j++) {
				int k = j + i - 1;
				if (min > V[j][k]) {
					min = V[j][k];
				}
			}
		}
/*
		long double min2 = 2000000000000;
		long double t;
		long double m;
		for (int i = 1;i <= N;i++) {
			for (int j = i;j <= N;j++) {
				if (j - i + 1 < K) continue;
				t = m = 0;

				for (int k = i;k <= j;k++) {
					m += data[k];
				}
				m = m / (long double)(j - i + 1);

				for (int k = i;k <= j;k++) {
					t += (data[k] - m)*(data[k] - m);
				}
				t = t / (long double)(j - i + 1);
				if (min2 > t) {
					min2 = t;
				}
			}
		}

		if (sqrt(min2) - sqrt(min) > 0.000001) {
			fprintf(stdout, "error!\n");
		}
*/
		fprintf(stdout, "%.11Lf\n", sqrt(min));
//	}
	return 0;
}