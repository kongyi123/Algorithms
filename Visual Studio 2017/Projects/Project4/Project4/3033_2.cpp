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
//		sum = mod(sum + mod((long long)(S[length - j + 1]) * t));
		int sum2 = sum;
		sum = mod(sum + mod((long long)(S[length - j + 1]) * t));
		if (j == length) break;
		t = mod((long long)t * 2);
	}

	hashtable[sum].push_back(1);
	/*
		문자열을 해싱하는 순서를 바꾸면 곱셈 누적으로 바로 다음 문자열 해싱값을 구하는게 가능.
		sum[1] = 2^4*S[1] + 2^3*S[2] + 2^2*S[3] + 2^1*S[4] + 1*S[5]
		sum[2] = 2^4*S[2] + 2^3*S[3] + 2^2*S[4] + 2^1*S[5] + 1*S[6]
			   = (sum[1] - 2^4*S[1]) * 2 + S[6]
	*/

//	printf("%d", -11 % 10);
	// sum[1] = 1*S[1] + 2*S[2] + 2^2*S[3] + 2^3*S[4] + 2^4*S[5]
	// sum[2] = 1*S[2] + 2*S[3] + 2^2*S[4] + 2^3*S[5] + 2^4*S[6]
	//		  = (sum-S[1])/2 + s^4*S[6]

	// 문자열 해싱 중에 곱하는 값인 t값이 너무 커지게 되면 누적변수를 오바해버리는 경우가 생김. 그렇게되면 해싱값이 키값에 대해 일관성 없는 결과가 나와버리게된다.
	// 즉, 결과적으로 모듈러 연산을 안했을 때는 a > b 라고 할지라도 a % MOD < b % MOD 를 만족하는 상황이 생길 수 있다는 것이다.
	// 이러한 경우에 a % MOD - b % MOD 는 음수 값이 나오게 되므로 mod함수에서 음수 모듈러 특수 처리를 해줘야 한다.
	// 간단하게 MOD를 증가 시켜 양수를 만든다음에 다시 % MOD 연산을 해주면 된다.
	// (% 연산자 자체가 양수 모듈러 연산을 제공하지 못한다. 그냥 단순하게 부호를 무시한 모듈러 처리가 되기 때문에 음수 %연산 관련 처리를 하는 mod함수를 직접 구현해줘야 한다.)

	// 나눗셈은 % 연산자와 교환법칙이 성립하지 않는다.
	for (int i = length + 1;i <= L;i++) {
//		sum = mod(2 * mod(sum - mod((long long)(S[i - length]) * t)) + (S[i]));
		sum = mod(mod(sum - (long long)(S[i - length])*t)*2 + S[i]);
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
	scanf("%d", &L);
	scanf("%s", &S[1]);
	printf("%d", process());
	return 0;
}

