// 10Ка

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <memory.h>

using namespace std;

int n, m;
vector<int> link[110];
bool check[110];
int rec[110];

bool back(int cur) {
	check[cur] = 1;
	for (auto& next : link[cur]) {
		if (rec[next] == 0 || (check[rec[next]] == 0 && back(rec[next]))) {
			rec[next] = cur;
			return true;
		}
	}
	return false;
}

int main(void) {
	fscanf(stdin, "%d %d", &n, &m);
	for (int i = 1;i <= m;i++) {
		int a, b;
		fscanf(stdin, "%d %d", &a, &b);
		link[a].push_back(b);
	}

	int cnt = 0;
	for (int i = 1;i <= n;i++) {
		if (back(i)) {
			memset(check, 0, sizeof(check));
			cnt++;
		}
	}

	fprintf(stdout, "%d", cnt);
	return 0;
}