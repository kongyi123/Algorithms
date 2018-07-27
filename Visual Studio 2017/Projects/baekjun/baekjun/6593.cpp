#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#define IN stdin
#define OUT stdout

//FILE *in = fopen("input.txt", "r");
//FILE *out = fopen("output.txt", "w");

int n, m, l;
char map[35][35][35];
char buf[10];
int queue[50000][3];
int check[35][35][35];
int dir[6][3] = { {0,0,1}, {0,1,0}, {1,0,0}, {-1, 0, 0}, {0, -1,0}, {0,0,-1} };

int process(int a, int b, int c) {
	int head = 0, tail = 1;
	memset(queue, 0, sizeof(queue));
	memset(check, 0, sizeof(check));
	queue[head][0] = a;
	queue[head][1] = b;
	queue[head][2] = c;
	int aa, bb, cc;
	int val;
	while (head < tail) {
		for (int i = 0;i <= 5;i++) {
			val = check[queue[head][0]][queue[head][1]][queue[head][2]];
			aa = queue[head][0] + dir[i][0];
			bb = queue[head][1] + dir[i][1];
			cc = queue[head][2] + dir[i][2];
			if (map[aa][bb][cc] == '#') continue;
			if (check[aa][bb][cc] > 0) continue;
			if (map[aa][bb][cc] == 'E') return val + 1;
			if (1 <= aa && aa <= n) {
				if (1 <= bb && bb <= m) {
					if (1 <= cc && cc <= l) {
						check[aa][bb][cc] = val + 1;
						queue[tail][0] = aa;
						queue[tail][1] = bb;
						queue[tail][2] = cc;
						tail++;
					}
				}
			}
		}
		head++;
	}

	return -1;
}

int main(void) {
	char ch;
	while (1) {
		memset(map, 0, sizeof(map));
		fscanf(IN, "%d%d%d", &n, &m, &l);
		if (n == 0 && m == 0 && l == 0) break;

		int s1, s2, s3;
		fgets(buf, 10, IN);
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j <= m;j++) {
				for (int k = 1;k <= l;k++) {
					fscanf(IN, "%c", &ch);
					if (ch == 'S') {
						s1 = i;
						s2 = j;
						s3 = k;
					}
					map[i][j][k] = ch;
				}
				fgets(buf, 10, IN);
			}
			fgets(buf, 10, IN);
		}


		int t = process(s1,s2,s3);
		if (t == -1) fprintf(OUT, "Trapped!\n");
		else fprintf(OUT, "Escaped in %d minute(s).\n", t);
	}

	return 0;
}