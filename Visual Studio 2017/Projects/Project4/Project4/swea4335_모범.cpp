
// 디버그 소스까지 있는 개 모범 소스... 내가 원하던 것.
// 모범 까지는 모르겠고... dbg 방식은 보고 배울 필요가 있다.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#define MAX_BOX (20) 

#define dbg //printf

int N = 0;

int dp[1 << MAX_BOX][MAX_BOX][4];
int c_1[1 << (MAX_BOX + 1)];
int c_2[1 << (MAX_BOX + 1)];
int c_3[1 << (MAX_BOX + 1)];
int cIdx = 0;
typedef struct BoxT
{
	int x;
	int y;
	int z;
} BoxT;



BoxT box[MAX_BOX];
int visit = 0;
int max(int a, int b)
{
	return a > b ? a : b;
}


int dfs(int x, int y, int h, int top, int faceType)
{
	dbg("[dfs] called with x:%d,y:%d,h:%d,top:%d,faceType:%d\n", x, y, h, top, faceType);

	int m = 0;


	if (dp[visit][top][faceType]) {
		dbg("return immediately dp[visit:%d][top:%d][faetType:%d] => %d\n", visit, top, faceType, dp[visit][top][faceType]);

		return dp[visit][top][faceType];
	}

	for (int i = 0; i < N; i++)
	{
		if (visit & (1 << i)) continue;
		if ((x >= box[i].x && y >= box[i].y) || (x >= box[i].y && y >= box[i].x))
		{
			visit |= (1 << i);
			m = max(m, dfs(box[i].x, box[i].y, box[i].z, i, 1));
			visit -= (1 << i);
		}

		if ((x >= box[i].x && y >= box[i].z) || (x >= box[i].z && y >= box[i].x))
		{
			visit |= (1 << i);
			m = max(m, dfs(box[i].x, box[i].z, box[i].y, i, 2));
			visit -= (1 << i);
		}
		if ((x >= box[i].y && y >= box[i].z) || (x >= box[i].z && y >= box[i].y))
		{
			visit |= (1 << i);
			m = max(m, dfs(box[i].y, box[i].z, box[i].x, i, 3));
			visit -= (1 << i);
		}
	}

	dp[visit][top][faceType] = m + h;

	dbg("return dp[visit:%d][top:%d][faceType:%d] = m(%d) + h(%d)\n", visit, top, faceType, m, h);

	c_1[cIdx] = visit;


	c_2[cIdx] = top;


	c_3[cIdx++] = faceType;

	return dp[visit][top][faceType];
}

int main()
{
	int T = 0;
	freopen("input.txt", "r", stdin); 
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++)
	{
		int m = 0;
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			scanf("%d %d %d", &box[i].x, &box[i].y, &box[i].z);
		}

		for (int i = 0; i < N; i++)
		{
			if (visit & (1 << i)) continue;
			visit |= (1 << i);

			dbg("dfs(box[%d].x:%d,box[%d].y:%d,box[%d].z:%d,i:%d,1)\n", i, box[i].x, i, box[i].y, i, box[i].z, i);
			m = max(m, dfs(box[i].x, box[i].y, box[i].z, i, 1));

			dbg("dfs(box[%d].x:%d,box[%d].z:%d,box[%d].y:%d,i:%d,1)\n", i, box[i].x, i, box[i].z, i, box[i].y, i);
			m = max(m, dfs(box[i].x, box[i].z, box[i].y, i, 2));

			dbg("dfs(box[%d].y:%d,box[%d].z:%d,box[%d].x:%d,i:%d,1)\n", i, box[i].y, i, box[i].z, i, box[i].x, i);
			m = max(m, dfs(box[i].y, box[i].z, box[i].x, i, 3));

			visit -= (1 << i);
		}

		printf("#%d %d\n", test_case, m);// , sizeof(dp)); 
		for (int i = 0; i < cIdx; i++)
		{
			dp[c_1[i]][c_2[i]][c_3[i]] = 0;
		}

		cIdx = 0;
		m = 0;
		visit = 0;
	}
	return 0;
}