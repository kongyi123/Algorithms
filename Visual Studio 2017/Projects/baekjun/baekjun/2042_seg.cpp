// �ۼ� ��¥ : 2017.09.25
// �ɸ��ð� : 7��
// Ű���� : ���׸�Ʈ Ʈ�� ����Ǵ� �κ� ��, long long����

// shift�ϰ� ������ �Ҷ� ��ȣ�� �ؾ��Ѵ�. �׷��� ������ + ���� ���� �ϰԵ�!!

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

long long k;
long long tree[2100000];

int main(void) {
	long long n, m;
	fscanf(stdin, "%lld %lld %lld", &n, &m, &k);
	m += k;
	for (k = 1;k < n;k = k << 1);
	for (int i = k;i < k + n;i++) {
		fscanf(stdin, "%lld", &tree[i]);
	}
	
	for (int i = k - 1;i >= 1;i--) {
		tree[i] = tree[i << 1] + tree[(i << 1) + 1];
	}

	for (int i = 1;i <= m;i++) {
		long long a, b, c;
		fscanf(stdin, "%lld %lld %lld", &a, &b, &c);
		if (a == 1) {
			tree[k + b - 1] = c;
			int temp = (k + b - 1) >> 1;
			while (temp >= 1) {
				tree[temp] = tree[temp << 1] + tree[(temp << 1) + 1];
				temp = temp >> 1;
			}
		}
		else {
			int p, q;
			p = k + b - 1;
			q = k + c - 1;
			long long sum = 0;
			while (p <= q) {
				if (p % 2 == 1) sum += tree[p++];
				if (q % 2 == 0) sum += tree[q--];
				p = p >> 1;
				q = q >> 1;
			}
			fprintf(stdout, "%lld\n", sum);
		}
	}
	return 0;
}