#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[100];
int n;


int search(int s, int e, int val) {
	while (s < e) {
		int mid = (s + e) / 2; // mid = (s + e + 1) / 2 �� �Ǿ ����� ����. �ֳ��ϸ� ������ �������� �� mid��° ÷�ڴ� �����ϱ� �����̴�.
		if (val == arr[mid]) return mid;
		else if (val < arr[mid]) e = mid - 1;
		else s = mid + 1;
	}

	if (val == arr[s]) return s;
	return -1;
}

int upper_bound(int s, int e, int val) {
	while (s < e) { // �Ʒ� ���ǿ� ���� s,e ���� �˰��� �߿� e = mid�� �ִ�. ���� ������ ��Ȳ�� ���ֱ� ���� = �� ����.
		int mid = (s + e + 1) / 2;
		if (val == arr[mid]) s = mid + 1; // ���� �� val �� ������ ���̶�� �츮�� ã�� ���� �� ���ɼ��� ����. ���� mid ÷�ڴ� ����
		else if (val < arr[mid]) e = mid; // ���� �ָ��ϰ� �ִ� mid ÷�ڿ� �ִ� ���� �츮�� ã�� ���� ���� �ֱ� ������ e = mid - 1 �� �ƴ� e = mid �̴�.
		else s = mid + 1; // ���� �� val ���� ���� ���̶�� �츮�� ã�� ���� �� ���ɼ��� ����. ���� mid ÷�ڴ� ����       
	}
	if (s == n && arr[n] <= val) return n + 1;
	return s;
}


int main(void) {

	scanf("%d", &n);
	for (int i = 1;i <= n;i++) {
		scanf("%d", &arr[i]);
	}
	int val;
	while (1) {
		scanf("%d", &val);
		fprintf(stdout, "\ndap = %d\n\n", search(1, n, val));
//		fprintf(stdout, "\ndap = %d\n\n", upper_bound(1, n, val));
	}
	return 0;
}
