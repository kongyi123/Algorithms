#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <memory.h>

int check[1100];
int dir[1100];

int main(void) {
	int t, n;
	int data;
	fscanf(stdin, "%d", &t);
	for (int i = 1;i <= t;i++) {
		fscanf(stdin, "%d", &n);
		memset(check, 0, sizeof(check));
		memset(dir, 0, sizeof(dir));
		for (int j = 1;j <= n;j++) {
			fscanf(stdin, "%d", &data);
			dir[j] = data;
		}
		int cnt = 0;
		for (int j = 1;j <= n;j++) {
			if (check[j] == 0) {
				int t = j;
				while (check[t] == 0) {
					check[t] = 1;
					t = dir[t];
				}
				cnt++;
			}
		}

		fprintf(stdout, "%d\n", cnt);
	}
	return 0;
}