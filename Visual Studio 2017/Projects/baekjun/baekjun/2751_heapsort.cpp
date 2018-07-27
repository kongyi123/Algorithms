// �ּ� heap : ��� ���� ����� ����, �� ����� �ڽĳ�庸�� �۾ƾ� �Ѵ�.


// ������������ �����Ϸ��� ������ �ִ����� �̿��Ͽ� ���� ū�ͺ��� �̾Ƴ���  �⺻ �迭�� ���������� stack�Ѵ�.


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define IN in
#define OUT out
#define MAX 1000010

FILE *in = fopen("input.txt", "r");
FILE *out = fopen("output.txt", "w");

int heap[MAX];

void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}

int main()
{
	int t;
	int n;
	fscanf(IN, "%d", &n);

	// �� ����
	for (int i = 1; i <= n; i++) {
		int m;
		fscanf(IN, "%d", &m);
		heap[i] = m;							// �����͸� �Է¹��� ���� i��° idx�� �ִ´�.
		for (int j = i; j > 1; j = j >> 1) {	// �װ��� ��� �θ� ��忡 ���󰡰� �Ͽ� 
			if (heap[j] > heap[j >> 1]) {		// ���� �θ��庸�� ���� �ԷµȰ� �� ũ�� ��ȯ (�ִ���)
				swap(heap[j], heap[j >> 1]);
			}
		}
	}

	// ����
	for (int i = 1; i <= n; i++) {
		swap(heap[1], heap[n - i + 1]);			// root���� ����� ��ſ�, ���� �����ؾ� �ϴ� ���� ���� ����� �� ��° idx�� �־��� (swap)	
		for (int j = 1; ; ) {					// ���� �ڽİ� ���ؼ� �� �����Ͱ� ��ȯ ���� �ݺ�
			int k = j << 1;
			if (k > n - i) break;				// �ڽ��� �ε����� ���� ������� �� �ʰ��ϸ� �ߴ�
			if (k + 1 <= n - i && heap[k] < heap[k + 1]) k++; // ���� �ڽ��� ��� ����̰�  �����ڽ��� ���ڽ� ���� ũ��  k(idx)�� ���� �ڽ�����
			if (heap[j] < heap[k]) {			// ���� ��尡 �ڽ� ����� ������ ������
				swap(heap[j], heap[k]);			// ��ȯ
				j = k;
			}
			else break;
		}

	}

	// ���
	for (int i = 1; i <= n; i++) {
		fprintf(OUT, "%d\n", heap[i]);
	}

	return 0;
}
