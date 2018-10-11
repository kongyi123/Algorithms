// queue_x의 헤더파일을 작성하면 
// Queue 구조체가 맞는지 채점해줌.

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
		case 0:	// 뒤에 추가
			scanf("%d", &b);
			q.push(b);
			break;
		case 1: // 앞에 pop
				//			printf("%d\n", q.front());
			break;

		case 2: // 앞에 삭제
			q.pop(0);
			break;

		case 3: // idx에 추가
			scanf("%d %d", &idx, &b);
			q.push(idx, b);

			break;
		case 4: // idx에 있는 것 삭제
			scanf("%d", &idx);
			q.pop(idx);

			break;
		}

		//		printf("출력 "); q.print();
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
	else printf("뻑\n");
	_getch();
	return 0;
}