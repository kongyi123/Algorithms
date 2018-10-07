// 34

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

int D, W, K;
int dat[14][21];
int cpy[14][21];

pair<int, int> parent[14][21];

int MIN = 0x7fffffff;

vector<int> a;
vector<int> b;

pair<int, int> find(int y, int x) {
	if (parent[y][x].first > 0)	// 만약 대표자가 아닌 경우
		return parent[y][x] = find(parent[y][x].first, parent[y][x].second);
	else return pair<int, int>(y, x);	// 대표자인 경우 대표 넘버를 반환
}

void join(int y1, int x1, int y2, int x2) {
	parent[y1][x1] = find(y2, x2);
}

// 0 : A
// 1 : B
void back(int y) { // 현재의 막 번호
	if (a.size() + b.size() >= MIN) return;
	if (y == D + 1) {
		for (int i = 0;i < a.size();i++) 
			for (int j = 1;j <= W;j++) {
				cpy[a[i]][j] = dat[a[i]][j];
				dat[a[i]][j] = 0;
			}
			
		for (int i = 0;i < b.size();i++) 
			for (int j = 1;j <= W;j++) {
				cpy[b[i]][j] = dat[b[i]][j];
				dat[b[i]][j] = 1;
			}
		
		int no = 0;
		for (int j = 1;j <= W;j++) {
			int pass = 0;
			int cnt = 1;
			for (int i = 2;i <= D;i++) {
				if (dat[i][j] == dat[i - 1][j]) cnt++;
				else cnt = 1;
				if (cnt >= K) pass = 1;
			}

			if (pass == 0) {
				no = 1;
				break;
			}
		}

		if (no == 0) {
			int t = a.size() + b.size();
			if (MIN > t) MIN = t;
		}

		for (int i = 0;i < a.size();i++) 
			for (int j = 1;j <= W;j++) {
				dat[a[i]][j] = cpy[a[i]][j];
			}
			
		for (int i = 0;i < b.size();i++) 
			for (int j = 1;j <= W;j++) {
				dat[b[i]][j] = cpy[b[i]][j];
			}

	}
	else {
		a.push_back(y);
		back(y + 1);
		a.pop_back();
		b.push_back(y);
		back(y + 1);
		b.pop_back();
		back(y + 1);
	}
}

void init() {
	MIN = 0x7fffffff;
}

int main(void) {
	int T;
	scanf("%d", &T);
	for (int tc = 1;tc <= T;tc++) {
		init();
		scanf("%d%d%d", &D, &W, &K);
		for (int i = 1;i <= D;i++) {
			for (int j = 1;j <= W;j++) {
				scanf("%d", &dat[i][j]);
			}
		}
		/*
		for (int j = 1;j <= W;j++) {
			for (int i = 1;i <= D;i++) {
				parent[i][j] = -1;
			}
		}
		*/
		back(1);
		printf("#%d %d\n", tc, MIN);
	}
	return 0;
}