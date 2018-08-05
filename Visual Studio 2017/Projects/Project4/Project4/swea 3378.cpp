// 방정식을 ....가우스 조던 소거법으로 접근....
// 이렇게 접근하면 못푸는 그런문제.
// 예제를 샅샅이 확인한다음에 풀기 시작해야되는 문제..

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *in = fopen("input.txt", "r");
FILE *out = fopen("output.txt", "w");

int T, P, Q;
int A[10][4];
char str[100];
int check[100];
int D[3]; // R C S

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
			A[i-1][3] = cnt;
		}
		P = P - 1; 

		// 해가 0인 행 제거
		for (int i = 1;i <= P;i++) {
			if (A[i][3] == 0) {
				for (int j = i;j < P;j++) {
					for (int k = 0;k <= 3;k++) {
						A[j][k] = A[j + 1][k];
					}
				}
				P --;
			}
		}
		/*
		A[1][0] = 3; A[1][1] = 0; A[1][2] = 1; A[1][3] = 9;
		A[2][0] = 1; A[2][1] = 2; A[2][2] = 3; A[2][3] = 5;
		A[3][0] = 2; A[3][1] = 1; A[3][2] = 5; A[3][3] = 7;
		*/

		memset(check, 0, sizeof(check));
		// 1~P 행까지
		for (int j = 0;j <= 2;j++) {
			int pivot = -1;
			for (int i = 1;i <= P;i++) {
				if (A[i][j] != 0 && check[i] == 0) {
					check[i] = 1;
					pivot = i;
					break;
				}
			}

			if (pivot == -1) continue;
			int t1 = A[pivot][j];
			for (int i = 1;i <= P;i++) {
				if (i == pivot) continue;
				int t2 = A[i][j];
				for (int k = 0;k <= 3;k++) {
					A[i][k] = A[i][k] * t1 - A[pivot][k] * t2;
				}
			}
		}

		fprintf(out, "#%d ", tc);
		for (int j = 0;j <= 2;j++) {
			int er = 1;
			for (int i = 1;i <= P;i++) {
				if (A[i][j] != 0) {
					//fprintf(out, "%d ", A[i][3]/A[i][j]);
					D[j] = A[i][3] / A[i][j];
					er = 0;
					break;
				}
			}
			//if (er == 1) fprintf(out, "-1 ");
			if (er == 1) D[j] = -1;
		}

		a = b = c = d = e = f = 0;
		for (int i = 1;i <= Q;i++) {
			fscanf(in, "%s", &str);
			if ((D[0] == -1 && a - b != 0) || (D[1] == -1 && c - d != 0) || (D[2] == -1 && e - f != 0)) fprintf(out, "-1 ");
			else {
				fprintf(out, "%d ", D[0] * (a - b) + D[1] * (c - d) + D[2] * (e - f));
				for (int j = 0;j < strlen(str);j++) {
					if (str[j] == '(') a++;
					if (str[j] == ')') b++;
					if (str[j] == '{') c++;
					if (str[j] == '}') d++;
					if (str[j] == '[') e++;
					if (str[j] == ']') f++;
				}
			}
		}
		fprintf(out, "\n");

	}


	return 0;
}