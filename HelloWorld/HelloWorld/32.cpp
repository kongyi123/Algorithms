// 다른 솔루션으로도 풀어보도록 한다.
// 1249번도 풀어볼것.

#include <string>

using namespace std;

class Solution {
public:
	int stack[5000] = { 0, };
	

	int longestValidParentheses(string s) {
		int state = 0;
		int cnt = 0;
		int max = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') {
				state++;
			}
			else {
				if (state > 0) {
					state--;
					stack[state] += stack[state + 1] + 2;
					stack[state + 1] = 0;
					if (max < stack[state])
						max = stack[state];
				}
				else {
					state = 0;
					stack[state] = 0;
				}
			}
		}
		return max;
	}
};

int main() {
	Solution sol;
	string s(")()())()()(");
//	string s("()(()");
	int val = sol.longestValidParentheses(s);
	printf("return = %d", val);
	return 0;
}