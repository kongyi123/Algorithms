// 13�� + alpha
// �̺а˻��� �� ������ �Ǵ� �� != �츮�� ���ϰ��� �ϴ� ��

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int data[11000];
int n, m;

int eval(int limit) {
	int sum = 0;
	int max = 0;
	for (int i = 1;i <= n;i++) {
		if (limit > data[i]) {
			sum += data[i];
			if (max < data[i])
				max = data[i];
		}
		else {
			sum += limit;
			if (max < limit) 
				max = limit;
		}
	}

	if (sum > m) return -1;	// ���� �Ұ� ����
	return max;	// ������ ����� �� �ִ밪�� ����
}

int main(void) {
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		fscanf(stdin, "%d", &data[i]);
	}
	fscanf(stdin, "%d", &m);

	int s = 1, e = 100000;
	int result;
	int ans = 0;

	// �ε��� ���õȰ� �̷��� �ص� �Ǵµ�
	// � ���� ������ ���� �̺а˻��� while ���ǹ��� = �� ����
	// ������� 1 ���� ��쿡 mid ���� ������ �� ���� ���� ��.
	while (s <= e) {
		int mid = (s + e + 1) / 2;
		if ((result = eval(mid)) != -1) {	
			if (ans < result) ans = result;				
			s = mid;
			if (s == e) break;
		}
		else {
			e = mid - 1;
		}
	}

	fprintf(stdout, "%d", ans);
	return 0;
}