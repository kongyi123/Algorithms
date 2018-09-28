
#define _CRT_SECURE_NO_WARNINGS
#define DEBUG 0
#if DEBUG
#include <conio.h>
#endif


#include <stdio.h>
#include <stack>

using namespace std;

stack<int> st;
int N;
int dat[100010];

long long process() {
	long long max = 0, t; // <- ÀÌ³ðÀÇ t....
	int last;
	while (!st.empty()) st.pop(); // clear
	st.push(0);
	for (int i = 1;i <= N + 1;i++) {
		if (dat[i] >= dat[st.top()])
			st.push(i);
		else {
			while (dat[i] < dat[st.top()]) {
				t = (long long)dat[st.top()] * (i - st.top());
				if (max < t) max = t;
				last = st.top();
				st.pop();
			}
			dat[last] = dat[i];
			st.push(last);
		}
	}


	return max;
}

int main(void) {
#if DEBUG
	freopen("input.txt", "r", stdin);
#endif
	while (1) {
		scanf("%d", &N);
		if (N == 0) break;

		for (int i = 1;i <= N;i++) {
			scanf("%d", &dat[i]);
		}
		dat[N + 1] = 0;

		printf("%lld\n", process());
	}
#if DEBUG
	_getch();
#endif
	return 0;
}