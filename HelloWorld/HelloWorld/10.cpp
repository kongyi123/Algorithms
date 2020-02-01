#include <string>
#include <vector>

using namespace std;
/*
#include <string>

using namespace std;

class Solution {
public:


	int isMatch(string s, string p) {
		int queue[5000][2];
		int mem[50][50] = { 0, };
		int size = 5000;
		// queue[][0] = s pivot  no miji
		// queue[][1] = p pivot  is miji
		int head = 0, tail = 1;
		queue[0][0] = 0;
		queue[0][1] = 0;
		int len_s = s.length();
		int len_p = p.length();
		while (head != tail) {
			int index_s = queue[head][0];
			int index_p = queue[head][1];
			if (index_s == len_s) {
				if (index_p == len_p) return 1;
				else if (index_p + 1 == len_p && p[index_p] == '*') return 1;
				else if (index_p + 1 == len_p - 1 && p[index_p + 1] == '*') return 1;
			}
			if (s[index_s] == p[index_p] || p[index_p] == '.') {
				if (mem[index_s + 1][index_p + 1] == 0) {
					mem[index_s + 1][index_p + 1] = 1;
					queue[tail][0] = index_s + 1;
					queue[tail][1] = index_p + 1;
					tail = (tail + 1) % size;
				}
			}
			else if (p[index_p] == '*') {
				if (len_p - index_p <= (len_s - index_s)*2 && index_p > 0) {
					if (mem[index_s][index_p - 1] == 0) {
						mem[index_s][index_p - 1] = 1;
						queue[tail][0] = index_s;
						queue[tail][1] = index_p - 1;
						tail = (tail + 1) % size;
					}
				}

				if (index_p + 1 < len_p) {
					if (mem[index_s][index_p + 1] == 0) {
						mem[index_s][index_p + 1] = 1;
						queue[tail][0] = index_s;
						queue[tail][1] = index_p + 1;
						tail = (tail + 1) % size;
					}
				}
			}

			if (index_p + 2 < len_p && p[index_p + 1] == '*') {
				if (mem[index_s][index_p + 2] == 0) {
					mem[index_s][index_p + 2] = 1;
					queue[tail][0] = index_s;
					queue[tail][1] = index_p + 2;
					tail = (tail + 1) % size;
				}
			}
			head = (head + 1) % size;
		}
		return false;
	}
};

// "aaaaaaaaaaaaab"
// "a*a*a*a*a*a*a*a*a*a*a*a*b"
*/


class Solution {
public:
	bool isMatch(string s, string p) {
		int dy[500][500];
		int len_p = p.size();
		int len_s = s.size();
		dy[0][0] = 1;
		for (int i = 0; i < p.size(); i++) {
			if (p[i] == '*') {
				dy[i][0] = dy[i - 1][0];
			}
		}

		for (int i = 0; i < len_p; i++) {
			for (int j = 0; j < len_s; j++) {
				if (s[j] == p[i] || p[i] == '.') {
					dy[i + 1][j + 1] = dy[i][j];			// p[i] 가 .이거나 동일한 문자면
				}
				else {
					if (p[i] == '*') {												// p[i]가 *이면
						dy[i+1][j+1] = dy[i-1][j+1];								// * = 0 
						if (s[j] == p[i-1] || p[i-1] == '.') { // * != 0 , 이전문자와 동일하거나, .인 경우에
							if (dy[i + 1][j] == 1) {
								dy[i + 1][j + 1] = 1;
							}
						}
					}
				}
			}
		}

		return dy[len_p-1][len_s-1];
	}
};


int main() {
	Solution sol;
	string s("aaaaaaaaaaaaab");
	string p("a*a*a*a*a*a*a*a*a*a*a*a*b");
	printf("answer : %d", sol.isMatch(s, p));
}



/*
class Solution {
public:
	bool isMatch(string s, string p) {
		vector<vector<bool>> dp(p.size() + 1,vector<bool> (s.size() + 1,false));
		dp[0][0] = true;
		for(int i = 1;i<=p.size();i++) {
			if(p[i-1]=='*') {
				dp[i][0] = dp[i-2][0];
			}
		}

		for(int i = 1;i<=p.size();i++) {
			for(int j = 1;j<=s.size();j++) {
				if(s[j-1] == p[i-1] || p[i-1] == '.') {
					dp[i][j] = dp[i-1][j-1];
				} else {
					if(p[i-1] == '*') {
						dp[i][j] = dp[i-2][j];
						if(s[j-1] == p[i-2] || p[i-2] =='.') {
							dp[i][j] = dp[i][j] || dp[i][j-1];
						}
					}
				}
			}
		}

		return dp[p.size()][s.size()];
	}
};

*/