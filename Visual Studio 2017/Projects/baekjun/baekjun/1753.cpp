#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define IN stdin
#define OUT stdout

//FILE *in = fopen("input.txt", "r");
//FILE *out = fopen("output.txt", "w");

int table[1001][1001][2];
int cnt[1001];
int n, m;

int s, e;
int dist[1001];
int visit[1001];

int main(void) {
	int i, j;
	int a, b, c;
	fscanf(IN, "%d%d", &n, &m);
	fscanf(IN, "%d", &s);
	for (i = 1;i <= m;i++) {
		fscanf(IN, "%d%d%d", &a, &b, &c);
		table[a][++cnt[a]][0] = b;
		table[a][cnt[a]][1] = c;
	}


	for (i = 1;i <= n;i++) dist[i] = -1;
	dist[s] = 0;


	for (i = 1;i <= n;i++) {
		int min = 200000000;
		for (j = 1;j <= n;j++) {
			if (dist[j] == -1) continue;
			if (visit[j] == 1) continue;
			if (min > dist[j]) {
				min = dist[j];
				s = j;
			}
		}

		visit[s] = 1;

		for (j = 1;j <= cnt[s];j++) {
			int t = table[s][j][0], val = dist[s] + table[s][j][1];
			if (dist[t] == -1) dist[t] = val;
			else if (dist[t] > val) dist[t] = val;
		}
	}

	for (i = 1;i <= n;i++) {
		if (dist[i] == -1) fprintf(OUT, "INF\n");
		else {
			fprintf(OUT, "%d\n", dist[i]);
		}
	}

	return 0;
}