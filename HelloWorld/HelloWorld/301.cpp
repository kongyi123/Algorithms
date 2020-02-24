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

	void back(string s, int cur ,int open_cnt, int set_cnt, string dap) {
		if (cur > len) {
			if (set_cnt == opt) {
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
				back(s, cur + 1, open_cnt + 1, set_cnt, dap);
				dap.pop_back();
			}
			back(s, cur + 1, open_cnt, set_cnt, dap);
		}
		else if (s[cur] == ')') {
			if (open_cnt > 0) {
				dap.push_back(s[cur]);
				back(s, cur + 1, open_cnt - 1, set_cnt + 1, dap);
				dap.pop_back();
			}
			back(s, cur + 1, open_cnt, set_cnt, dap);
		}
		else {
			dap.push_back(s[cur]);
			back(s, cur + 1, open_cnt, set_cnt, dap);
		}
		
	}

	vector<string> removeInvalidParentheses(string s) {
		result.clear();
		int open_cnt = 0;
		len = s.size();
		for (int i = 0; i < len; i++) {
			if (s[i] == '(') open_cnt++;
			else if (s[i] == ')' && open_cnt > 0) {
				opt++; open_cnt--;
			}
		}
		LOG(opt);

		if (opt)
			back(s, 0, 0, 0, "");
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
	string str("a");
//	string str("(a)())()");
//	string str("()())()");
//	string str(")))(()()))");
	vector<string> sol_str = sol.removeInvalidParentheses(str);

	return 0;
}