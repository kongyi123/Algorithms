#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int MOD = 1000000000;

// ��ȣ ������� ���� n�� �־����� ���� ������ ���� ���� ����
inline int mod(long long n) {
	if (n >= 0) return n % MOD;
	return ((-n / MOD + 1)*MOD + n) % MOD; // ������ ���
}

int main() {
	char W[1000001], S[1000001];
	int M, N;
	gets(S);
	gets(W);
	N = strlen(S);
	M = strlen(W);

	vector<int> result;
	int G = 0, H = 0, power = 1;
	for (int i = 0; i <= N - M; i++) {
		// W�� S ù ��ġ�� �ؽð��� ���
		if (i == 0) {
			for (int j = 0; j<M; j++) {
				G = mod(G + 1LL * W[M - 1 - j] * power);
				H = mod(H + 1LL * S[M - 1 - j] * power);
				if (j < M - 1) power = mod(power * 2);
			}
		}
		// �ƴ� ��� ���� ��ġ�� �ؽð��� ����� �̹� �ؽð��� ����
		else H = mod(2 * (H - 1LL * S[i - 1] * power) + S[i + M - 1]);

		// �ؽð��� ���ٸ� �ܼ� ��
		if (G == H) {
			bool same = true;
			for (int j = 0; j<M; j++) {
				if (S[i + j] != W[j]) {
					same = false;
					break;
				}
			}
			// �ܼ� ���ؼ� ���ڿ��� ã�Ҵٸ� ����� �߰�
			if (same) result.push_back(i + 1);
		}
	}

	// ��� ���
	printf("%d\n", result.size());
	for (int i : result)
		printf("%d ", i);
}