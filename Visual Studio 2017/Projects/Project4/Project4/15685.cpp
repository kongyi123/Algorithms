// 1:48 1 Accept
// ��� ���� : 1. �迭�� �׷����� y�� ���� ('�迭���' ä������ �ڵ��� �����ؾ�.)
//             2. rotation �Լ� ���踦 �ϴ� ������. ��, v���͸� ��Ȯ�� ������ �Ŀ� �װ��� ������ �����ؾ�����... 
//								�̰��� ���ؼ� ���� �ȵǴ� �ڵ��� �س��� �� �ȵǴ���  ����� ��.
//						v ���� : �� ������ ��ǥ��. 
//						������ ���� ��Ȯ�� ���Ǹ� �ű�� ���� ���踦 �����ؾ�.
//						�ڵ��� ������ ���̴�.

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> v;
int table[110][110];
int x, y, d, g;

int min(int a, int b) {
	if (a > b) return b;
	return a;
}

int max(int a, int b) {
	if (a < b) return b;
	return a;
}

void draw() {
	for (int i = 0;i < v.size()-1;i ++) {
		if (v[i].first == v[i + 1].first) {
			for (int j = min(v[i].second, v[i+1].second);j <= max(v[i].second, v[i+1].second);j++) {
				table[j][v[i].first] = 1;
			}
		}
		else {
			for (int j = min(v[i].first, v[i+1].first);j <= max(v[i].first, v[i+1].first);j++) {
				table[v[i].second][j] = 1;
			}
		}
	}
}

void rotation_add() {
	int ex = v[v.size() - 1].first;
	int ey = v[v.size() - 1].second;
	int tx, ty;
	int nx, ny;
	int len = v.size();
	vector<pair<int, int>> t;
	for (int i = 0;i < len;i++) {
		nx = v[i].first;
		ny = v[i].second;
		
		
		nx -= ex;
		ny -= ey;
		tx = nx;
		ty = ny;
		
		nx = -ty + ex;
		ny = tx + ey;
		t.push_back(pair<int, int>(nx, ny));
	}

	for (int i = t.size() - 2;i >= 0;i--) {
		v.push_back(pair<int, int>(t[i].first, t[i].second));
	}
}

int count() {
	int cnt = 0;
	for (int i = 0;i <= 100;i++) {
		for (int j = 0;j <= 100;j++) {
			if (table[i][j] == 1 && table[i + 1][j] == 1 && table[i][j + 1] == 1 && table[i + 1][j + 1] == 1) {
				cnt++;
			}
		}
	}
	return cnt;
}


void process() {
	draw(); // 0 gen
	for (int i = 1;i <= g;i++) {
		rotation_add();
		draw();
	}
}

int main(void) {
	scanf("%d", &N);
	int dir[4][2] = {{ 1, 0 }, { 0, -1 }, { -1, 0 }, { 0, 1 }};
	for (int i = 1;i <= N;i++) {
		scanf("%d %d %d %d", &x, &y, &d, &g);
		v.push_back(pair<int, int>(x, y));
		v.push_back(pair<int, int>(x+dir[d][0], y+dir[d][1]));
		process();
		v.clear();
	}

	printf("%d", count());
	return 0;
}