// 처음에 시간초과
// back 함수에 string 인자 (원본 데이터) 하나 빼니까 가깟으로 AC나옴 9.94% (256ms)  

// if (open_cnt > len - cur) return; 거기서 가지치기 하나 추가하니까 19.84% (140ms)

// cur첨자의 문자를 dap에 포함시키지 않는 경우 여러칸을 한번에 넘기면서 재귀를 돌릴 수 있는 방식을 채택하여 속도면에서 얼만큼의 차를 보이는지 보자.
//  > 별로 차이 없다.

// 재귀 함수 인자에 dap을 넣었었는데, 그걸 전역변수로 빼니까 2배 이상 빨라짐. > 24% (72ms)

// map 대신 set을 쓰니까 2배가 더 빨라짐. > 59% (24ms)


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <set>

#define LOG(x) 
//printf("%d", x)

using namespace std;

class Solution {
public:
	int opt = 0;
	int len;
	set<string> mem;
	vector<string> result;
	string s;
	char* dap;
	int dcnt = 0;

	void back(int cur, int open_cnt, int set_cnt) {
		if (open_cnt > len - cur) return;
		if (cur == len) {
			if (set_cnt == opt && open_cnt == 0) {
				dap[dcnt] = 0;
				mem.insert(dap);
			}
			return;
		}

		if (s[cur] == '(') {
			if (open_cnt <= opt) {
				dap[dcnt++] = s[cur];
				back(cur + 1, open_cnt + 1, set_cnt);
				dcnt--;
			}
			back(cur + 1, open_cnt, set_cnt);
		}
		else if (s[cur] == ')') {
			if (open_cnt > 0) {
				dap[dcnt++] = s[cur];
				back(cur + 1, open_cnt - 1, set_cnt + 1);
				dcnt--;
			}
			back(cur + 1, open_cnt, set_cnt);
		}
		else {
			dap[dcnt++] = s[cur];
			back(cur + 1, open_cnt, set_cnt);
			dcnt--;
		}
	}

	vector<string> removeInvalidParentheses(string s) {
		result.clear();
		int open_cnt = 0;
		this->s = s;
		len = s.size();
		for (int i = 0; i < len; i++) {
			if (s[i] == '(') open_cnt++;
			else if (s[i] == ')' && open_cnt > 0) {
				opt++; open_cnt--;
			}
		}
		LOG(opt);
		dap = new char[len+1];

		if (opt) {
			back(0, 0, 0);
			for (auto str : mem) {
				result.push_back(str);
			}
		}
		else {
			string dap;
			dap.clear();
			for (int i = 0; i < len; i++) {
				if (s[i] != '(' && s[i] != ')') dap.push_back(s[i]);
			}

			result.push_back(dap);
		}
		return result;
	}
};


int main(void) {
	Solution sol;
	string str("()())()");
	//string str("()((c))()())(m)))()(");
	//	string str("(()");
	//	string str("a");
	//	string str("(a)())()");
	//	string str("()())()");
	//	string str(")))(()()))");
	vector<string> sol_str = sol.removeInvalidParentheses(str);
	for (int i = 0; i < sol_str.size(); i++) {
		cout << sol_str[i] << '\n';
	}

	return 0;
}