// 코드가 이렇게 짧아질수도 있구나...

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
//#include <map>
#include <unordered_map> // hash map

// map : treeMap
// unordered_map : hashMap
using namespace std;

int max(int a, int b) {
	if (a > b) return a;
	return b;
}

class Solution {
public:
	int longestConsecutive(vector<int>& num) {
		unordered_map<int, int> m;
		int r = 0;
		for (int i : num) {
			if (m[i]) continue;
			r = max(r, m[i] = m[i + m[i + 1]] = m[i - m[i - 1]] = m[i + 1] + m[i - 1] + 1);
		}
		return r;
	}
};