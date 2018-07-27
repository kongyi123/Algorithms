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
				// x�� ���� count
				if (map[i][j] == 'x')
					crash++;

				// i�� �������� ¦�� / Ȧ���� �̺и�Ī�� �Ѵ�.
				// �̶� ¦�� ��ġ�� point���Ϳ� ��Ƶд�.
				if (j % 2 == 0)
					point.push_back(cnt);

				// ������ (i,j)�� cnt�� �ѹ���
				number[i][j] = cnt++;
			}

		// i�� ¦����°�� �������� ���� �� �� �ִ� ��� ��ġ�� adj�� push
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

		// �̺� ��Ī
		int ans = bipartiteMatch();
		printf("%d\n", n*m - ans - crash);
	}
	return 0;
}