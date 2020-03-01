#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

class Node {
public:
	int arr[27];
	Node() {}
	Node(int t) {
		for (int i = 0; i < 27; i++) arr[i] = t;
	}
	Node operator+(const Node t) {
		Node temp;
		for (int i = 0; i < 27; i++) {
			if (t.arr[i] == 1 || arr[i] == 1) {
				temp.arr[i] = 1;
			}
			else temp.arr[i] = 0;
		}
		return temp;
	}
};

int n, q;
char s[500000];
Node tree[500001];

void update(int i, char ch, int t) {
	while (i <= n) {
		tree[i].arr[ch-'a'] = t;
		i += (i & -i);
	}
}

Node sum(int i) {
	Node ans(0);
	while (i > 0) {
		ans = ans + tree[i];
		i -= (i & -i);
	}
	return ans;
}

int main(void) {
	scanf("%d", &n);
	scanf("%s", &s[1]);
	scanf("%d", &q);

	for (int i = 1; i <= n; i++) 
		update(i, s[i], 1);
	
	for (int i = 1; i <= q; i++) {
		int type, a, b;
		scanf("%d", &type);
		if (type == 2) {
			scanf("%d%d", &a, &b);
			int hap = 0;
			Node s1 = sum(a-1);
			//for (int i = 0; i < 27; i++) {
			//	printf("%d", s1.arr[i]);
			//}
			//printf("\n");
			Node s2 = sum(b);
			//for (int i = 0; i < 27; i++) {
			//	printf("%d", s2.arr[i]);
			//}
			//printf("\n");

			for (int i = 0; i < 27; i++) {
				hap += (s2.arr[i] - s1.arr[i]);
			}

			printf("%d\n", hap);
		}
		else {
			char ch;
			scanf("%d %c", &a, &ch);
			update(a, s[a], 0);
			s[a] = ch;
			update(a, ch, 1);
		}
	}
	return 0;
}