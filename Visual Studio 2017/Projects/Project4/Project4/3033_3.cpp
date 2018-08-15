#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <queue>
#define MAX 200000

using namespace std;

const int MOD = 100003;

inline int mod(long long n) {
	if (n >= 0) return n % MOD; // long long 범위 안에 드는 경우
	return ((-n / MOD + 1)*MOD + n) % MOD;
	//	return n % MOD;
}

int L;
char S[MAX + 10];

queue<int> hashtable[MOD];

int eval(int length) {
	for (int i = 0;i < MOD;i++) {
		while (!hashtable[i].empty()) hashtable[i].pop();
	}

	int sum = 0;
	int t = 1;
	for (int j = 1;j <= length;j++) {
		sum = mod(sum + 1LL * (S[length - j + 1]) * t);
		if (j == length) break;
		t = mod(t * 2);
	}

	hashtable[sum].push(0);

	for (int i = length + 1;i <= L;i++) {
		sum = mod(2 * (sum - 1LL * (S[i - length]) * t) + (S[i]));

		//		if (pr.second == false) { // 겹치는게 있다는 거... 그럼 진짜 확인해봐야겠지
		if (!hashtable[sum].empty()) {
			int size = hashtable[sum].size();
			for (int k = 0;k < size;k++) {
				int differ = 0;
				int t = hashtable[sum].front();
				hashtable[sum].pop();
				for (int j = 0;j < length;j++) {
					if (S[t + j] != S[i - length + 1 + j]) {
						differ = 1;
						break;
					}
				}
				hashtable[sum].push(t);

				if (differ == 0) return 1;
			}
		}

		hashtable[sum].push(i - length + 1);

	}

	return 0;
}

int process() {
	int max = 0;
	int s = 1, e = L;
	int flag = 0;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (eval(mid) == 1) {
			flag = 1;
			if (max < mid) max = mid;
			s = mid + 1;
		}
		else e = mid - 1;
	}

	if (flag == 0) return 0;
	return max;
}


int main(void) {
	int T;
	//	freopen("input.txt", "r", stdin);
	//	scanf("%d", &T);
	T = 1;
	for (int tc = 1;tc <= T;tc++) {
		scanf("%d", &L);
		scanf("%s", &S[1]);
		//		printf("#%d %d\n", tc, process());
		printf("%d", process());
	}
	return 0;
}