#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define INPUT stdin
#define OUTPUT stdout
#define MAX 2010

//FILE *in = fopen("input.txt", "r");
//FILE *out = fopen("output.txt", "w");

typedef struct network_edge {
	int to, capacity, flow;
	struct network_edge* residual_edge;
} network_edge;

typedef struct node {
	struct node* next;
	struct node* last;
	struct network_edge* edge;
} node;

int min(int a, int b) {
	return a < b ? a : b;
}

void add_edge(int from, int to, int capacity);
int back(int cur, int admissible);

node* adj[MAX];
int src, sink, check[MAX];
int n, m;

bool flag;
int sum;

void input() {
	fscanf(INPUT, "%d%d", &n, &m);
	// 1 : src
	// 2~n+1 : Á÷¿ø
	// n+2~n+m+1 : ÀÏ
	// n+m+2 : sink
	src = 1;
	sink = n + m + 2;

	for (int i = 1;i <= sink;i++) {
		adj[i] = (node*)malloc(sizeof(node));
		adj[i]->next = NULL;
		adj[i]->last = adj[i];
	}

	//	fscanf(INPUT, "%d%d", &src, &sink);

	int cnt;
	int to;
	for (int from = 2;from <= n + 1;from++) {
		add_edge(src, from, 1);

		fscanf(INPUT, "%d", &cnt);
		for (int j = 1;j <= cnt;j++) {
			fscanf(INPUT, "%d", &to);
			to = to + n + 1;
			add_edge(from, to, 1);
		}
	}

	for (int i = n + 2;i <= n + m + 1;i++) {
		add_edge(i, sink, 1);
	}
}

void process() {
	int temp_ad;
	check[src] = 1;
	while (1) {
		for (int i = 1;i <= sink;i++) check[i] = 0;
		check[src] = 1;
		flag = 0;
		temp_ad = back(src, 101);
		if (temp_ad == 0) break;
		sum += temp_ad;
	}

}

void output() {
	fprintf(OUTPUT, "%d", sum);
}

int main() {

	input();
	process();
	output();
	return 0;
}

network_edge* make_edge(int to, int capacity, int flow) {
	network_edge* edge = (network_edge*)malloc(sizeof(network_edge));
	edge->to = to;
	edge->capacity = capacity;
	edge->flow = flow;
	return edge;
}

void add_edge(int from, int to, int capacity) {
	node* actual = (node*)malloc(sizeof(node));
	node* residual = (node*)malloc(sizeof(node));

	actual->edge = make_edge(to, capacity, 0);
	residual->edge = make_edge(from, 0, 0);
	actual->edge->residual_edge = residual->edge;
	residual->edge->residual_edge = actual->edge;

	actual->next = NULL;
	residual->next = NULL;

	adj[from]->last->next = actual;
	adj[from]->last = actual;
	adj[to]->last->next = residual;
	adj[to]->last = residual;
}

int back(int cur, int admissible) {
	if (cur == sink) {
		flag = 1;
		return admissible;
	}

	int frontier;
	int temp;

	for (node* current = adj[cur]->next; current != NULL; current = current->next) {
		frontier = current->edge->to;
		if (check[frontier] == 1 || current->edge->capacity == current->edge->flow) continue;

		check[frontier] = 1;
		temp = back(frontier, min(admissible, current->edge->capacity - current->edge->flow));
		if (flag == 1) {
			current->edge->flow += temp;
			current->edge->residual_edge->flow -= temp;
			return temp;
		}
	}
	return 0;
}
