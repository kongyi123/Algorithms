#include <stdio.h>
#include <vector>

using namespace std;

int max(int a, int b) {
	if (a > b) return a;
	return b;
}

int min(int a, int b) {
	if (a > b) return b;
	return a;
}

struct IndexedTree {
	vector<int> tree;
	int size;
	IndexedTree(int n, int *arr) :

		tree(4 * n, 987654321) {   //�˳��ϰ� 4*n ������ �迭 ����, �ʱⰪ ����

		size = 1;

		while (size < n) //2�� ����� ���� ���̷��� ��� ���� ����

			size *= 2;

		for (int i = 0; i < n; i++)

			tree[size + i] = arr[i];   //�� ����

		init(1);  //���� �� ���.

	}

	/* �Ķ��̺� �Լ� */

	int init(int pos) {

		if (pos >= size) //�ܸ� ����� ���

			return tree[pos];

		return tree[pos] = min(init(pos * 2), init(pos * 2 + 1));

	}

	int query(int left, int right, int node, int nodeLeft, int nodeRight) {

		left = max(left, nodeLeft);

		right = min(right, nodeRight);

		if (left > right)

			return 987654321;   //�ʱⰪ

		if (left == nodeLeft && right == nodeRight)

			return tree[node];

		int mid = (nodeLeft + nodeRight) / 2;

		return min(query(left, right, node * 2, nodeLeft, mid),

			query(left, right, node * 2 + 1, mid + 1, nodeRight));

	}



	void update(int pos) {

		if (pos < 1)

			return;   //��Ʈ������

		tree[pos] = min(tree[pos * 2], tree[pos * 2 + 1]);   //����

		update(pos / 2);   //�θ� ��� ���� ��� �ö�

	}



	/* ���� ���� ȣ���� �Լ� */

	int query(int left, int right) {  //left~right ������ ��ǥ��

		return query(left, right, 1, 0, size - 1);

	}

	void update(int index, int newValue) {   //index�� ��� ���� ����

		tree[size + index] = newValue; //�ش� ��� ������Ʈ

		update((size + index) / 2); //�θ� ��� ��� ������Ʈ

	}

};

