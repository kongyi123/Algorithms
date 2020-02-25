// ó���� �ð��ʰ�
// back �Լ��� string ���� (���� ������) �ϳ� ���ϱ� �������� AC���� 9.94% (256ms)  

// if (open_cnt > len - cur) return; �ű⼭ ����ġ�� �ϳ� �߰��ϴϱ� 19.84% (140ms)

// cur÷���� ���ڸ� dap�� ���Խ�Ű�� �ʴ� ��� ����ĭ�� �ѹ��� �ѱ�鼭 ��͸� ���� �� �ִ� ����� ä���Ͽ� �ӵ��鿡�� ��ŭ�� ���� ���̴��� ����.
//  > ���� ���� ����.

// ��� �Լ� ���ڿ� dap�� �־����µ�, �װ� ���������� ���ϱ� 2�� �̻� ������. > 24% (72ms)

// map ��� set�� ���ϱ� 2�谡 �� ������. > 59% (24ms)


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