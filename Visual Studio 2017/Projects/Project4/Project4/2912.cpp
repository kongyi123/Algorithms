// 양심적으로 세그먼트트리 잘 모르고 있다.
// lazy propagation도 엄청 듣고 있는데 외면하고 있다.
// 그걸 먼저 이해하고 이 문제를 풀자.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cmath>
#include <vector>
#define FIRST 0
#define SECOND 1

using namespace std;

int M;
int N, C;
int dat[300002];


struct Unit {
	int num;
	int cnt;
	Unit() {
		num = cnt = 0;
	}
};

struct Node {
	Unit arr[2];
};

Node tree[1 << 20];
vector<Unit> temp;

Node arrange(vector<Unit> & temp, int n) {
	for (int i = 0;i < temp.size();i++) {
		for (int j = i + 1;j < temp.size();j++) {
			if (temp[i].num == temp[j].num) {
				temp[i].cnt += temp[j].cnt;
			}
		}
	}

	Node t;
	int cnt = 0;
	int max_cnt = 0;
	int max_num;
	for (int i = 0;i < temp.size();i++) {
		if (max_cnt < temp[i].cnt) {
			max_cnt = temp[i].cnt;
			max_num = temp[i].num;
		}
	}
	if (max_cnt >= n / 2) {
		t.arr[cnt].cnt = max_cnt;
		t.arr[cnt].num = max_num;
		cnt++;
	}

	for (int i = 0;i < temp.size();i++) {
		if (t.arr[0].num == temp[i].num) continue;
		if (max_cnt < temp[i].cnt) {
			max_cnt = temp[i].cnt;
			max_num = temp[i].num;
		}
	}
	if (max_cnt >= n / 2) {
		t.arr[cnt].cnt = max_cnt;
		t.arr[cnt].num = max_num;
	}

	return t;
}

Node init(int node, int start, int end) {
	if (start == end) {
		tree[node].arr[FIRST].num = dat[start];
		tree[node].arr[FIRST].cnt = 1;
		return tree[node];
	}
	else {
		Node t1 = init(node * 2, start, (start + end) / 2);
		Node t2 = init(node * 2 + 1, (start + end) / 2 + 1, end);
		temp.push_back(t1.arr[FIRST]); temp.push_back(t1.arr[SECOND]);
		temp.push_back(t2.arr[FIRST]); temp.push_back(t2.arr[SECOND]);
		return tree[node] = arrange(temp, end-start+1);
	}
}

int main(void) {
	scanf("%d%d", &N, &C);
	for (int i = 1;i <= N;i++) {
		scanf("%d", &dat[i]);
	}
	init(1, 1, N);


	scanf("%d", &M);
	for (int i = 1;i <= M;i++) {
		int a, b;
		scanf("%d%d", &a, &b);


		int t = -1;
		if (t == -1) printf("no\n");
		else printf("yes %d\n", t);
	}
	return 0;
}