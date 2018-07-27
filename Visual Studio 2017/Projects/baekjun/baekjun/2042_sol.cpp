// �˰��� : ���� Ʈ��
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>

using namespace std;

long long sum(vector<long long> &tree, int i) {
	long long ans = 0;
	while (i > 0) {
		ans += tree[i];			
		i -= (i & -i);			// ���� ���� �ڸ��� �̺� ������ ���� �ϳ��� ������ ���� ���Ѵ�.
	}
	return ans;
}

void update(vector<long long> &tree, int i, long long diff) {
	while (i < tree.size()) {
		tree[i] += diff;		// �����ִµ�
		i += (i & -i);			// �ڽ��� �̺� ������ �����ش�. 
	}
}

int main() {
	int n, m, k;
	
	scanf("%d %d %d", &n, &m, &k);		// N : ������ ��
	vector<long long> a(n + 1);			// M : ���� ������ �Ͼ�� Ƚ��
	vector<long long> tree(n + 1);		// K : ������ ���� ���ϴ� Ƚ��
	
	for (int i = 1; i <= n; i++) {		// ������ �Է�
		scanf("%lld", &a[i]);
		update(tree, i, a[i]);			// Ʈ���� ������Ʈ
										// tree��� ���Ϳ� i��° �����Ϳ� �ش��ϴ� �κе鿡 a[i]��ŭ �����ش�.
	}

	m += k;
	while (m--) {
		int t1;
		scanf("%d", &t1);				// �Է� ����
		if (t1 == 1) {					// ������ 1�� ��� => t2��° ���� t3���� ����
			int t2;
			long long t3;
			scanf("%d %lld", &t2, &t3); 
			long long diff = t3 - a[t2];	// t2��° �����ٰ� diff��ŭ ���� ���� ���� �༭ t3���� �����.
			a[t2] = t3;						// �������� val���� ���������� ���� �ʴ´�.
			update(tree, t2, diff);			// ���� ������Ʈ
		}
		else {
			int t2, t3;
			scanf("%d %d", &t2, &t3);	// ������ 2�� �ܿ� => t2 ���� t3 ��°�� �ش��ϴ� ������ ���� ���
			printf("%lld\n", sum(tree, t3) - sum(tree, t2 - 1));
		}
	}
	return 0;
}