#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
using namespace std;

#define MAX 250002

using namespace std;

int abs(int a) {
	if (a < 0) return -a;
	return a;
}

struct Node {
	int x;
	int y;
	int id;
};

void swap(Node &a, Node &b) {
	Node t = a;
	a = b;
	b = t;
}

int Q;
int N;

int data_[MAX][2];
Node xheap[MAX];
int visited[MAX];
Node yheap[MAX];
int xpos[MAX];
int ypos[MAX];
int main()
{
	fscanf(stdin, "%d %d", &N, &Q);
	for (int i = 1; i <= N; i++) {
		fscanf(stdin, "%d %d", &data_[i][0], &data_[i][1]);
		xheap[i].x = data_[i][0];
		xheap[i].y = data_[i][1];
		xheap[i].id = i;

		yheap[i].x = data_[i][0];
		yheap[i].y = data_[i][1];
		yheap[i].id = i;
		for (int j = i; j > 1; j /= 2) {
			if (xheap[j].x > xheap[j / 2].x) {
				swap(xheap[j], xheap[j / 2]);
			}
		}
		for (int j = i; j > 1; j /= 2) {
			if (yheap[j].y > yheap[j / 2].y) {
				swap(yheap[j], yheap[j / 2]);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		swap(xheap[1], xheap[N - i + 1]);
		for (int j = 1; ; ) {
			int k = j * 2;
			if (k > N - i) break;
			if (k + 1 <= N - i && xheap[k].x < xheap[k + 1].x) k++;
			if (xheap[j].x < xheap[k].x) {
				swap(xheap[j], xheap[k]);
				j = k;
			}
			else break;
		}
	}	


	
	for (int i = 1; i <= N; i++) {
		swap(yheap[1], yheap[N - i + 1]);
		for (int j = 1; ; ) {
			int k = j * 2;
			if (k > N - i) break;
			if (k + 1 <= N - i && yheap[k].y < yheap[k + 1].y) k++;
			if (yheap[j].y < yheap[k].y) {
				swap(yheap[j], yheap[k]);
				j = k;
			}
			else break;
		}
	}

	for (int i = 1;i <= N;i++) {
		xpos[xheap[i].id] = i;
		ypos[yheap[i].id] = i;
	}

	
	int flag;
	queue<int> q;
	int a, b, c;
	int cur;
	for (int i = 1;i <= Q;i++) {
		
		fscanf(stdin, "%d %d %d", &a, &b, &c);
		q.push(a);
		visited[a] = i;

		
		while (!q.empty()) {
			flag = 0;
			cur = q.front(); q.pop();
			int x = xpos[cur];
			while (x < N) {
				x++;
				if (abs(xheap[x].x - xheap[xpos[cur]].x) <= c) {
					if (visited[xheap[x].id] != i) {
						visited[xheap[x].id] = i;
						if (xheap[x].id == b) {
							flag = 1;
							break;
						}
						q.push(xheap[x].id);
					}
				}
				else break;
			}
			if (flag) break;

			x = xpos[cur];
			while (2 <= x) {
				x--;
				if (abs(xheap[x].x - xheap[xpos[cur]].x) <= c) {
					if (visited[xheap[x].id] != i) {
						visited[xheap[x].id] = i;
						if (xheap[x].id == b) {
							flag = 1;
							break;
						}
						q.push(xheap[x].id);
					}
				}
				else break;
			}
			if (flag) break;

			int y = ypos[cur];
			while (y < N) {
				y++;
				if (abs(yheap[y].y - yheap[ypos[cur]].y) <= c) {
					if (visited[yheap[y].id] != i) {
						visited[yheap[y].id] = i;
						if (yheap[y].id == b) {
							flag = 1;
							break;
						}
						q.push(yheap[y].id);
					}
				}
				else break;
			}
			if (flag) break;

			y = ypos[cur];
			while (2 <= y) {
				y--;
				if (abs(yheap[y].y - yheap[ypos[cur]].y) <= c) {
					if (visited[yheap[y].id] != i) {
						visited[yheap[y].id] = i;
						if (yheap[y].id == b) {
							flag = 1;
							break;
						}
						q.push(yheap[y].id);
					}
				}
				else break;
			}
			if (flag) break;


		}
		if (visited[b] == i) {
			fprintf(stdout, "YES\n");
		}
		else fprintf(stdout, "NO\n");
	}

	return 0;
}