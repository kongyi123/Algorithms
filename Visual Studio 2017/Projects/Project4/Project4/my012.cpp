// 못풀겠음

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

using namespace std;

bool check[32769][201];
bool check2[32769][201];

int dat[40000];
int n, m;

void update(int i, int x) {
	int cur = i;
	while (cur <= n) {
		check[cur][x] = 1;
		cur += (cur & -cur);
	}

	cur = i - 1;
	while (cur > 0) {
		check2[cur][x] = 1;
		cur -= (cur & -cur);
	}
}

int query(int a, int b) {
	int cur = a - 1;
	int next = (cur & -cur);
	while (next-1 <= b-1) {
		
		cur = next;
		next += (next & -next);
	}
	return 0;
}

int main(void) {
	freopen("input.txt", "r", stdin);
	printf("%d\n", sizeof(short));
	printf("%d\n", sizeof(char));

	printf("%d", sizeof(int));
	scanf("%d", &n);
	for (int i = 1;i <= n;i++) {
		scanf("%d", &dat[i]);
	
	}
	scanf("%d", &m);
	for (int i = 1;i <= m;i++) {
		int p, q;
		scanf("%d %d", &p, &q);
	}
	return 0;
}