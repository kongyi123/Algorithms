// 작성 날짜 : 2017.09.25
// 걸린시간 : 
// 키워드 : 펜윅 트리, 변경되는 부분 합

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int n, m, k;

long long data[1010000];
long long tree[2100000];

void add(long long  index, long long val) {
	while (index <= n) {
		tree[index] += val;
		index = index + (index & -index);
	}
}

long long sum(long long index) {
	long long t = 0;
	while (index > 0) {
		t += tree[index];
		index = index - (index & -index);
	}
	return t;
}

int main(void) {
	fscanf(stdin, "%d %d %d", &n, &m, &k);
	for (int i = 1;i <= n;i++) {
		fscanf(stdin, "%lld", &data[i]);
		add(i, data[i]);
	}

	m += k;
	for (int i = 1;i <= m;i++) {
		long long a, b, c;
		fscanf(stdin, "%lld %lld %lld", &a, &b, &c);
		if (a == 1) {
			long long diff = c - data[b];
			add(b, diff);
			data[b] += diff;
		}
		else {
			fprintf(stdout, "%lld\n", sum(c) - sum(b - 1));
		}
	}
	return 0;
}