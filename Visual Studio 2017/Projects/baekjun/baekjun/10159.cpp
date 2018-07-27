#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>

int n, m;
int up[110][110];
int ucnt[110];

int down[110][110];
int dcnt[110];

int queue[200];
int check[110];
int ex[110][110];

int main(void) {
	
	fscanf(stdin, "%d", &n);
	fscanf(stdin, "%d", &m);
	for (int i = 1;i <= m;i++) {
		int a, b;
		fscanf(stdin, "%d %d", &a, &b);
		if (ex[a][b] == 1) continue;
		ex[a][b] = ex[b][a] = 1;
		
		ucnt[b] ++;
		up[b][ucnt[b]] = a;

		dcnt[a] ++;
		down[a][dcnt[a]] = b;
	}

	for (int i = 1;i <= n;i++) {
		int cnt = 0;

		
		// up case
		memset(queue, 0, sizeof(queue));
		memset(check, 0, sizeof(check));
		int head = 0, tail = 1;
		queue[0] = i; check[i] = 1;
		while (head < tail) {
			int cur = queue[head];
			for (int j = 1;j <= ucnt[cur];j++) {
				int tar = up[cur][j];
				if (check[tar] == 0) {
					check[tar] = 1;
					cnt++;
					queue[tail] = tar;
					tail++;
				}
			}
			head++;
		}

		// down case
		memset(queue, 0, sizeof(queue));
		memset(check, 0, sizeof(check));
		head = 0, tail = 1;
		queue[0] = i; check[i] = 1;
		while (head < tail) {
			int cur = queue[head];
			for (int j = 1;j <= dcnt[cur];j++) {
				int tar = down[cur][j];
				if (check[tar] == 0) {
					check[tar] = 1;
					cnt++;
					queue[tail] = tar;
					tail++;
				}
			}
			head++;
		}


		fprintf(stdout, "%d\n", n-cnt-1);
	}
	return 0;
}