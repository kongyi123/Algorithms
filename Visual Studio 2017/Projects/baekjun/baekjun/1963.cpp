#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <memory.h>

int check[20000];
int queue[74000];
int visit[74000];
int dir[5] = {10000, 1000, 100, 10, 1 };

int main(void) {
	check[0] = 1;
	int cnt = 0;
	for (int i = 2;i <= 9999;i++) {
		for (int j = i << 1;j <= 9999;j+=i) {
			check[j] = 1;
			cnt++;
		}
	}

	int t;
	fscanf(stdin, "%d", &t);
	for (int i = 1;i <= t;i++) {
		int a, b;
		fscanf(stdin, "%d %d", &a, &b);
		visit[a] = 1;
		int head = 0, tail = 1;
		queue[0] = a;
		while (head < tail) {
			int cur = queue[head];
			int t = cur;
			for (int j = 0;j <= 9;j++) {
				for (int k = 1;k <= 4;k++) {
					int a = int((cur % dir[k - 1]) / dir[k]) * dir[k];
					t = cur - a + j * dir[k];
					if (check[t] == 1) continue;
					if (t < 1000) continue;
					if (visit[t] != 0) continue;
					queue[tail++] = t;
					visit[t] = visit[cur] + 1;
				}
			}

			head++;		
		}
		
		if (visit[b] == 0) fprintf(stdout, "Impossible\n");
		else fprintf(stdout, "%d\n", visit[b]-1);
		memset(queue, 0, sizeof(queue));
		memset(visit, 0, sizeof(visit));
	}


	return 0;
}