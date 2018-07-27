// �̺� �˻��� ������ ���ǵ��� �ִ�. �����ϰ� ���� ����.
// 1. ���� ���ؾ� �ϴ� ��.
// 2. � ������ �Ǵ� ��.
// 1,2���� �ٸ� ��쵵 �ְ� ���� ��쵵 �ִ�. �� ���� ���� ���� �ٸ���.

// 46�� �ɸ�

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int data[11000];

int n, m;

int check(int limit) { // rest�� ���� ���ϸ� ���Ѿ��� �ٿ��� �Ѵ�.
					   // rest�� ����� �����ϸ�  
	int rest = m;
	int max = 0;
	for (int i = 1;i <= n;i++) {
		if (data[i] <= limit) {
			rest -= data[i];
			if (max < data[i]) max = data[i];
		}
		else {
			rest -= limit;
			if (max < limit) max = limit;
		}
		if (rest < 0) return -1;
	}
	return max;
}

int main(void) {
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		fscanf(stdin, "%d", &data[i]);
	}
	fscanf(stdin, "%d", &m);

	int max = 0;
	int s = 1, e = 1000000000;
	while (s <= e) {
		int mid = (s + e) / 2;
		int result;
		if ((result = check(mid)) != -1) {
			if (max < result) max = result;
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}

	
	fprintf(stdout, "%d", max);

	return 0;
}