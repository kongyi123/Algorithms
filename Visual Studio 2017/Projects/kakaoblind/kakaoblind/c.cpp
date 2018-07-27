#include <string>
#include <vector>
#include <conio.h>

using namespace std;

int check[40][40];

int refresh(int m, int n, vector<string> &board) { // 블록 지우고 지워지는 것의 개수를 반환
	// 스캔
	int move = 0;
	for (int i = m-2;i >= 0;i--) {
		for (int j = n-2;j >= 0;j--) {
			if (check[i][j] == 0) {
				char ch = board.at(i).at(j);
				if (ch == '_') continue;
				int er = 0;
				if (ch != board.at(i).at(j + 1)) er = 1;
				if (ch != board.at(i + 1).at(j)) er = 1;
				if (ch != board.at(i + 1).at(j + 1)) er = 1;
				if (er == 0) { // 정사각형 만들어짐
					check[i][j] = check[i][j + 1] = check[i + 1][j] = check[i + 1][j + 1] = 1;
					move = -1;
				}
			}
		}
	}

	// 처리
	for (int i = m-1;i >= 0;i --) {
		for (int j = 0;j <= n - 1;j++) {
			if (check[i][j] == 1) {
				int y = i;
				int x = j;
				while (1) {
					y--;
					if (y < 0) break;
					if (check[y][x] == 0) {
						swap(check[y][x], check[i][j]);
						swap(board.at(y).at(x), board.at(i).at(j));
					}
				} 
			}
		}
	}

	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
			if (check[i][j] == 1) board.at(i).at(j) = '_';
		}
	}


	if (move == 0) { // 움직임이 없었으면 남은 개수를 return
		int cnt = 0;
		for (int i = 0;i < m;i++) {
			for (int j = 0;j < n;j++) {
				if (check[i][j] == 0) cnt++;
			}
		}
		return cnt;
	}

	return move;
}

int solution(int m, int n, vector<string> board) {
	int answer = -1;
	while (answer == -1) {
		answer = refresh(m, n, board);
	}
	answer = (n*m) - answer;

	return answer;
}


int main(void) {
	vector<string> board;
	board.push_back("CCAACC");
	board.push_back("AAAAAA");
	board.push_back("BBBBBB");
	board.push_back("BBBBBB");
	board.push_back("CCAACC");
	board.push_back("AACCAA");
	fprintf(stdout, "%d", solution(6, 6, board));
	_getch();
	return 0;
}