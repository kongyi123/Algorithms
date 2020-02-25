class Solution {
public:
	vector<string> removeInvalidParentheses(string str) {
		vector<string> res;
		int left = 0, right = 0;
		for (char ch : str) {
			if (ch == '(') {
				++left;
			}
			else if (ch == ')') {
				if (left > 0) --left;
				else ++right;
			}
		}

		dfs(res, str, 0, left, right, 0, "");
		return res;
	}

private:
	void dfs(vector<string>& res, const string& s, int start, int left, int right, int open, string path) {
		if (left < 0 or right < 0 or open < 0)
			return;

		const int len = s.size();
		if (start == len) {
			if (left == 0 and right == 0 and open == 0)
				res.push_back(path);

			return;
		}

		char c = s[start];
		if (c == '(') {
			if (start == 0 or s[start - 1] != c) {
				for (int i = 0; start + i < len and s[start + i] == c; ++i)
					dfs(res, s, start + i + 1, left - i - 1, right, open, path);
			}
			dfs(res, s, start + 1, left, right, open + 1, path + c);
		}
		else if (c == ')') {
			if (start == 0 or s[start - 1] != c) {
				for (int i = 0; start + i < len and s[start + i] == c; ++i)
					dfs(res, s, start + i + 1, left, right - i - 1, open, path);
			}
			dfs(res, s, start + 1, left, right, open - 1, path + c);
		}
		else
			dfs(res, s, start + 1, left, right, open, path + c);
	}
};