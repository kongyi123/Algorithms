#include<vector>
#include<stdio.h>
#include<string>
#define MAX 2000000000
using namespace std;

int num[200];
int op[200]; // op == 1 : +
			 // op == -1 : -
//int dy[200][200];

typedef struct d {
	int max;
	int min;
} D;

D dy[200][200];

int max(int a, int b) {
	if (a > b) return a;
	return b;
}

int min(int a, int b) {
	if (a > b) return b;
	return a;
}

int solution(vector<string> arr)
{
	int answer = 1;
	int len = arr.size();
	int n = 0;
	int m = 0;
	for (int i = 1;i <= len;i++) {
		if (i % 2 == 1) { // ¼ýÀÚ
			num[++n] = atoi(arr.at(i - 1).c_str());
			dy[n][n].min = dy[n][n].max = num[n];
		}
		else {
			if (arr.at(i - 1).compare("+") == 0) {
				op[++m] = 1;
			}
			else op[++m] = -1;
		}
	}

	for (int k = 1;k <= n - 1;k++) {
		for (int i = 1;i <= n - k;i++) {
			int tmax = -MAX;
			int tmin = MAX;
			for (int j = i;j < i + k;j++) {
				int val = dy[i][j].max + op[j] * dy[j + 1][i + k].min;
				tmax = max(tmax, val);
				val = dy[i][j].max + op[j] * dy[j + 1][i + k].max;
				tmax = max(tmax, val);

				val = dy[i][j].min + op[j] * dy[j + 1][i + k].min;
				tmin = min(tmin, val);
				val = dy[i][j].min + op[j] * dy[j + 1][i + k].max;
				tmin = min(tmin, val);
			}
			dy[i][i + k].max = tmax;
			dy[i][i + k].min = tmin;
		}
	}

	answer = dy[1][n].max;
	return answer;
}

int main(void) {
	vector<string> board;
	board.push_back("15");
	board.push_back("-");
	board.push_back("3");
	board.push_back("+");
	board.push_back("1");
	board.push_back("+");
	board.push_back("2");
	board.push_back("-");
	board.push_back("4");

	fprintf(stdout, "%d", solution(board));
}