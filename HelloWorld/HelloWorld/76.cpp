// 76. Minimum Window Substring
/*
	string S�� T�� �־����� ��, T�� ��� ���ڵ��� �����ϴ� minimum window S�� ���Ͽ���. 
	�ð����⵵ O(n) ����.

	- T�� ��� ���ڵ��� Ŀ���ϴ� window S�� ���ٸ�, �� string�� ""�� return �϶�.
	- �־��� �����ʹ� window S�� �����ϰ� �����ϰų� �������� �ʴ� �͸� �����ȴ�.
*/

#include <cstdio>
#include <string>
#include <iostream>
#define INF 2000000000

using namespace std;

class Solution {
public:
	int ch_remain[200] = { 0, };
	bool check[200] = { 0, };
	int full_remain = 0;
	int t_len, n;

	void setting(const string s, const string t) {
		t_len = t.size();
		n = s.size();
		for (int i = 0; i < t_len; i++) {
			check[t[i] - 'A'] = 1;
			if (ch_remain[t[i] - 'A'] == 0) full_remain++;
			ch_remain[t[i] - 'A'] ++;
		}
	}

	string minWindow(string s, string t) {
		setting(s, t);
		int start, end;
		start = end = 0;
		int min = INF, dstart, dend;

		while (start < n && end < n) {
			while (end < n && full_remain > 0) { 
				if (check[s[end] - 'A']) {
					ch_remain[s[end] - 'A'] --;
					if (ch_remain[s[end] - 'A'] == 0) full_remain--;
				}
				end++;
			}

			while (start < n && full_remain == 0) { 
				if (check[s[start] - 'A']) {
					ch_remain[s[start] - 'A'] ++;
					if (ch_remain[s[start] - 'A'] > 0) full_remain++;
				}
				start++;
			}

			if (min > end - start + 1) {
				min = end - start + 1;
				dstart = start - 1;
				dend = end - 1;
			}
		}

		if (dstart == -1) return string("");
		return s.substr(dstart, min);
	}
};

int main(void) {
	Solution sol;
	string s("ADOBECODEBANCDZ");
	string t("AD");
	string output = sol.minWindow(s, t);
	cout << output;
	return 0;
}