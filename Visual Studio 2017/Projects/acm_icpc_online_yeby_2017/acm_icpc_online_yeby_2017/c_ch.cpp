#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int link[100][100];
int n, m;
int cut = 999;
int ch[100];
int cnt;

void check(int node) {
	for (int i = 0;i < n;i++) {
		if (link[node][i] == 1 && ch[i] == 0) {
			ch[i] = 1; cnt++;
			check(i);
		}
	}
}

int eval() {
	int i, j;
	for (i = 0;i < n;i++) {
		for (j = 0;j < n;j++) {
			if (link[i][j] == 1) {
				link[i][j] = link[j][i] = 0;
				memset(ch, 0, sizeof(ch));
				ch[1] = 1;
				cnt = 1;
				check(1);
				link[i][j] = link[j][i] = 1;
				if (cnt != n) return -1;
			}
		}
	}

	return 1;
}

int back(int depth) {
	if (cut <= depth) return 1;
	

	for (int i = 0;i < n-1;i++) {
		if (link[i][i + 1] == 0) {
			link[i][i + 1] = link[i+1][i] = 1;
			if (eval() == 1) {
				if (cut > depth+1) {
					cut = depth+1;
				}
				link[i][i + 1] = link[i + 1][i] = 0;
				return 1;
			}
			back(depth + 1);
			link[i][i + 1] = link[i+1][i] = 0;
		}
	}
	if (link[n - 1][0] == 0) {
		link[n - 1][0] = link[0][n - 1] = 1;
		if (eval() == 1) {
			if (cut > depth + 1) {
				cut = depth + 1;
			}
			link[n - 1][0] = link[0][n - 1] = 0;
			return 1;
		}
		back(depth + 1);
		link[n - 1][0] = link[0][n - 1] = 0;
	}


}

int main(void) {
	fscanf(stdin, "%d %d", &n, &m);
	for (int i = 1;i <= m;i++) {
		int a, b;
		fscanf(stdin, "%d %d", &a, &b);
		link[a][b] = link[b][a] = 1;
	}

	back(0);

	if (cut == 999) cut = 0;
	fprintf(stdout, "%d", cut);

	return 0;
}