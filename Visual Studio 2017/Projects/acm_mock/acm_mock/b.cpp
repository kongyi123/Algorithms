// 1시간 반 고민후.....쿠키가 가는 길이 다른 쿠키때문에 방해가 되는 것 까지 고려 못함
// gg

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <memory.h>
#define MAX 2010

int h, w, n;
int queue[11000][2];
int head, tail;

int map[110][110];
bool ch[110][110];

int table[110][110];
int c[110][2];
int hole[110][2];
int q[11000][3];

int length(int a, int b) {
	memset(ch, 0, sizeof(ch));
	int head, tail;
	int dir[4][2] = { {0,1},{1,0}, {-1, 0}, {0,-1} };
	head = 0, tail = 1;
	q[0][0] = c[a][0];
	q[0][1] = c[a][1];
	ch[c[a][0]][c[a][1]] = 1;
	while (head < tail) {
		for (int i = 0;i <= 3;i++) {
			int ny = q[head][0] + dir[i][0];
			int nx = q[head][1] + dir[i][1];
			if (1 <= ny && ny <= h && 1 <= nx && nx <= w) {
				if (ny == hole[b][0] && nx == hole[b][1]) {
					return q[head][2] + 1;
				}
				if (map[ny][nx] == 0 && ch[ny][nx] == 0) {
					q[tail][0] = ny;
					q[tail][1] = nx;
					q[tail][2] = q[head][2] + 1;
					tail++;
				}
				else if (map[ny][nx] == 1 && ch[ny][nx] == 0) {
					ch[ny][nx] = 1;
				}
			}
		}
		head++;
	}

	return -1;
}

int check() {
	int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
	while (head < tail) {
		for (int i = 0;i <= 3;i++) {
			int ny = queue[head][0] + dir[i][0];
			int nx = queue[head][1] + dir[i][1];
			if (map[ny][nx] == 0 && ch[ny][nx] == 0) {
				if (1 <= ny && ny <= h && 1 <= nx && nx <= w) {
					ch[ny][nx] = 1;
					//map[ny][nx] = 2;
					queue[tail][0] = ny;
					queue[tail][1] = nx;
					tail++;
				}
			}
			else if (map[ny][nx] == 1) {
				ch[ny][nx] = 1;
			}
		}
		head++;
	}

	for (int i = 1;i <= h;i++) {
		for (int j = 1;j <= w;j++) {
			if (ch[i][j] == 0 && map[i][j] == 1) {
				return 0;
			}
		}
	}

	return 1;
}


int src, sink;
int ftable[MAX][MAX];
int fcnt[MAX];
int edge[MAX][MAX][2];
int check2[MAX];
// edge[][][0] : 용량
// edge[][][1] : 유량

int sum = 0;

int min(int a, int b) {
	if (a > b) return b;
	return a;
}

int flag;

int back(int cur, int admissible) {
	if (cur == sink) {
		flag = 1;
		return admissible;
	}

	int curcnt = fcnt[cur];
	int frontier;
	int temp;
	for (int i = 1;i <= curcnt;i++) {
		frontier = ftable[cur][i];
		if (check2[frontier] == 1 || edge[cur][frontier][0] == edge[cur][frontier][1]) continue;

		check2[frontier] = 1;
		temp = back(frontier, min(admissible, edge[cur][frontier][0] - edge[cur][frontier][1]));
		if (flag == 1) {
			edge[cur][frontier][1] += temp; // 순방향 유량 증가
			edge[frontier][cur][1] -= temp; // 역방향 유량 감소
			return temp;
		}
		//		check[frontier] = 0; // 
	}


	return 0;
}

void input(int limit) {
	src = 1;
	sink = n + n + 2;
	int cnt;
	int from, to;

	for (from = 2;from <= n + 1;from++) {
		ftable[src][++fcnt[1]] = from;
		ftable[from][++fcnt[from]] = src; // 역방향
		edge[src][from][0] = 1;


		// all cow to chuksa
		for (int j = 1;j <= n;j++) {
			to = j + 1 + n; // src 떄문에 번호 하나씩 밀린다.
			ftable[from][++fcnt[from]] = to;
			ftable[to][++fcnt[to]] = from; // 역방향
			if (table[from-1][j] <= limit) edge[from][to][0] = 1;
		}
	}

	for (int i = n + 2;i <= n+n + 1;i++) {
		ftable[i][++fcnt[i]] = sink;
		ftable[sink][++fcnt[sink]] = i; // 역방향
		edge[i][sink][0] = 1;
	}
}

void process() {
	int temp_ad;
	sum = 0;
	while (1) {
		for (int i = 1;i <= sink;i++) check2[i] = 0;
		check2[src] = 1;
		flag = 0;
		temp_ad = back(src, 101);
		if (temp_ad == 0) break;
		sum += temp_ad;
	}


}



int can(int mid) {
	memset(edge, 0, sizeof(edge));
	memset(ftable, 0, sizeof(ftable));
	memset(fcnt, 0, sizeof(fcnt));
	memset(check2, 0, sizeof(check2));
	input(mid);
	if (mid == 3) {
		mid = mid;
	}
	process();
	if (sum == n) return 1;
	return 0;
}

int bsearch(int s, int e) {
	int result = 0;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (can(mid)) {
			result = s;
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}

	return result;
}

int main(void) {

	head = tail = 0;

	int i;
	fscanf(stdin, "%d %d %d", &h, &w, &n);
	for (int i = 1;i <= n;i++) {
		int a, b;
		fscanf(stdin, "%d %d", &a, &b);
		queue[tail][0] = a;
		queue[tail++][1] = b;
		ch[a][b] = 1;
		c[i][0] = a;
		c[i][1] = b;
	}

	for (int i = 1;i <= n;i++) {
		int a, b;
		fscanf(stdin, "%d %d", &a, &b);
		map[a][b] = 1;
		hole[i][0] = a;
		hole[i][1] = b;
	}

	int result = check();
	if (result == 0) {
		fprintf(stdout, "-1");
		return 0;
	}



	for (int i = 1;i <= n;i++) {		// 쿠키
		for (int j = 1;j <= n;j++) {	// 홀
			table[i][j] = length(i, j);
		
		}
	}

	result = bsearch(1, 10000);
	fprintf(stdout, "%d", result);



	return 0;
}