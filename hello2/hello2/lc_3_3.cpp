/*
Runtime: 8 ms, faster than 94.05% of C++ online submissions for Longest Substring Without Repeating Characters.
Memory Usage: 8.3 MB, less than 100.00% of C++ online submissions for Longest Substring Without Repeating Characters.
*/

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		vector<int> dict(256, -1);
		int maxLen = 0, start = -1;
		for (int i = 0; i != s.length(); i++) {
			if (dict[s[i]] > start)
				start = dict[s[i]];
			dict[s[i]] = i;
			maxLen = max(maxLen, i - start);
		}
		return maxLen;
	}
};

