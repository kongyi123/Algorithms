// 배열 크기 때문에 헤매다가 1시간 20분 걸림

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

int n;
char map[310][310];

typedef struct dtype {
	int y;
	int x;
};

vector<dtype> dap;

int normal(int y, int x);
void sewo(int y, int x);

void sewo(int y, int x) {
	if (map[y][x] == 'R') normal(y, x - 1);
	if (map[y][x + 1] == 'L') {
		normal(y, x + 1);
	}

	if (map[y][x] == 'U' && map[y][x + 1] == 'U') {
		if (map[y + 1][x] == 'D' && map[y + 1][x + 1] == 'D') {
			map[y][x] = map[y + 1][x] = 'L';
			map[y][x + 1] = map[y + 1][x + 1] = 'R';
			dtype t;
			t.y = y;
			t.x = x;
			dap.push_back(t);
		}
	}
}

int normal(int y, int x) {
	int result = 0;
	if (map[y][x] == 'L' && map[y][x + 1] == 'R') {
		if (map[y + 1][x] == 'L' && map[y + 1][x + 1] == 'R') {
			map[y][x] = map[y][x + 1] = 'U';
			map[y + 1][x] = map[y + 1][x + 1] = 'D';
			dtype t;
			t.y = y;
			t.x = x;
			dap.push_back(t);
			result =  1;
		}
		else result = 0;
	}
	else {
		return 0;
	}

	if (result == 0) {
		sewo(y + 1, x);
		return 1;
	}
}

int main(void) {
	char buf[10];
	fscanf(stdin, "%d", &n);
	for (int i = 0;i < n * 2;i++) {
		fgets(buf, 10, stdin);
		for (int j = 0;j < n * 2;j++) {
			fscanf(stdin, "%c", &map[i][j]);
		}
	}

	for (int i = 0;i < n * 2;i++) {
		for (int j = 0;j < n * 2;j++) {
			int result = normal(i, j);
			if (result == 1) {
				j--;
				continue;
			}
		}
	}

	fprintf(stdout, "%d\n", dap.size());
	for (dtype cur : dap) {
		fprintf(stdout, "%d %d\n", cur.y+1, cur.x+1);
	}

	return 0;
}