// 최소 heap : 모든 기준 노드의 값이, 그 노드의 자식노드보다 작아야 한다.

// 오름차순으로 정렬하려면 오히려 최대힙을 이용하여 가장 큰것부터 뽑아내어  기본 배열의 마지막으로 stack한다.
// 시간 : 11분

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define IN in
#define OUT out
#define MAX 1000010

FILE *in = fopen("input.txt", "r");
FILE *out = fopen("output.txt", "w");

int heap[MAX], hcnt = 0;

void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}

void heap_add(int m) {
	hcnt++;
	heap[hcnt] = m;							// 데이터를 입력받은 족족 i번째 idx에 넣는다.
	for (int j = hcnt; j > 1; j = j >> 1) {	// 그것을 즉시 부모 노드에 따라가게 하여 
		if (heap[j] < heap[j >> 1]) {		// 만약 부모노드보다 현재 입력된게 더 크면 교환 (최소힙)
			swap(heap[j], heap[j >> 1]);
		}
	}
}

int heap_pop() {
	swap(heap[1], heap[hcnt]);			// root항을 지우는 대신에, 현재 정렬해야 하는 남은 구성 요소의 수 번째 idx에 넣어줌 (swap)	
	for (int j = 1; ; ) {					// 이제 자식과 비교해서 더 작은것과 교환 과정 반복
		int k = j << 1;
		if (k > hcnt) break;				// 자식의 인덱스가 남은 구성요소 수 초과하면 중단
		if (k + 1 <= hcnt && heap[k] < heap[k + 1]) k++; // 오른 자식이 고려 대상이고  오른자식이 왼자식 보다 크면  k(idx)를 오른 자식으로
		if (heap[j] < heap[k]) {			// 기준 노드가 자식 노드의 값보다 작으면
			swap(heap[j], heap[k]);			// 교환
			j = k;
		}
		else break;
	}
	hcnt--;
	return heap[hcnt+1];
}

int main()
{
	int t;
	int n;
	fscanf(IN, "%d", &n);

	// 힙 구현
	for (int i = 1; i <= n; i++) {
		int m;
		fscanf(IN, "%d", &m);
		heap_add(m);
	}

	// 출력
	for (int i = 1; i <= n; i++) {
		fprintf(OUT, "%d\n", heap_pop());
	}

	return 0;
}
