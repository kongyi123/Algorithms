#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#define MAX 15
#define IN in
#define OUT out

FILE *in = fopen("input.txt", "r");
FILE *out = fopen("output.txt", "w");

char map[MAX][MAX];
int n, m;

// 노드는 최대 102개가 나옴
int check[103];
int table[105][105];
int cnt[105];

int flow[105][105];
int capacity[105][105];

int flag;

int src, sink;

int min(int a, int b) {
	if (a > b) return b;
	return a;
}

int back(int cur, int admissible) {
	if (cur == sink) {
		flag = 1;
		return admissible;
	}
	
	int tar, temp;
	for (int i = 1;i <= cnt[cur];i++) {
		tar = table[cur][i];
		if (check[tar] == 0 && capacity[cur][tar]-flow[cur][tar] > 0) {
			check[tar] = 1;
			temp = back(tar, min(admissible, capacity[cur][tar]-flow[cur][tar]));
			if (flag == 1) {
				flow[cur][tar] += temp;
				flow[tar][cur] -= temp;

				return temp;
			}
			check[tar] = 0;
		}
	}
	
	return 0;
}

int main(void) {
	char buf[10];
	fscanf(IN, "%d%d", &n, &m);
	for (int i = 1;i <= n;i++) {
		fgets(buf, 10, IN);
		for (int j = 1;j <= m;j++) {
			fscanf(IN, "%c", &map[i][j]);
		}
	}

	src = 1, sink = n*m + 2;

	int i, j, k;
	int a, b;

	for (i = 1;i <= m;i++) {
		if (map[1][i] == 'x') continue;
		a = src;
		b = i + 1;
		cnt[a] ++;
		table[a][cnt[a]] = b;
		cnt[b] ++;
		table[b][cnt[b]] = a;

		capacity[a][b] = 1;
	}

	for (i = 1;i <= m;i++) {
		if (map[n][i] == 'x') continue;
		a = m*(n - 1) + 2;
		b = sink;
		cnt[a] ++;
		table[a][cnt[a]] = b;
		cnt[b] ++;
		table[b][cnt[b]] = a;

		capacity[a][b] = 1;
	}

	for (i = 1;i <= n-1;i++) {
		for (j = 1;j <= m;j++) {
			if (map[i][j] == 'x') continue;
			for (k = 1;k <= m;k++) {
				if (map[i+1][k] == 'x') continue;
				if (k == j + 1 || k == j - 1) continue;
				
				a = (i - 1)*m + j + 1;
				b = i*m + k + 1;

				cnt[a] ++;
				table[a][cnt[a]] = b;
				cnt[b] ++;
				table[b][cnt[b]] = a;

				capacity[a][b] = 1;
			}
		}
	}

	int t;
	int dap = 0;
	while (1) {
		memset(check, 0, sizeof(check));
		check[src] = 1; flag = 0;
		t = back(src, 10);
		if (t == 0) break;
		dap += t;
	}

	fprintf(OUT, "%d", dap);


}