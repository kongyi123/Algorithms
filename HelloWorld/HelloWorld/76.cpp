// 76. Minimum Window Substring
/*
	string S와 T가 주어졌을 때, T의 모든 문자들을 포함하는 minimum window S를 구하여라. 
	시간복잡도 O(n) 만에.

	- T의 모든 문자들을 커버하는 window S가 없다면, 빈 string인 ""를 return 하라.
	- 주어진 데이터는 window S가 유일하게 존재하거나 존재하지 않는 것만 제공된다.
*/

#include <cstdio>
#include <string>
#include <iostream>
#include <unordered_map>
#define INF 2000000000

using namespace std;


class Solution {
public:
	string minWindow(string s, string t) {
		unordered_map<char, int> letters;
		//unordered map for storing the characters in t that we need to check for in s
		for (auto c : t) letters[c]++;
		int count = 0; //counts number of t's letters in current window
		int low = 0, min_length = INT_MAX, min_start = 0;

		for (int high = 0; high < s.length(); high++) {

			if (letters[s[high]] > 0) { //means that this letter is in t
				count++;
			}
			letters[s[high]]--; //reduce the count for the letter on which we are currently 

			if (count == t.length()) { //if current windows contains all of the letters in t

				while (low < high && letters[s[low]] < 0) { //move low ahead if its not of any significance
					letters[s[low]]++, low++;
				}

				if (min_length > high - low) { //update the min length
					min_length = high - (min_start = low) + 1;
				}

				letters[s[low++]]++; //move low ahaead and also increment the value
				count--; //count-- as we are moving low ahead & low pointed to a char in t before
			}
		}
		return min_length == INT_MAX ? "" : s.substr(min_start, min_length); //check for edge case & return the result
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


/*
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
*/
/*
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

		for (end = 0;end <= n;end ++) {
			if (full_remain > 0 && end < n) {
				if (check[s[end] - 'A']) {
					ch_remain[s[end] - 'A'] --;
					if (ch_remain[s[end] - 'A'] == 0) full_remain--;
				}
			}
			else {
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
				if (end == n) break;
				end--;
			}
		}

		if (dstart == -1) return string("");
		return s.substr(dstart, min);
	}
};

int main(void) {
	Solution sol;
	string s("BDAB");
	string t("AB");
	string output = sol.minWindow(s, t);
	cout << output;
	return 0;
}

*/
