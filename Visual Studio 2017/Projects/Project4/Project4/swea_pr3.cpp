#include <iostream>
using namespace std;

int map[15][30];
int dp[30][1 << 10][1 << 10];
int ans;
int H, W;
int cnt ;

int max(int a, int b)
{
	if (a < b)
		return b;
	else
		return a;
}

int dfs(int x, int y)
{
	int value, i, j;
	int order1, order2;
	order1 = 0; order2 = 0;
	value = 0;

	if (x >= H)
	{
		x = 1;
		y++;
	}
	if (y >= W)
	{
		return 0;
	}

	for (i = 1; i <= H; i++)
	{
		if (map[i][y] == 1)
		{
			order1 |= (1 << (i - 1));
		}
	}

	for (i = 1; i <= H; i++)
	{
		if (map[i][y + 1] == 1)
		{
			order2 |= (1 << (i - 1));
		}
	}

	if (dp[y][order1][order2] != -1)
	{
		return dp[y][order1][order2];
	}

	if (map[x + 1][y] == 1 || map[x + 1][y + 1] == 1)
	{
		value = max(value, dfs(x + 2, y));
		return value;
	}

	if (map[x][y] == 1 || map[x][y + 1] == 1)
	{
		value = max(value, dfs(x + 1, y));
		return value;
	}

	for (i = x; i <= x + 1; i++)
	{
		for (j = y; j <= y + 1; j++)
		{
			map[i][j] = 1;
		}
	}

	value = max(value, dfs(x + 2, y) + 1);

	for (i = x; i <= x + 1; i++)
	{
		for (j = y; j <= y + 1; j++)
		{
			map[i][j] = 0;
		}
	}

	value = max(value, dfs(x + 1, y));

	dp[y][order1][order2] = value;

	return dp[y][order1][order2];
}

int main(void)
{
	int T;
	int i;

	cin >> T;

	for (i = 1; i <= T; i++)
	{
		int j, k, l, t;
		cin >> H >> W;

		for (j = 1; j <= H; j++)
		{
			for (k = 1; k <= W; k++)
			{
				cin >> map[j][k];
			}
		}


		for (j = 1; j <= W; j++)
		{
			for (k = 0; k <= (1 << H) + 1; k++)
			{
				for (l = 0; l <= (1 << H) + 1; l++)
				{
					dp[j][k][l] = -1;
				}
			}
		}


		ans = dfs(1, 1);

		cout << "#" << i << " " << ans << endl;
	}
}