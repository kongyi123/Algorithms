#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
const int MOD = 100003;

inline int mod(long long n) {
	if (n >= 0) return n % MOD;
	return ((-n / MOD + 1)*MOD + n) % MOD; 
	// MOD 기준으로 몫을 하나 더 큰걸로 복구해서 다시 % 계산을 해준다.
	// 한마디로 음수 % 연산을 시행해줌.
}

int main() {
	int L;
	char W[200001];
	scanf("%d %s", &L, W);

	int lo = 0, hi = L; // lo: 가능, hi: 불가능
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;

		int H = 0, power = 1;
		vector<int> pos[MOD]; // pos[i]: 해시값이 i인 부분 문자열의 등장 위치들
		bool found = false;

		// 가능한 모든 위치에서 길이 mid인 부분 문자열들의 해시값을 구해 보며 처리
		for (int i = 0; i <= L - mid; i++) {
			if (i == 0) {
				for (int j = 0; j<mid; j++) {
					H = mod(H + 1LL * W[mid - 1 - j] * power);
					if (j < mid - 1) power = mod(power * 2);
				}
			}
			else H = mod(2 * (H - 1LL * W[i - 1] * power) + W[i + mid - 1]);

			// 해시값 충돌이 일어남
			if (!pos[H].empty()) {
				// 같은 문자열이 앞서 등장했는지 모두 비교
				for (int p : pos[H]) {
					bool same = true;
					for (int j = 0; j<mid; j++) {
						if (W[i + j] != W[p + j]) {
							same = false;
							break;
						}
					}
					// 동일한 부분 문자열이 등장했음
					if (same) {
						found = true;
						break;
					}
				}
			}
			if (found) break; // 찾음
			else pos[H].push_back(i); // 찾지 못함: 루프 계속
		}

		// 길이 mid인 부분 문자열이 2번 등장했느냐에 따라 상하값 조절
		(found ? lo : hi) = mid;
	}
	printf("%d\n", lo);
}