// 냅섹 방식으로 짜면... 결국 손해.
// (1 << 19) * 20 * 3 을 매번 돌면서 20회를 또 돌아야 되기 때문


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int N;
int dat[21][3];
int dy[200001][21][3];

int c1[200001 * 21 * 3];
int c2[200001 * 21 * 3];
int c3[200001 * 21 * 3];
int cnt;

int max_(int a, int b) {
	if (a > b) return a;
	return b;
}

struct Node {
	int height;
	int visited;
	char id;
	char type;
	Node(int height, int visited, char id, char type) {
		this->height = height;
		this->visited = visited;
		this->id = id;
		this->type = type;
	}

	Node() {}

	bool operator<(Node node) const {
		if (this->height < node.height) return true;
		return false;
	}
};

template <typename T>
void swap(T &a, T &b) {
	T temp;
	temp = a;
	a = b;
	b = temp;
}


int set[3][2] = { {1, 2}, {0, 2}, {0, 1} };

int process() {
	int max_height = 0;

	// 초기화
	for (int i = 1;i <= cnt;i++) 
		dy[c1[i]][c2[i]][c3[i]] = 0;

	
	cnt = 0;
	for (int i = 1;i <= N;i++) {
		int x, y, z;	
		x = dat[i][0]; y = dat[i][1]; z = dat[i][2];
		dy[x][i][0] = 1 << (i - 1);
		dy[y][i][1] = 1 << (i - 1);
		dy[z][i][2] = 1 << (i - 1);
		max_height = max_(max_height, x);
		max_height = max_(max_height, y);
		max_height = max_(max_height, z);

		cnt++;
		c1[cnt] = x; c2[cnt] = i; c3[cnt] = 0;
		cnt++;
		c1[cnt] = y; c2[cnt] = i; c3[cnt] = 1;
		cnt++;
		c1[cnt] = z; c2[cnt] = i; c3[cnt] = 2;
	}

	int x, y;
	for (int k = 1;k <= 1 << 19;k ++) {
		for (int a = 1;a <= N;a++) {
			for (int i = 1;i <= N;i++) {
				if ((visited & (1 << (i - 1))) != 0) continue;
				x = dat[cur.id][set[cur.type][0]];  // cur의 x, y
				y = dat[cur.id][set[cur.type][1]];

				for (int j = 0;j <= 2;j++) { // 다음 타입이 j일때 
					if ((x >= dat[i][set[j][0]] && y >= dat[i][set[j][1]]) || (y >= dat[i][set[j][0]] && x >= dat[i][set[j][1]])) {
						if (dy[cur.height + dat[i][j]][i][j] == 0) { // 중복을 막기위함
							dy[cur.height + dat[i][j]][i][j] = cur.visited | (1 << (i - 1));
							cnt++;
							c1[cnt] = cur.height + dat[i][j];
							c2[cnt] = i;
							c3[cnt] = j;
							max_height = max_(max_height, cur.height + dat[i][j]);
						}
					}
				}
			}
		}
	}

	return max_height;
}

int main(void) {
	int T;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	for (int tc = 1;tc <= T;tc++) {
		scanf("%d", &N);
		for (int i = 1;i <= N;i++) {
			scanf("%d %d %d", &dat[i][0], &dat[i][1], &dat[i][2]);
		}


		printf("#%d %d\n", tc, process());
	}

	return 0;
}