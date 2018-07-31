//				c = ((c - 1) % N) + 1;

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
//#define in stdin
//#define out stdout

FILE *in = fopen("input.txt", "r");
FILE *out = fopen("output.txt", "w");

using namespace std;

int N;
char col[1002][1002];
vector<vector<int>> rlink;
vector<vector<int>> blink;

int parent[1002];

int isCorrect(int t);
int bfs(int cur);
int bfs2(int cur);
int q[10000001];


int main(void) {
	int T;
	fscanf(in, "%d", &T);
	for (int tc = 1;tc <= T;tc++) {
		rlink.clear();
		blink.clear();
		fscanf(in, "%d", &N);
		for (int i = 1;i <= N+1;i++) {
			rlink.push_back(vector<int>());
			blink.push_back(vector<int>());
		}

		for (int i = 1;i <= N-1;i++) {
			fscanf(in, "%s", &col[i][i+1]);
			for (int j = i + 1;j <= N;j++) {
				col[j][i] = col[i][j];
			}
		}

		int cnt = 0;
		for (int i = 1;i <= N;i++) parent[i] = 0;
		for (int i = 1;i <= N;i ++) {
			if (parent[i] == 0) {
				parent[i] = 1001;
				cnt += bfs(i);
			}
		}
		
		for (int i = 1;i <= N;i++) parent[i] = 0;
		for (int i = 1;i <= N;i++) {
			if (parent[i] == 0) {
				parent[i] = 1001;
				cnt += bfs2(i);
			}
		}


		fprintf(out, "#%d %d\n", tc, cnt);
		fprintf(out, "correct? %d\n", isCorrect(cnt));
	}
	return 0;
}


int isCorrect(int t) {
	int cnt = 0;
	for (int i = 1;i <= N - 2;i++) {
		for (int j = i + 1;j <= N - 1;j++) {
			if (col[i][j] != '1') continue;
			for (int k = j + 1;k <= N;k++) {
				if (col[j][k] == '1' && col[i][k] == '1') {
					cnt++;
				}
			}
		}
	}
	
	for (int i = 1;i <= N - 2;i++) {
		for (int j = i + 1;j <= N - 1;j++) {
			if (col[i][j] != '0') continue;
			for (int k = j + 1;k <= N;k++) {
				if (col[j][k] == '0' && col[i][k] == '0') {
					cnt++;
				}
			}
		}
	}
	if (t == cnt) return 1;
	return 0;
}


int bfs(int cur) {
	int count = 0;
	int head = 0, tail = 1;
	q[head] = cur;
	while (head < tail) {
		int cur = q[head];
		for (int i = 1;i <= N;i++) {
			if (col[cur][i] != '1') continue;
			if (parent[i] == 0) {
				parent[i] = cur;
				q[tail++] = i;
			}
			else if (parent[i] == parent[cur]) {
				count++;
			}
			else if (col[cur][parent[i]] == '1' || col[parent[i]][cur] == '1') {
				count++;
			}
			else if (col[parent[cur]][i] == '1' || col[i][parent[cur]] == '1') {
				count++;
			}
		}

		head++;
	}

	return count/2;
}


int bfs2(int cur) {
	int count = 0;
	int head = 0, tail = 1;
	q[head] = cur;
	while (head < tail) {
		int cur = q[head];
		for (int i = 1;i <= N;i++) {
			if (col[cur][i] != '0') continue;
			if (parent[i] == 0) {
				parent[i] = cur;
				q[tail++] = i;
			}
			else if (parent[i] == parent[cur]) {
				count++;
			}
			else if (col[cur][parent[i]] == '0' || col[parent[i]][cur] == '0') {
				count++;
			}
			else if (col[parent[cur]][i] == '0' || col[i][parent[cur]] == '0') {
				count++;
			} 
			
		}

		head++;
	}

	return count / 2;
}