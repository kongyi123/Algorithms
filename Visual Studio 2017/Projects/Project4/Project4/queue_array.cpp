// 2018.08.29 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 1000

int arr[MAX]; //0���� �� ��
int size = 0;
int n;

void add(int val) {
	arr[size] = val;
	size++;
}

void add(int idx, int val) {
	for (int i = size;i >= idx + 1;i--) {
		arr[i] = arr[i - 1];
	}
	arr[idx] = val;
	size++;
}

void del(int idx) {
	for (int i = idx;i < size - 1;i++) {
		arr[i] = arr[i + 1];
	}
	size--;
}

void print() {
	for (int i = 0;i < size;i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int pop() {
	return arr[0];
}

int main(void) {
	scanf("%d", &n);
	for (int i = 1;i <= n;i++) {
		int a, b, idx;
		scanf("%d", &a);
		switch (a) {
		case 0:	// �ڿ� �߰�
			scanf("%d", &b);
			add(b);
			break;
		case 1: // �տ� pop
			printf("%d\n", pop());
			break;

		case 2: // �տ� ����
			del(0);
			break;

		case 3: // idx�� �߰�
			scanf("%d %d", &idx, &b);
			add(idx, b);

			break;
		case 4: // idx�� �ִ� �� ����
			scanf("%d", &idx);
			del(idx);

			break;
		}

		print();
	}
	return 0;
}