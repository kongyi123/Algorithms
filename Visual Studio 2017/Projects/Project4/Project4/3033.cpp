#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
const int MOD = 100003;

inline int mod(long long n) {
	if (n >= 0) return n % MOD;
	return ((-n / MOD + 1)*MOD + n) % MOD; 
	// MOD �������� ���� �ϳ� �� ū�ɷ� �����ؼ� �ٽ� % ����� ���ش�.
	// �Ѹ���� ���� % ������ ��������.
}

int main() {
	int L;
	char W[200001];
	scanf("%d %s", &L, W);

	int lo = 0, hi = L; // lo: ����, hi: �Ұ���
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;

		int H = 0, power = 1;
		vector<int> pos[MOD]; // pos[i]: �ؽð��� i�� �κ� ���ڿ��� ���� ��ġ��
		bool found = false;

		// ������ ��� ��ġ���� ���� mid�� �κ� ���ڿ����� �ؽð��� ���� ���� ó��
		for (int i = 0; i <= L - mid; i++) {
			if (i == 0) {
				for (int j = 0; j<mid; j++) {
					H = mod(H + 1LL * W[mid - 1 - j] * power);
					if (j < mid - 1) power = mod(power * 2);
				}
			}
			else H = mod(2 * (H - 1LL * W[i - 1] * power) + W[i + mid - 1]);

			// �ؽð� �浹�� �Ͼ
			if (!pos[H].empty()) {
				// ���� ���ڿ��� �ռ� �����ߴ��� ��� ��
				for (int p : pos[H]) {
					bool same = true;
					for (int j = 0; j<mid; j++) {
						if (W[i + j] != W[p + j]) {
							same = false;
							break;
						}
					}
					// ������ �κ� ���ڿ��� ��������
					if (same) {
						found = true;
						break;
					}
				}
			}
			if (found) break; // ã��
			else pos[H].push_back(i); // ã�� ����: ���� ���
		}

		// ���� mid�� �κ� ���ڿ��� 2�� �����ߴ��Ŀ� ���� ���ϰ� ����
		(found ? lo : hi) = mid;
	}
	printf("%d\n", lo);
}