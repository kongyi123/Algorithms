/*
Runtime: 8 ms, faster than 94.05% of C++ online submissions for Longest Substring Without Repeating Characters.
Memory Usage: 7 MB, less than 100.00% of C++ online submissions for Longest Substring Without Repeating Characters.
*/

int lengthOfLongestSubstring(string s) {
	int maxLen = 0, prevMaxLen = 0, prevIndexOf[128] = { 0 };
	for (int i = 0; i < s.length(); i++) {
		int curMaxLen = min(prevMaxLen, i - prevIndexOf[s[i]]) + 1;
		prevIndexOf[s[i]] = i + 1;

		if (curMaxLen > maxLen) {
			maxLen = curMaxLen;
		}
		prevMaxLen = curMaxLen;
	}
	return maxLen;
}