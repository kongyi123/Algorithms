// ���� ���� Ǯ�̴�.. ������ �����ϵ�.
// �ϳ� ���� �Է¹��� ������ ���� ���� ���� �� �ϳ��� ���� ���.
// �׷��� heap������ N���� �����ϴ� �������.
// min-heap���� Ǭ��.
// �ϳ� ��� �ϳ� �Դ� �׸��� ������ �����̵� ������ �ΰ�. 
// �׸��� �׷��� ������ ��Ʈ�� �뷮??

// 19

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int heap[1501], hcnt;

void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}

int main(void) {

	int N;
	scanf("%d", &N);
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			int dat;
			scanf("%d", &dat);
			if (hcnt == N) {
				if (heap[1] < dat) {
					heap[1] = dat;
					int cur = 1;
					int temp, p;
					while (1) {
						temp = heap[cur]; p = cur;
						if (cur * 2 + 1 <= hcnt && temp > heap[cur * 2 + 1]) {
							temp = heap[cur * 2 + 1]; p = cur * 2 + 1;
						}
						if (cur * 2 <= hcnt && temp > heap[cur * 2]) {
							temp = heap[cur * 2]; p = cur * 2;
						}

						if (heap[cur] > temp) {
							swap(heap[cur], heap[p]);
							cur = p;
						}
						else break;
					}
				}
			}
			else {
				hcnt++;
				heap[hcnt] = dat;
				int cur = hcnt;
				while (1) {
					if (cur == 1) break;
					if (heap[cur] < heap[cur / 2]) {
						swap(heap[cur], heap[cur / 2]);
						cur = cur / 2;
					}
					else break;
				}
			}
		}
	}

	int min = 0x7fffffff;
	for (int i = 1;i <= hcnt;i++) {
		if (min > heap[i])
			min = heap[i];
	}

	printf("%d", min);

	return 0;
}