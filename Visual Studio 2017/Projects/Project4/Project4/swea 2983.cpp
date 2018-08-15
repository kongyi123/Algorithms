#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <vector>
#define MAX 200000
#define MOD 100003

using namespace std;

int L;
char S[MAX + 10];
vector<int> hashtable[MOD];

inline int mod(long long n) {
	while (n < 0) n += MOD;
	return n % MOD;
}

int eval(int length) {
	long long sum = 0;
	long long  t = 1;
	for (int j = 1;j <= length;j++) {
		sum = mod(sum + mod((long long)(S[length - j + 1]) * t));
		if (j == length) break;
		t = mod((long long)t * 2);
	}

	hashtable[sum].push_back(1);
	for (int i = length + 1;i <= L;i++) {
		sum = mod(mod(sum - (long long)(S[i - length])*t) * 2 + S[i]);
		if (!hashtable[sum].empty()) {
			for (int k = 0;k < hashtable[sum].size();k++) {
				int differ = 0;
				for (int j = 0;j < length;j++) {
					if (S[hashtable[sum].at(k) + j] != S[i - length + 1 + j]) {
						differ = 1;
						break;
					}
				}

				if (differ == 0) return 1;
			}
		}

		hashtable[sum].push_back(i - length + 1);

	}

	return 0;
}

int process() {
	int max = 0;
	int s = 1, e = L;
	int flag = 0;
	while (s <= e) {
		int mid = (s + e) / 2;
		for (int i = 0;i < MOD;i++) hashtable[i].clear();

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
	scanf("%d", &T);
	for (int tc = 1; tc <= T;tc++) {
		scanf("%d", &L);
		scanf("%s", &S[1]);
		printf("#%d %d\n", tc, process());
	}
	return 0;
}

