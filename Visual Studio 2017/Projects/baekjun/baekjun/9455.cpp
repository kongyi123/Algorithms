#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>

int data[110][110];
int cnt[110];

int main(void) {
	int t;
	int n, m;
	fscanf(stdin, "%d", &t);
	for (int i = 1;i <= t;i++) {
		memset(data, 0, sizeof(data));
		memset(cnt, 0, sizeof(cnt));
		fscanf(stdin, "%d %d", &n, &m);
		for (int j = 1;j <= n;j++) {
			for (int k = 1;k <= m;k++) {
				fscanf(stdin, "%d", &data[j][k]);
				cnt[k] += data[j][k];
			}
		}

		int sum = 0;
		for (int j = 1;j <= n;j++) {
			for (int k = 1;k <= m;k++) {
				if (data[j][k] == 1) {
					sum = sum + (n - j) + 1 - cnt[k];
					cnt[k] --;
				}
			}
		}
		fprintf(stdout, "%d\n", sum);
	}

	
	return 0;
}