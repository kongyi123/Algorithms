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

template <typename T>
struct Heap {
	T* heap;
	int size;
	Heap() {
		heap = new Node[200001];
		size = 0;
	}
	void push(T a) {
		if (size == 0) {
			size++;
			heap[size] = a;
		}
		else {
			size++;
			heap[size] = a;
			int cur = size;
			while (cur / 2 >= 1 && heap[cur] < heap[cur / 2]) {
				swap(heap[cur], heap[cur / 2]);
				cur = cur / 2;
			}
		}
	}

	T top() {
		return heap[1];
	}

	void pop() {
		if (size == 0) return;
		heap[1] = heap[size];
		size--;
		int cur = 1;
		int idx = 1;
		while (1) {
			if (cur * 2 + 1 <= size) {
				if (heap[cur * 2] < heap[cur * 2 + 1]) idx = cur * 2;
				else idx = cur * 2 + 1;
			}
			else if (cur * 2 <= size) idx = cur * 2;

			if (heap[idx] < heap[cur]) {
				swap(heap[idx], heap[cur]);
				cur = idx;
			}
			else break;
		}

	}

	bool empty() {
		if (size == 0) return true;
		return false;
	}

	void clear() {
		delete heap;
		heap = new Node[200001];
		size = 0;
	}
};

int set[3][2] = { {1, 2}, {0, 2}, {0, 1} };

Heap<Node> q; // heap

int process() {
	q.clear();
	int max_height = 0;

	// 초기화
	for (int i = 1;i <= cnt;i++) 
		dy[c1[i]][c2[i]][c3[i]] = 0;

	
	cnt = 0;
	for (int i = 1;i <= N;i++) {
		int x, y, z;	
		x = dat[i][0]; y = dat[i][1]; z = dat[i][2];
		dy[x][i][0] = 1 << (i - 1); q.push(Node(x, dy[x][i][0], i, 0));
		dy[y][i][1] = 1 << (i - 1); q.push(Node(y, dy[y][i][1], i, 1));
		dy[z][i][2] = 1 << (i - 1); q.push(Node(z, dy[z][i][2], i, 2));
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
	while (!q.empty()) {
		Node cur = q.top(); 
		q.pop();

		for (int i = 1;i <= N;i++) {
			if ((cur.visited & (1 << (i - 1))) != 0) continue;
			x = dat[cur.id][set[cur.type][0]];  // cur의 x, y
			y = dat[cur.id][set[cur.type][1]];
			
			for (int j = 0;j <= 2;j++) { // 다음 타입이 j일때 
				if ((x >= dat[i][set[j][0]] && y >= dat[i][set[j][1]]) || (y >= dat[i][set[j][0]] && x >= dat[i][set[j][1]])) {
					if (dy[cur.height + dat[i][j]][i][j] == 0) { // 중복을 막기위함
						dy[cur.height + dat[i][j]][i][j] = cur.visited | (1 << (i - 1));
						q.push(Node(cur.height + dat[i][j], cur.visited | (1 << (i - 1)), i, j));
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