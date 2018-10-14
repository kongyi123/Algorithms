#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int R, C;
int visited[21][21][4][16];
int dat[21][21];
int num[21][21];

int finish;

// dy, dx
int dir[4][2] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };

char NumToChar[12] = { '<', '>', '^', 'v', '_', '|', '?', '.', '@', 'N', '+', '-' };
int CharToNum[300];

void back(int y, int x, int direction, int mem) {
	if (x == -1 && direction == 0) x = C - 1;
	else if (x == C && direction == 1) x = 0;
	else if (y == -1 && direction == 2) y = R - 1;
	else if (y == R && direction == 3) y = 0;

	if (visited[y][x][direction][mem] != 0) return;
	visited[y][x][direction][mem] = 1;

	if (finish == 1) return;

	switch (dat[y][x]) {
	case 0:
		back(y + dir[0][0], x + dir[0][1], 0, mem);
		break;
	case 1:
		back(y + dir[1][0], x + dir[1][1], 1, mem);
		break;
	case 2:
		back(y + dir[2][0], x + dir[2][1], 2, mem);
		break;
	case 3:
		back(y + dir[3][0], x + dir[3][1], 3, mem);
		break;
	case 4:
		if (mem == 0) back(y + dir[1][0], x + dir[1][1], 1, mem);
		else back(y + dir[0][0], x + dir[0][1], 0, mem);
		
		break;
	case 5:
		if (mem == 0) back(y + dir[3][0], x + dir[3][1], 3, mem);
		else back(y + dir[2][0], x + dir[2][1], 2, mem);
	
		break;
	case 6:
		for (int d = 0;d <= 3;d++) {
			back(y + dir[d][0], x + dir[d][1], d, mem);
		}
	
		break;
	case 7:
		back(y + dir[direction][0], x + dir[direction][1], direction, mem);
		break;
	case 8:
		finish = 1;
		return;
		
		break;
	case 9:
		back(y + dir[direction][0], x + dir[direction][1], direction, num[y][x]);
		
		break;
	case 10:
		if (mem == 15) mem = 0;
		else mem++;

		back(y + dir[direction][0], x + dir[direction][1], direction, mem);
		
		break;
	case 11:
		
		if (mem == 0) mem = 15;
		else mem--;

		back(y + dir[direction][0], x + dir[direction][1], direction, mem);
			
		break;
	}

	visited[y][x][direction][mem] = 0;
}

void init() {
	for (int i = 0;i < R;i++) {
		for (int j = 0;j < C;j++) {
			for (int k = 0;k <= 3;k++) {
				for (int l = 0;l <= 15;l++) {
					visited[i][j][k][l] = 0;
				}
			}
			num[i][j] = 0;
			dat[i][j] = 0;
		}
	}
}

int main(void) {
	int T;
	char A[21];
	//char NumToChar[12] = { '<', '>', '^', 'v', '_', '|', '?', '.', '@', 'N', '+', '-' };
	for (int i = 0;i <= 11;i++) CharToNum[NumToChar[i]] = i;

	int gol;
	scanf("%d", &T);
	for (int tc = 1;tc <= T;tc++) {
		scanf("%d%d", &R, &C);
		init();
		gol = 0;
		for (int i = 0;i < R;i++) {
			scanf("%s", A);
			for (int j = 0;j < C;j++) {
				if (A[j] == '@') {
					gol = 1;
				}
				if ('0' <= A[j] && A[j] <= '9') {
					num[i][j] = A[j] - '0';
					dat[i][j] = 9;
				}
				else {
					dat[i][j] = CharToNum[A[j]];
				}
			}
		}
	
		finish = 0;
		if (gol == 1) back(0, 0, 1, 0); // y, x, direction, mem
		printf("#%d ", tc);
		if (finish == 1) printf("YES\n");
		else printf("NO\n");
	}

	
	return 0;
}