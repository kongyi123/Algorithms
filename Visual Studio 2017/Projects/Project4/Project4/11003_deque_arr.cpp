// 11003_deque Æ©´×

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

vector<pair<int, int >> q(5000001); // idx, val

int N, L;
int dat[5000001];

int main(void) {
	scanf("%d%d", &N, &L);
	for (int i = 1;i <= N;i++) {
		scanf("%d", &dat[i]);
	}

	int head, tail;
	head = tail = 0;
	for (int i = 1;i <= N;i++) {
		if (head < tail) {
			if (i - q[head].first >= L) head ++;
		}

		while (head < tail) {
			if (q[tail-1].second >= dat[i]) tail--;
			else break;
		}

		q[tail++] = pair<int, int>(i, dat[i]);

		printf("%d ", q[head].second);
	}


	return 0;
}