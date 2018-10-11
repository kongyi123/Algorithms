// queue_x�� ��������� �ۼ��ϸ� 
// Queue ����ü�� �´��� ä������.

#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <stdio.h>
#include "queue_b.h"

Queue<int> q;
int n;

int main(void) {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 1;i <= n;i++) {
		int a, b, idx;
		scanf("%d", &a);
		switch (a) {
		case 0:	// �ڿ� �߰�
			scanf("%d", &b);
			q.push(b);
			break;
		case 1: // �տ� pop
				//			printf("%d\n", q.front());
			break;

		case 2: // �տ� ����
			q.pop(0);
			break;

		case 3: // idx�� �߰�
			scanf("%d %d", &idx, &b);
			q.push(idx, b);

			break;
		case 4: // idx�� �ִ� �� ����
			scanf("%d", &idx);
			q.pop(idx);

			break;
		}

		//		printf("��� "); q.print();
	}

	int dcheck[] = { 20, 1, 2, 3, 4, 5 };
	int cnt = 0;
	while (q.front()) {
		if (q.front() == dcheck[cnt]) {
			cnt++;
		}
		q.pop(0);
	}

	if (cnt == 6) printf("Accepted!\n");
	else printf("��\n");
	_getch();
	return 0;
}