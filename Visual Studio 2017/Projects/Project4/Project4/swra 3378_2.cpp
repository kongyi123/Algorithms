// brute force인데...
// 예제 데이터가 없으면 엄청 틀릴만한 문제...


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define in stdin
#define out stdout

int T, P, Q;
int A[10][4];
char str[100];
int check[100];
int dap[100];
char qdata[100][100];

int main(void) {
	int a, b, c, d, e, f;
	int m;
	fscanf(in, "%d", &T);
	for (int tc = 1;tc <= T;tc++) {
		m = 0;
		a = b = c = d = e = f = 0;
		fscanf(in, "%d %d", &P, &Q);
		for (int i = 1;i <= P;i++) {
			fscanf(in, "%s", &str);
			int cnt = 0; // 온점의 개수
			int flag = 0;
			for (int j = 0;j < strlen(str);j++) {
				if (str[j] != '.') {
					flag = 1;
					if (str[j] == '(') a++;
					if (str[j] == ')') b++;
					if (str[j] == '{') c++;
					if (str[j] == '}') d++;
					if (str[j] == '[') e++;
					if (str[j] == ']') f++;
				}
				else if (flag == 0 && str[j] == '.') {
					cnt++;
				}
			}

			A[i][0] = a - b;
			A[i][1] = c - d;
			A[i][2] = e - f;
			A[i - 1][3] = cnt;
		}
		P = P - 1;

		for (int i = 1;i <= Q;i++) {
			fscanf(in, "%s", &qdata[i]);
		}

		// 해가 0인 행 제거
		for (int i = 1;i <= P;i++) {
			if (A[i][3] == 0) {
				for (int j = i;j < P;j++) {
					for (int k = 0;k <= 3;k++) {
						A[j][k] = A[j + 1][k];
					}
				}
				P--;
			}
		}
		
		for (int i = 1;i <= Q;i++) {
			dap[i] = -2;
		}
		
		int r, c, s;
		int re = 0;
		for (int R = 1;R <= 20;R ++) {
			for (int C = 1;C <= 20;C++) {
				for (int S = 1;S <= 20;S++) {
					int flag = 0;
					for (int i = 1;i <= P;i++) {
						if (R*A[i][0] + C*A[i][1] + S*A[i][2] != A[i][3]) {
							flag = 1;
							break;
						}
					}
					if (flag == 0) {
						a = b = c = d = e = f = 0;
 						for (int i = 1;i <= Q;i++) {
							if (dap[i] == -2) dap[i] = R * (a - b) + C * (c - d) + S * (e - f);
							else if (dap[i] != -1) { // 처음 넣는게 아닐 때
								if (dap[i] != R * (a - b) + C * (c - d) + S * (e - f)) { // 다른 값이 들어 갈 수 있다면 
									dap[i] = -1;
								}
							}
							for (int j = 0;j < strlen(qdata[i]);j++) {
								if (qdata[i][j] == '(') a++;
								if (qdata[i][j] == ')') b++;
								if (qdata[i][j] == '{') c++;
								if (qdata[i][j] == '}') d++;
								if (qdata[i][j] == '[') e++;
								if (qdata[i][j] == ']') f++;
							}
						}
					}
				}
			}
		}
		
		fprintf(out, "#%d ", tc);
		for (int i = 1;i <= Q;i++) {
			fprintf(out, "%d ", dap[i]);
		}
		fprintf(out, "\n");
	}


	return 0;
}