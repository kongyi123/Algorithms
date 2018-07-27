
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <vector>
#define IN in
#define OUT out

#define MAXN 100

FILE *in = fopen("input.txt", "r");
FILE *out = fopen("output.txt", "w");

using namespace std;

int n;
bool row[MAXN], col[MAXN], diag1[MAXN * 2 - 1], diag2[MAXN * 2 - 1];

int crossSol[MAXN][MAXN], plusSol[MAXN][MAXN];

void placeCrosses() { // x를 새로 놓는 것에 대하여...
	// 그 자리가 이미 결정지어진 행이나 열이 아니면
	for (int i = 0; i < n; i++) {
		if (row[i]) continue;
		for (int j = 0; j < n; j++) {
			if (col[j]) continue;

			crossSol[i][j] = 1; // x를 놓을 수 있는 자리를 찾아서 그 위치를 체크
			col[j] = true;		// 같은 열을 이제는 놓을 수 없도록 체크
			break;	// break를 함으로써 같은 row는 다음부터 손을 못대게 한다.
					// 그래서 굳이 row[i] = true;를 할 필요 없이 break; 한거임.
		}
	}

	// 즉, 넣을 수 있는 대로 바로바로 쳐 넣어댄다고 가정.
	// 이게 어째서 성립이 가능한거지?? 그리디잖아.
	// 어떻게 된다는 것을 알 수 있었던거지??
}

int placePluses() { // +를 두려면은 그 줄에 2개 이상 존재해야 하고, +만 존재해야한다.
	vector<int> ds;
	for (int i = 0; i < n - 1; i++) {
		ds.push_back(i);
		ds.push_back(n * 2 - i - 2);
	}
	ds.push_back(n - 1); // 좌밑 우위 대각선 체크를 할때 순서를 바깥쪽에서부터 중앙 순서대로 하기위한 셋팅
	// n == 3, ds = 0,4,1,3,2
	
/*
	for (int i = 0;i <= n * 2 - 2;i++) {
		ds.push_back(i);
	}
	*/


 	int points = 0;
	for (int d : ds) {
		if (diag1[d]) {  // 좌밑우위 대각선 이미 차지 되어있으면 그냥 포인트만 더하고 넘어가?
			points++;	// 포인트는 왜 더하는데. 포인트가 뭔데 plusPoint래는데.... 
			continue; 
		}  

		// 차지 안되고 있으면 좌밑 우위 대각선 위에 있는 
		// 격자를 순회하면서   그 격자의 좌위우밑 대각선 체크
		int i = d < n ? d : n - 1;
		int j = d < n ? 0 : d - n + 1;
		
		for (; i >= 0 && j < n; i--, j++) { 
			if (diag2[i - j + n - 1]) continue; // 좌위우밑 대각선 이미 차지 되어있으면 스킵
			
			// 어느 대각선이든 비어 있는 경우면 +를 둔다.
			plusSol[i][j] = 1;
			diag2[i - j + n - 1] = true;
			// 좌위우밑 대각선 체크를 해줌.
			// diag1을 해줄 필요가 없는 것은 다시 뒤로 돌아갈 일이 없을 것이기
			// 때문이다.
			points++;
			break;
		}
	}

	// 포인트를 카운팅하는 경우는 두가지.
	// 1. 좌밑우위 대각선이 차지해진 대로. (그 대각선에는 이미 +가 1개 있다는 뜻)
	// 2. 

	// points는 기존의 +의 점수에다가 추가로 +를 두면서 얻을 수 있는 점수
	return points;
}

int main() {
	int t; 
	fscanf(IN, "%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		int m; fscanf(IN, "%d %d", &n, &m); // n x n 크기의 무대, m명의 모델 입력

		// 초기화	
		memset(row, 0, sizeof(row));							// 행
		memset(col, 0, sizeof(col));							// 열
		memset(diag1, 0, sizeof(diag1));					    // 대각1
		memset(diag2, 0, sizeof(diag2));						// 대각2
		memset(crossSol, 0, sizeof(crossSol));					
		memset(plusSol, 0, sizeof(plusSol));

		char buf[100];
		for (int i = 0; i < m; i++) {
			fgets(buf, 10, IN);
			char ch; int r, c; fscanf(IN, "%c %d %d", &ch, &r, &c); 
			r--; c--;
			if (ch != '+') { 
				crossSol[r][c] = -1;
				row[r] = col[c] = true;	
			}
			if (ch != 'x') { 
				plusSol[r][c] = -1;
				diag1[r + c] = diag2[r - c + n - 1] = true;
			}
		}

		

		placeCrosses(); // x모델을 추가로 놓는다. (점수 계산은 없다)
		int plusPoints = placePluses(); // +모델을 추가로 놓는다. (+로 계산할 수 있는 점수 계산)

		int pieces = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (crossSol[i][j] > 0 || plusSol[i][j] > 0) pieces++;
				// crossSol과 plusSol 에는 새로 놓은 모델이 표시되어있다.
				// x나 +를 새로 둘 수 있는 자리면 piece를 카운다.

			}
		}



		// n+plusPoints는 모델을 두고 매긴 점수
		// piece는 새로 두는 모델의 수
		fprintf(OUT, "Case #%d: %d %d\n", tc, n + plusPoints, pieces);

		// crossSol에 체크가 된다는 것은 x를 둘 수 있는 자리라는 것이고
		// (즉, x를 하나만 두거나 같은 행에 x하나와 다른 +들을 둔다는 것)
		// plusSol에 체크가 된다는 것은 +를 둘 수 있는 자리라는 것이다.
		// (그것은 즉, +를 하나만 두거나 +하나와 다른 x들을 둔다는 것)
		// x나 +대신에 o를 둘 수 있다.
		// 새로 두는 것이라면 무조건 되어야 하는 거 아닌가??

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (crossSol[i][j] > 0 || plusSol[i][j] > 0) {
					char ch = crossSol[i][j] ? (plusSol[i][j] ? 'o' : 'x') : '+';
					// if (crossSol[i][j] == 1 && plusSol[i][j] == 1) ch = 'o';
					// if (crossSol[i][j] == 1 && plusSol[i][j] == 0) ch = 'x';
					// if (crossSol[i][j] == 0 && plusSol[i][j] == 1) ch = '+';


					// 만약에 +를 둘 수 있으면 'o'를 놓고
					// 그렇지 않으면 x를 두고
					// 둘 다 

					fprintf(OUT, "%c %d %d\n", ch, i + 1, j + 1);
				}
			}
		}
	}
	return 0;
}