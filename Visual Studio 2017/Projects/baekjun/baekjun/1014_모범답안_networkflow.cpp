#include <iostream>
#include <cstdio>
#include <vector>

#define MAX_N 15

using namespace std;
int n, m;

char map[MAX_N][MAX_N];
int number[MAX_N][MAX_N];

vector<int> visit;
int visitCnt = 1;

vector<int> aMatch;
vector<int> bMatch;

vector<int> point;
vector<vector<int>> adj;
int dy[6] = { -1,-1,0,0,1,1 };
int dx[6] = { -1,1,-1,1,-1,1 };

bool dfs(int a)
{
	if (visit[a] == visitCnt)
		return false;

	visit[a] = visitCnt;

	for (int i = 0; i < adj[a].size(); i++)
	{
		int b = adj[a][i];

		if (bMatch[b] == -1 || dfs(bMatch[b]))
		{
			aMatch[a] = b;
			bMatch[b] = a;

			return true;
		}
	}
	return false;
}

int bipartiteMatch()
{
	int size = 0;

	visit = vector<int>(n*m + 1);
	aMatch = vector<int>(n*m + 1, -1);
	bMatch = vector<int>(n*m + 1, -1);

	for (int a = 0; a < point.size(); a++)
	{
		visitCnt++;
		size += dfs(point[a]);
	}

	return size;
}
int main()
{
	int tc;
	scanf("%d", &tc);

	while (tc--)
	{
		scanf("%d %d", &n, &m);

		adj = vector<vector<int>>(n*m + 1);
		point.clear();

		int crash = 0;
		for (int i = 0; i < n; i++)
			scanf("%s", map[i]);

		int cnt = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				// x의 개수 count
				if (map[i][j] == 'x')
					crash++;

				// i를 기준으로 짝수 / 홀수로 이분매칭을 한다.
				// 이때 짝수 위치를 point벡터에 담아둔다.
				if (j % 2 == 0)
					point.push_back(cnt);

				// 정점의 (i,j)를 cnt로 넘버링
				number[i][j] = cnt++;
			}

		// i가 짝수번째인 정점에서 컨닝 할 수 있는 모든 위치를 adj에 push
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j += 2)
			{
				if (map[i][j] == 'x')
					continue;

				for (int k = 0; k < 6; k++)
				{
					int y = i + dy[k];
					int x = j + dx[k];

					if (x < 0 || y < 0 || x >= m || y >= n || map[y][x] == 'x')
						continue;

					adj[number[i][j]].push_back(number[y][x]);
				}
			}

		// 이분 매칭
		int ans = bipartiteMatch();
		printf("%d\n", n*m - ans - crash);
	}
	return 0;
}