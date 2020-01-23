#include <vector>
#include <string>

using namespace std;

#include <vector>
#include <string>

using namespace std;

class Solution {
	vector<string> ans;
	int col, row;
	int** check;
public:
	int dir[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };
	int back(int r, int c, int pivot, string& word, vector<vector<char>>& board) {
		if (word.size() == pivot) {
			return 1;
		}
		for (int i = 0; i <= 3; i++) {
			int nr = r + dir[i][0];
			int nc = c + dir[i][1];
			if (0 <= nr && nr < row && 0 <= nc && nc < col) {
				if (word[pivot] == board[nr][nc] && check[nr][nc] == 0) {
					check[nr][nc] = 1;
					int result = back(nr, nc, pivot + 1, word, board);
					check[nr][nc] = 0;
					if (result) return result;
				}
			}
		}
		return 0;
	}

	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		row = board.size();
		col = board[0].size();
		check = new int* [row];
		for (int i = 0; i < row; i++) {
			check[i] = new int[col];
			for (int j = 0; j < col; j++) {
				check[i][j] = 0;
			}
		}


		int n = words.size();
		for (int k = 0; k < n; k++) {
			int flag = 0;
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					if (words[k][0] == board[i][j]) {
						check[i][j] = 1;
						int result = back(i, j, 1, words[k], board);
						check[i][j] = 0;
						if (result) {
							flag = 1; break;
						}
					}
				}
			}
			if (flag) ans.push_back(words[k]);
		}

		return ans;
	}
};




int main(void) {
	Solution s;
	vector<vector<char>> board;
	vector<char> row;
	row.push_back('a'); row.push_back('b'); row.push_back('c'); 
	board.push_back(row); row.clear();
	row.push_back('a'); row.push_back('e'); row.push_back('d');
	board.push_back(row); row.clear();
	row.push_back('a'); row.push_back('f'); row.push_back('g');
	board.push_back(row); row.clear();

	vector<string> words;
	words.push_back("eaabcdfga");
/*	words.push_back("pea");
	words.push_back("eat");
	words.push_back("rain");
	*/
	//words.push_back("aaa");

	s.findWords(board, words);

	return 0;
}