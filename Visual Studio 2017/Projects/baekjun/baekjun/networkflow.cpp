#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 101
#define INPUT in
#define OUTPUT out

FILE *in = fopen("input.txt", "r");
FILE *out = fopen("output.txt", "w");

typedef struct network_edge {		// ���� typedef
	int to, capacity, flow;			
	struct network_edge* residual_edge;	// �ܿ�����
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
	fscanf(INPUT, "%d %d", &v, &e);		// vertex(����)�� ��, edge(����)�� ��
	for (int i = 1;i <= v;i++) {		// ��� ����ŭ �ݺ��ϸ鼭 ��带 �����.
		adj[i] = (node*)malloc(sizeof(node));	// malloc
		adj[i]->next = NULL;					
	}

	fscanf(INPUT, "%d %d", &src, &sink);		// ������, ������

	for (int i = 0;i < e;i++) {
		int from, to, capacity;
		fscanf(INPUT, "%d %d %d", &from, &to, &capacity);		// ���� ����Ʈ �Է�
		add_edge(from, to, capacity);
	}
	int ans = 0, added_flow;
	while (added_flow = back(src, 101)) {		// sink������ ��ΰ� �߰� ���� ���� �� ����
		ans += added_flow;							// �߰� ����� ���� 
		for (int i = 1; i <= v; i++) {				// üũ �迭 �ʱ�ȭ 
			chk[i] = 0;
		}
	}

	fprintf(OUTPUT, "%d\n", ans);
	return 0;
}

network_edge* make_edge(int to, int capacity, int flow) {	// ���⼺ �����ε� ����(���� : ���, �뷮, ����) �� ���� �ִ�.
	network_edge* edge = (network_edge*)malloc(sizeof(network_edge));
	edge->to = to;
	edge->capacity = capacity;
	edge->flow = flow;
	return edge;
}

void add_edge(int from, int to, int capacity) {		// ���� ����Ʈ�� �Է¹���  ���� ������ �߰�
	node* actual = (node*)malloc(sizeof(node));		// ��¥ ���?
	node* residual = (node*)malloc(sizeof(node));	// �ܿ� ���?

	actual->edge = make_edge(to, capacity, 0);		// ��¥ ���� ����
	residual->edge = make_edge(from, 0, 0);			// �ܿ� ���� ����
	
	actual->edge->residual_edge = residual->edge;	// ��¥ ������ �ݷ� = �ܿ�
	residual->edge->residual_edge = actual->edge;	// �ܿ� ������ �ݷ� = ��¥

	
													// ������ ���(�޸�)�� 
													// adj[]�� ��Ī�ϴ� �ڸ��� ù��° �ڸ��� ���� �ִ´�. 
	actual->next = adj[from]->next;					// ��¥ ����� ���� = ���� 
	adj[from]->next = actual;
	residual->next = adj[to]->next;
	adj[to]->next = residual;
}

int back(int cur, int addible_flow) {
	if (cur == sink) return addible_flow;	// current == sink �� ���� ������ ��ȯ  => �̰� added�� ���ؼ� ���� ���� ��ȯ������ ���޵�
	chk[cur] = 1;	// ������ ��θ� check

	for (node* current = adj[cur]->next; current != NULL; current = current->next) {	// ���� current ��忡�� �����ִ� ���� ��尡 ���� ��ũ�� ����Ʈȭ �Ǿ� �ִ� ���� ��ȸ
		network_edge* edge = current->edge;	// ������ ��Ī�ϴ� �ӽ� ���� ������ ����
		if (chk[edge->to] == 1 || edge->capacity - edge->flow == 0) continue; // ����Ƽ� �̹� ��ģ ����̰ų� ������ �뷮�� ���� �� ���� �� (��, ������ �ִ� ������ �������� ��)  �� ���� ��ŵ

		int added = back(edge->to, min(addible_flow, edge->capacity - edge->flow)); // �� ��带 ���������� �����ϰ� ����Ƽ����� sink �������� ���� ��θ� ã��, �׿����� ������ ��ȯ �޴´�.
		if (added) {	// ������ �ִٸ� sink�� ���� path�� ã�Ҵٴ� ���̰�
						// ���� ���, ����Ƽ��� ������ ������ ������ ���� �����Ѵ�.
			edge->flow += added;		// ������ ������ �������� added��ŭ �߰� 
			edge->residual_edge->flow -= added;	// ������ ������ �������� added��ŭ ����
			return added;			// 
		}
	}
	return 0;						// sink ������ path�� �߰� ���� ������ ���� 0 return
}


