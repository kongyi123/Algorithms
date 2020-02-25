// cur첨자의 문자를 dap에 포함시키든 안시키든 한칸씩 넘기면서 재귀를 돌리는 방식
// cur첨자의 문자를 dap에 포함시키지 않는 경우 여러칸을 한번에 넘기면서 재귀를 돌릴 수 있는 방식을 채택하여 속도면에서 얼만큼의 차를 보이는지 보자.

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#define LOG(x) 
//printf("%d", x)

using namespace std;

class Solution {
public:
	int opt = 0;
	int len;
	map<string, bool> mem;
	vector<string> result;
	string s;

	void back(int cur ,int open_cnt, int set_cnt, string dap) {
		if (open_cnt > len - cur) return;
		if (cur == len) {
			if (set_cnt == opt && open_cnt == 0) {
				if (mem[dap] == 0) {
					mem[dap] = 1;
					result.push_back(dap);
				}
			}
			return; 
		}

		if (s[cur] == '(') {
			if (open_cnt <= opt) {
				dap.push_back(s[cur]);
				back(cur + 1, open_cnt + 1, set_cnt, dap);
				dap.pop_back();
			}
			back(cur + 1, open_cnt, set_cnt, dap);
		}
		else if (s[cur] == ')') {
			if (open_cnt > 0) {
				dap.push_back(s[cur]);
				back(cur + 1, open_cnt - 1, set_cnt + 1, dap);
				dap.pop_back();
			}
			back(cur + 1, open_cnt, set_cnt, dap);
		}
		else {
			dap.push_back(s[cur]);
			back(cur + 1, open_cnt, set_cnt, dap);
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

		if (opt)
			back(0, 0, 0, "");
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
	string str("()((c))()())(m)))()(");	
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