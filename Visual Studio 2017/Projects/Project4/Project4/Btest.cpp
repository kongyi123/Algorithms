#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, M;
int before[100];
int after[100];
int qcnt;

int table_before[100];
int table_after[100];

int hash_before[1000];
int hash_after[1000];

int visit_before[100];
int visit_after[100];

int before_end;
int after_end;

int get(int* file_name, int idx, int* hash) {
	qcnt++;
	hash[file_name[idx]] = idx;
	return file_name[idx];
}

int find_size(int* file_name, int* file_table, int *hash, int *visit) {
	int cur = 0;
	int p = 1;
	int t;
	int flag = 0;
	int max = -1;
	while (p) {
		cur = cur + p;
		if (visit[cur] == 0) {
			t = get(&file_name[0], cur, hash);
			visit[cur] = 1;
		}
		if (t != 0) {
			file_table[cur] = t;
			if (max < cur) max = cur;
		}
		else {
			flag = 1;
			cur = cur - p;
		}

		if (flag == 0) p = p * 2;
		else p = p / 2;
	}

	return max;
}

void back(int s, int e, int p, int q) {
	int mid1 = (s + e) / 2;
	int mid2 = (p + q) / 2;
	int flag = 0;
	int term = (e - s);
	if (visit_after[mid2] == 0) {
		visit_after[mid2] = 1;
		table_after[mid2] = get(after, mid2, hash_after);
	}

	while (flag == 0) {
		term = term / 2;
		if (term == 0) break;
		int cur = s;
		while (cur < e) {
			cur = cur + term;
			if (visit_before[cur] == 0) {
				visit_before[cur] = 1;
				table_before[cur] = get(before, cur, hash_before);
			}
		}

		if (hash_after[table_before[mid1]] != 0) {
			if (!(hash_after[table_before[mid1]] - p == mid1 - s)) {
				// 삭제할 게 있는 범위
				back(s, mid1, p, hash_after[table_before[mid1]]);
			}

			if (!(q - hash_after[table_before[mid1]] == e - mid1)) {
				// 삭제할 게 있는 범위
				back(mid1, e, hash_after[table_before[mid1]], q);
			}
			flag = 1;
		}

		if (hash_before[table_after[mid2]] != 0) {
			if (!(hash_before[table_after[mid2]] - s == mid2 - p)) {
				// 삭제할 게 있는 범위
				back(s, hash_before[table_after[mid2]], p, mid2);
			}

			if (!(e - hash_before[table_after[mid2]] == q - mid2)) {
				// 삭제할 게 있는 범위
				back(hash_before[table_after[mid2]], e, mid2, q);
			}
			flag = 1;
		}
	}

}

void process() {
	before_end = find_size(before, table_before, hash_before, visit_before);
	after_end = find_size(after, table_after, hash_after, visit_after);
	back(0, before_end+1, 0, after_end+1);
}

int main(void) {
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 1;i <= N;i++) 
		scanf("%d", &before[i]);
	
	scanf("%d", &M);
	for (int i = 1;i <= M;i++) 
		scanf("%d", &after[i]);
	

	process();

	printf("%d", qcnt);
	return 0;
}