// ���� ��� ����

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>

using namespace std;

int N;

int main(void) {
	int arr[100];
	queue<int> radix[10]; // �ڸ����� ���� ť �迭
	
	scanf("%d", &N);
	for (int i = 0;i < N;i++) {
		scanf("%d", &arr[i]);
	}

	int max = arr[0];
	int d = 1; // �ִ��ڸ���
			   // �ִ� �ڸ����� ���ϱ� ���ؼ� �ִ��� ã�Ƴ���.
	for (int i = 1; i < N; i++)
		if (max < arr[i]) max = arr[i];

	// �ִ� �ڸ����� ���س���.
	while (max / 10) {
		d *= 10;
		max /= 10;
	}

	int mod = 10;
	int dMin = 1;

	while (dMin <= d) {
		for (int i = 0; i < N; i++) {
			radix[(arr[i] % mod) / dMin].push(arr[i]);
			// Ư�� �ڸ��� ���ڸ� ������ �׿� �ش��ϴ� ��ġ�� �����͸� push
		}

		// ť�� �� ������ �ڸ��� ũ�� ������ �ٽ� �迭�� ����ִ´�.
		int j = 0;
		for (int i = 0;i <= 9;i++) {
			while (radix[i].size() > 0) {
				arr[j++] = radix[i].front();
				radix[i].pop();
			}
		}

		// �ϳ� �� ���� �ڸ����� �̵�
		dMin *= 10;
		mod *= 10;

	}

	for (int i = 0; i < N; i++) printf("%3d ", arr[i]);

	return 0;
}