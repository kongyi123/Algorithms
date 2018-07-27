// vector 명으로 data를 쓰면 모호하다고 되면서 에러가 뜬다. 즉, 벡터명으로 data 사용 못함.
// vector는 무조건 배열로 표시한다면 index = 0 부터 쓰인다.
// 재귀 호출을 안쓰는 dfs는 의미가 없다. 속도는 비재귀가 더 빠른듯.

// 위 두가지 사항을 몰라서 헤메다가 시간을 보냄
// 33분


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <memory.h>


using namespace std;

bool arr[1100][1100];
bool check[1100];
int queue[1100000];
vector<int> dat[1100];

void back(int cur) {
	for (int i = 0;i < dat[cur].size();i++) {
		if (check[dat[cur][i]] == 0) {
			check[dat[cur][i]] = 1;
			fprintf(stdout, "%d ", dat[cur][i]);
			back(dat[cur][i]);
		}
	}
}

int main(void) {
	int n, m, v;
	fscanf(stdin, "%d %d %d", &n, &m, &v);
	for (int i = 1;i <= m;i++) {
		int a, b;
		fscanf(stdin, "%d %d", &a, &b);
		arr[a][b] = arr[b][a] = 1;
	}

	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			if (arr[i][j]) dat[i].push_back(j);
		}
	}

	check[v] = 1;
	fprintf(stdout, "%d ", v);
	back(v);
	memset(check, 0, sizeof(check));

	fprintf(stdout, "\n");

	int head = 0, tail = 1;
	queue[0] = v;
	check[v] = 1;
	fprintf(stdout, "%d ", v);
	while (head < tail) {
		int cur = queue[head];
		for (int i = 0;i < dat[cur].size();i++) {
			if (check[dat[cur][i]] == 0) {
				check[dat[cur][i]] = 1;
				queue[tail] = dat[cur][i];
				tail++;
				fprintf(stdout, "%d ", dat[cur][i]);
			}
		}
		head++;
	}

	return 0;
}