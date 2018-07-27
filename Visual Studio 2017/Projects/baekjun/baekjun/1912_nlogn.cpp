// nlogn
// ���ҿ� ����. ��, ��������. �߿��ѱ���̴�.
// �߰�, ���� ���, ������� ���� ��
// �ִ뿬�� �κ����̱� ������ �߰��� ���� �����ϴ� ����� ������ ����

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MIN -2000000000

int data[110000];

int n;

int max(int a, int b) {
	if (a > b) return a;
	return b;
}

int fastMaxSum(int s, int e) {
	if (s <= e) {

		if (s == e) return data[s];

		int mid = (s + e) / 2;

		int left = MIN, right = MIN, sum = 0;
		for (int i = mid;i >= s;i--) {
			sum += data[i];
			if (left < sum) left = sum;
		}

		sum = 0;
		for (int i = mid + 1;i <= e;i++) {
			sum += data[i];
			if (right < sum) right = sum;
		}

		int single = max(fastMaxSum(1, mid), fastMaxSum(mid + 1, e));
		return max(single, left + right);
	}
}



int main(void) {
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		fscanf(stdin, "%d", &data[i]);
	}

	int result = fastMaxSum(1, n);

	fprintf(stdout, "%d", result);
	return 0;
}