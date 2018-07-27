// �̺� ��Ī ��ǥ �ڵ�
// ���� �˰����� �������ε� �� �� ������.
// �ڵ�� �׸��� Ȥ�� ��Ʈ��ŷ�� �� ������. (KAIST MOCK ACM 2017�� A���� ������ ����)
// -> �� ������ �̿��ؼ� KIAST MOCK ACM 2017 A�� ������ Ǯ� ��.

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
vector<vector<int>> g;	// 2���� ���� (���� ����Ʈ)
int ck[2001]; 
int b[2001];

bool dfs(int cur) {
	ck[cur] = 1;
	for (auto &p : g[cur]) { // ���� ����Ʈ�� ���켭 �ٷ� frontier ����
		if (b[p] == 0 || ck[b[p]] == 0 && dfs(b[p])) {
			// job�� �ƿ� ó������ ���� �޾Ұų�  || (�̹� ������ ���� �ٸ� ��θ� �� ã�� �� �ִٸ�(��, ������ üũ�� ��带 ����))
			// ��, ������ ��ο� �� �ٽ� ������ back���� �� ���ִ� ����
			b[p] = cur;
			return true;	// �� ���¿��� �� ��θ� ã�� �Ǹ� true
		}
	}
	return false;			// �� ���¿��� �� ��θ� ã�� ���ϸ� false
}

int main() {
	int n, m, ans = 0;
	scanf("%d%d", &n, &m);
	g.resize(2 * n + 1);				// ���� ����Ʈ ����
	for (int i = 1, a; i <= n; i++) {
		scanf("%d", &a);
		for (int j = 0, b; j < a; j++) {
			scanf("%d", &b);
			g[i].push_back(b);			// 1�� ���� ��Ī�� ��  �뷮�� ������ �ø��°� �ƴ϶�, ���� ��� �߰��� ������ �÷��ִ� �ɷ� ����Ѵ�.
			g[i + n].push_back(b);		// �ֳĸ� ��Ī�����̱� ����
		}
	}

	for (int i = 1; i <= n * 2; i++) {
		if (dfs(i)) { // ��θ� ã�� �� ������ ī���� ���ָ鼭 ��� �����ϵ��� ����� �ִ� ������ �ڵ�
			memset(ck, 0, sizeof(ck));
			ans++;
		}
	}
	
	printf("%d\n", ans);
	return 0;

}

