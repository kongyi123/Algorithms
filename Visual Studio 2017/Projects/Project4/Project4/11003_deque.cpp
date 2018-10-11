// 32

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>

using namespace std;

deque<pair<int, int >> q; // idx, val

int N, L;
int dat[5000001];

int main(void) {
	scanf("%d%d", &N, &L);
	for (int i = 1;i <= N;i++) {
		scanf("%d", &dat[i]);
	}

	for (int i = 1;i <= N;i++) {
		if (!q.empty()) {
			if (i - q.front().first >= L) q.pop_front();
		}

		while (!q.empty()) {
			if (q.back().second >= dat[i]) q.pop_back();
			else break;
		}

		q.push_back(pair<int, int> (i, dat[i]));

		printf("%d ", q.front().second);
	}


	return 0;
}