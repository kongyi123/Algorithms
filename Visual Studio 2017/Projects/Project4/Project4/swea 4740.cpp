/*

*** 1. 고작 240줄인데 디버깅한다고 헤맸다. 각 함수에 따른 최소한의 디버깅코드를 필수적으로 작성하도록 하자
	2. 모듈화를 위한 노력은 좋았다.
	3. 씸플 큐의 활용(큐를 배열을 이용하여 구현 한 것)도 좋았다. + 뿌요뿌요형 문제에 심플 큐를 활용한 중력처리 좋다.
	4. dfs를 이용한 카운팅 코드를 처음으로 작성해 봤다...!!
	5. swea에서는 문자열 입력 처리가 %c를 이용하면 잘 안된다. 
	(%c를 이용하면, 스페이스를 제외한 나머지 특수문자 즉, 엔터 값도 입력이 된다. 기존에 알고 있던게 맞음.
	다만, 쓰레기 버퍼를 처리하는 scanf문은 반드시 공통으로 처리하지말고 각 케이스별로 처리를 함으로써
	잘못된 입력 처리가 될 확률을 줄인다.)
	
  *	6. 에러 체크를 하면 궁극적으로는 더 빠르다. 의심하지 말자. 디버깅하게되면 백프로 더 느려지게 된다.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>

using namespace std;

int N, M, Q;
char table[31][31];

void gravity();
int isEmpty();
void Rfunction();
void Lfunction();
void Ufunction(char* row);
void Dfunction();
int isAllRow();

void Ufunction(char* row) {
	for (int j = 1;j <= M;j++) {
		for (int i = 1;i <= N - 1;i++) {
			table[i][j] = table[i + 1][j];
		}
	}

	for (int j = 1;j <= M;j++) table[N][j] = row[j];
	// cp. 출력해서 눈으로 확인하는 경우
	// cp. 기존의 table, row 배열의 문자 카운트와 합성 이후의 문자 카운트 일치성 여부 확인.
}

int visited[32][32];
int dir[4][2] = { { 0,1 } ,{ 1, 0 } ,{ -1, 0 },{ 0, -1 } };

int back(int y, int x, char ch) {
	int cnt = 0;
	for (int i = 0;i <= 3;i++) {
		int ny = y + dir[i][0];
		int nx = x + dir[i][1];
		if (ny <= N && ny > 0) {
			if (nx <= M && nx > 0) {
				if (table[ny][nx] == ch && visited[ny][nx] == 0) {
					visited[ny][nx] = 1;
					cnt = cnt + back(ny, nx, ch) + 1;
				}
			}
		}
	}


	// cp. bfs구현을 통한 카운트 값과 비교 일치 여부 확인.
	return cnt;
}

void erase(int y, int x, char ch) {
	for (int i = 0;i <= 3;i++) {
		int ny = y + dir[i][0];
		int nx = x + dir[i][1];
		if (ny <= N && ny > 0) {
			if (nx <= M && nx > 0) {
				if (table[ny][nx] == ch && visited[ny][nx] == 0) {
					visited[ny][nx] = 1;
					table[ny][nx] = '#';
					erase(ny, nx, ch);
				}
			}
		}
	}

	
}


void Dfunction() {
	int arr[1000][3], acnt = 0;
	for (int i = 1;i <= N;i++)
		for (int j = 1;j <= M;j++)
			visited[i][j] = 0;

	int max = 0, p;
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= M;j++) {
			if (table[i][j] != '#' && visited[i][j] == 0) {
				visited[i][j] = 1;
				int cnt = back(i, j, table[i][j]) + 1;
				arr[++acnt][0] = cnt;
				arr[acnt][1] = i;
				arr[acnt][2] = j;
				if (max < cnt) {
					max = cnt;
					p = acnt;
				}
			}
		}
	}

	for (int i = 1;i <= N;i++)
		for (int j = 1;j <= M;j++)
			visited[i][j] = 0;

	for (int i = 1;i <= acnt;i++) {
		if (max == arr[i][0]) {
			visited[arr[i][1]][arr[i][2]] = 1;
			erase(arr[i][1], arr[i][2], table[arr[i][1]][arr[i][2]]);
			table[arr[i][1]][arr[i][2]] = '#';
		}
	}
}



void Rfunction() {
	int queue[42];
	for (int i = 1;i <= N;i++) {
		int head = 0, tail = 0;
		for (int j = M;j >= 1;j--) {
			if (table[i][j] == '#') {
				queue[tail++] = j;
			}
			else {
				if (head < tail) {
					int x = queue[head];
					table[i][x] = table[i][j];
					table[i][j] = '#';
					queue[tail++] = j;
					head++;
				}
			}
		}
	}
}

void Lfunction() {
	int queue[42];
	for (int i = 1;i <= N;i++) {
		int head = 0, tail = 0;
		for (int j = 1;j <= M;j++) {
			if (table[i][j] == '#') {
				queue[tail++] = j;
			}
			else {
				if (head < tail) {
					int x = queue[head];
					table[i][x] = table[i][j];
					table[i][j] = '#';
					queue[tail++] = j;
					head++;
				}
			}
		}
	}
} // ok

void gravity() {
	int queue[32];
	for (int j = 1;j <= M;j++) {
		int t = N;
		int head = 0, tail = 0;
		for (int i = N;i >= 1;i--) {
			if (table[i][j] == '#') {
				queue[tail++] = i;
			}
			else {
				if (head < tail) {
					int y = queue[head];
					table[y][j] = table[i][j];
					table[i][j] = '#';
					queue[tail++] = i;
					head++;
				}
			}
		}
	}
} // ok

int isAllRow() {
	for (int i = 1;i <= N;i++) {
		int flag = 0;
		for (int j = 1;j <= M;j++) {
			if (table[i][j] != '#') {
				flag = 1; break;
			}
		}
		if (flag == 0) return 0; // 빈 행이 있는 경우 
	}
	return 1;
}

int isEmpty() {
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= M;j++) {
			if (table[i][j] == '#') continue;
			return 0;
		}
	}
	return 1;
}

int main(void) {
	int T;
	char buf;
	char row[32];
	scanf( "%d", &T);
	for (int tc = 1;tc <= T;tc++) {
		scanf( "%d %d %d", &N, &M, &Q);
		for (int i = 1;i <= N;i++) {
			scanf( "%s", &table[i][1]);
		}
		gravity();

		for (int i = 1;i <= Q;i++) {
			char step[3];
			scanf( "%s", &step);
			if (step[0] == 'U') {
				scanf( "%s", &row[1]);
				if (isAllRow()) continue;
				Ufunction(&row[0]);
				gravity();
			}
			else if (!isEmpty()) {
				if (step[0] == 'L') Lfunction();
				else if (step[0] == 'R') Rfunction();
				else if (step[0] == 'D') {
					Dfunction();
					gravity();
				}
			}
		}

		printf( "#%d\n", tc);

		for (int i = 1;i <= N;i++) {
			for (int j = 1;j <= M;j++) {
				printf( "%c", table[i][j]);
			}
			printf( "\n");
		}
		printf( "\n");
	}

	return 0;
}


