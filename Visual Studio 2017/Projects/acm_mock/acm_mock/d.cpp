#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

using namespace std;

/*
* Time complexity: TODO
* Space complexity: TODO
*/

int parent[100010];
int check[100010];
int inp[100010];
int dcnt, data[100010];

class info {
public:
	int depth;
	int big_parent;
	int p;

	info(int t) {
		p = t;
	}

	void find() {
		int tdepth = 0;
		int tbig_parent = p;
		while (parent[tbig_parent] != 0) {
			tbig_parent = parent[tbig_parent];
			tdepth++;
		}

		depth = tdepth;
		big_parent = tbig_parent;
	}

	int get_depth() {
		return depth;
	}

	int get_parent() {
		return big_parent;
	}
};



int main(int argc, const char *argv[]) {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		info tx(x), ty(y);
		tx.find();
		ty.find();
		if (tx.get_depth() > ty.get_depth()) {
			parent[ty.get_parent()] = tx.get_parent();
		}
		else {
			parent[tx.get_parent()] = ty.get_parent();
		}


		inp[x] = inp[y] = 1;

	}

	for (int i = 1;i <= 10;i++) {
		if (inp[i] == 1) {
			info tx(i);
			tx.find();
			check[tx.get_parent()] = 1;
			//				printf("%d\n", tx.get_parent());
		}
	}

	int cnt = 0;
	for (int i = 1;i <= 10;i++) {
		if (check[i] != 0) cnt++;
	}

	printf("%d", cnt);
	return 0;
}
