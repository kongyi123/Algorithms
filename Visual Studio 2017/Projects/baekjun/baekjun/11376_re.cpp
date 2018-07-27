// �̺� ��Ī ��ǥ �ڵ�
// ���� �˰����� �������ε� �� �� ������.
// �ڵ�� �׸��� Ȥ�� ��Ʈ��ŷ�� �� ������. (KAIST MOCK ACM 2017�� A���� ������ ����)
// -> �� ������ �̿��ؼ� KIAST MOCK ACM 2017 A�� ������ Ǯ� ��.
// �̺� ��Ī�� �ð����⵵�� ����ϸ�??  V*E



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <memory.h>

using namespace std;

int n, m;
int rec[2100];
vector<int> adj[2100];
bool check[2100];

bool back(int cur) {
	check[cur] = 1;
	for (auto &next : adj[cur]) { // ���� ����Ʈ�� ���켭 �ٷ� frontier ����
		if (rec[next] == 0 || (check[rec[next]] == 0 && back(rec[next]))) {
			// job�� �ƿ� ó������ ���� �޾Ұų�  || (�̹� ������ ���� �ٸ� ��θ� �� ã�� �� �ִٸ�(��, ������ üũ�� ��带 ����))
			// ��, ������ ��ο� �� �ٽ� ������ back���� �� ���ִ� ����
			rec[next] = cur;
			return true;	// �� ���¿��� �� ��θ� ã�� �Ǹ� true
		}
	}
	return false;			// �� ���¿��� �� ��θ� ã�� ���ϸ� false
}

int main(void) {
	
	fscanf(stdin, "%d %d", &n, &m);
	for (int i = 1;i <= n;i++) {// ���� ����Ʈ ����
		int a, b;
		fscanf(stdin, "%d", &a);
		for (int j = 1;j <= a;j++) {
			fscanf(stdin, "%d", &b);
			adj[i].push_back(b);			// 1�� ���� ��Ī�� ��  �뷮�� ������ �ø��°� �ƴ϶�, ���� ��� �߰��� ������ �÷��ִ� �ɷ� 
			adj[i + n].push_back(b);		// �ֳĸ� ��Ī�����̱� ����
		}
	}

	int cnt = 0;
	for (int i = 1;i <= n*2;i++) {
		if (back(i)) {						// ��θ� ã�� �� ������ ī���� ���ָ鼭 ��� �����ϵ��� ����� �ִ� ������ �ڵ�
			memset(check, 0, sizeof(check));
			cnt++;
		}
	}

	fprintf(stdout, "%d", cnt);

	return 0;
}