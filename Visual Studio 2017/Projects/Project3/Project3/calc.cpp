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

		tree(4 * n, 987654321) {   //넉넉하게 4*n 사이즈 배열 생성, 초기값 지정

		size = 1;

		while (size < n) //2의 배수로 최저 깊이레벨 노드 개수 결정

			size *= 2;

		for (int i = 0; i < n; i++)

			tree[size + i] = arr[i];   //값 복사

		init(1);  //값들 다 계산.

	}

	/* 후라이빗 함수 */

	int init(int pos) {

		if (pos >= size) //단말 노드일 경우

			return tree[pos];

		return tree[pos] = min(init(pos * 2), init(pos * 2 + 1));

	}

	int query(int left, int right, int node, int nodeLeft, int nodeRight) {

		left = max(left, nodeLeft);

		right = min(right, nodeRight);

		if (left > right)

			return 987654321;   //초기값

		if (left == nodeLeft && right == nodeRight)

			return tree[node];

		int mid = (nodeLeft + nodeRight) / 2;

		return min(query(left, right, node * 2, nodeLeft, mid),

			query(left, right, node * 2 + 1, mid + 1, nodeRight));

	}



	void update(int pos) {

		if (pos < 1)

			return;   //루트까지만

		tree[pos] = min(tree[pos * 2], tree[pos * 2 + 1]);   //갱신

		update(pos / 2);   //부모 노드 따라 계속 올라감

	}



	/* 사용시 직접 호출할 함수 */

	int query(int left, int right) {  //left~right 사이의 대표값

		return query(left, right, 1, 0, size - 1);

	}

	void update(int index, int newValue) {   //index번 노드 값을 갱신

		tree[size + index] = newValue; //해당 노드 업데이트

		update((size + index) / 2); //부모 노드 재귀 업데이트

	}

};

