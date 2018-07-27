#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 101
#define INPUT in
#define OUTPUT out

FILE *in = fopen("input.txt", "r");
FILE *out = fopen("output.txt", "w");

typedef struct network_edge {		// 간선 typedef
	int to, capacity, flow;			
	struct network_edge* residual_edge;	// 잔여간선
} network_edge;

typedef struct node {
	struct node* next;
	struct network_edge* edge;
} node;

network_edge* make_edge(int to, int capacity, int flow);
void add_edge(int from, int to, int capacity);
int back(int cur, int addible_flow);

int min(int a, int b) {
	return a < b ? a : b;
}

node* adj[MAX];
int src, sink, chk[MAX];

int main() {
	int v, e;
	fscanf(INPUT, "%d %d", &v, &e);		// vertex(정점)의 수, edge(간성)의 수
	for (int i = 1;i <= v;i++) {		// 노드 수만큼 반복하면서 노드를 만든다.
		adj[i] = (node*)malloc(sizeof(node));	// malloc
		adj[i]->next = NULL;					
	}

	fscanf(INPUT, "%d %d", &src, &sink);		// 시작점, 도착점

	for (int i = 0;i < e;i++) {
		int from, to, capacity;
		fscanf(INPUT, "%d %d %d", &from, &to, &capacity);		// 인접 리스트 입력
		add_edge(from, to, capacity);
	}
	int ans = 0, added_flow;
	while (added_flow = back(src, 101)) {		// sink까지의 경로가 발견 되지 않을 때 까지
		ans += added_flow;							// 발견 경로의 유량 
		for (int i = 1; i <= v; i++) {				// 체크 배열 초기화 
			chk[i] = 0;
		}
	}

	fprintf(OUTPUT, "%d\n", ans);
	return 0;
}

network_edge* make_edge(int to, int capacity, int flow) {	// 방향성 간선인데 성분(방향 : 노드, 용량, 유량) 을 갖고 있다.
	network_edge* edge = (network_edge*)malloc(sizeof(network_edge));
	edge->to = to;
	edge->capacity = capacity;
	edge->flow = flow;
	return edge;
}

void add_edge(int from, int to, int capacity) {		// 인접 리스트에 입력받은  간선 데이터 추가
	node* actual = (node*)malloc(sizeof(node));		// 진짜 노드?
	node* residual = (node*)malloc(sizeof(node));	// 잔여 노드?

	actual->edge = make_edge(to, capacity, 0);		// 진짜 간선 생성
	residual->edge = make_edge(from, 0, 0);			// 잔여 간선 생성
	
	actual->edge->residual_edge = residual->edge;	// 진짜 간선의 반려 = 잔여
	residual->edge->residual_edge = actual->edge;	// 잔여 간선의 반려 = 진짜

	
													// 생성한 노드(메모리)를 
													// adj[]가 지칭하는 자리의 첫번째 자리에 끼워 넣는다. 
	actual->next = adj[from]->next;					// 진짜 노드의 다음 = 순번 
	adj[from]->next = actual;
	residual->next = adj[to]->next;
	adj[to]->next = residual;
}

int back(int cur, int addible_flow) {
	if (cur == sink) return addible_flow;	// current == sink 면 가능 유량을 반환  => 이게 added를 통해서 최종 유량 반환값으로 전달됨
	chk[cur] = 1;	// 지나온 경로를 check

	for (node* current = adj[cur]->next; current != NULL; current = current->next) {	// 현재 current 노드에서 갈수있는 인접 노드가 전부 링크드 리스트화 되어 있는 것을 순회
		network_edge* edge = current->edge;	// 간선을 지칭하는 임시 변수 포인터 변수
		if (chk[edge->to] == 1 || edge->capacity - edge->flow == 0) continue; // 프론티어가 이미 거친 노드이거나 유량이 용량과 같아 져 있을 때 (즉, 가능한 최대 유량에 도달했을 때)  그 노드는 스킵

		int added = back(edge->to, min(addible_flow, edge->capacity - edge->flow)); // 현 노드를 시작점으로 가정하고 프론티어부터 sink 노드까지의 가능 경로를 찾고, 그에따른 유량을 반환 받는다.
		if (added) {	// 유량이 있다면 sink로 가는 path를 찾았다는 뜻이고
						// 현재 노드, 프론티어로 구성된 간선의 구성에 값을 갱신한다.
			edge->flow += added;		// 순방향 엣지의 유량에는 added만큼 추가 
			edge->residual_edge->flow -= added;	// 역방향 엣지의 유량에는 added만큼 감소
			return added;			// 
		}
	}
	return 0;						// sink 까지의 path가 발견 되지 않으면 유량 0 return
}


