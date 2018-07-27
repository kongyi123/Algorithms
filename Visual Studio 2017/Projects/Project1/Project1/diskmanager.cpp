#include <stdlib.h>
#include <stdio.h>

extern int type, id, size;
extern int block_count;

int check(int block_number, int id, int start, int end);

typedef struct chunk {
	int block_number;
	int id;
	int start_idx;
	int end_idx;
	chunk* next;
} chunk;

chunk* empty_list = NULL;
chunk* filled_list = NULL;

int add(chunk* &ptr_list, int block_number, int id, int start, int end) {
	if (ptr_list == NULL) {
		ptr_list = (chunk*)malloc(sizeof(chunk));
		ptr_list->block_number = 0;
		ptr_list->id = 0;
		ptr_list->start_idx = 0;
		ptr_list->end_idx = 0;
		ptr_list->next = NULL;

		chunk* temp = (chunk*)malloc(sizeof(chunk));
		temp->block_number = block_number;
		temp->id = id;
		temp->start_idx = start;
		temp->end_idx = end;
		temp->next = NULL;

		ptr_list->next = temp;
	}
	else {

		// ù����� �ƴѵ�, ���� ���ٸ�? �׳� �߰�
		if (ptr_list->next == NULL) {
			chunk* temp = (chunk*)malloc(sizeof(chunk));
			temp->block_number = block_number;
			temp->id = id;
			temp->start_idx = start;
			temp->end_idx = end;
			temp->next = NULL;

			ptr_list->next = temp;
		}

		// ù����� �ƴѵ�, ���� �ִٸ�? ������ ��ġ�� ã�´�.

		chunk* before = ptr_list;
		for (chunk*cur = ptr_list->next; cur != NULL; before = cur, cur = cur->next) {
			if (cur->block_number < block_number) continue;
			if (cur->block_number == block_number && cur->start_idx < start) continue;

			// ������ ��ġ�� cur�� ��. cur�� �о�� �� �տ� �� ��带 �ִ´�.

			chunk* temp = (chunk*)malloc(sizeof(chunk));
			temp->block_number = block_number;
			temp->id = id;
			temp->start_idx = start;
			temp->end_idx = end;
			temp->next = cur;

			before->next = temp;

			break;
		}

		// ������ ��ġ�� ��ã���� -> ��, �������� �߰��ؾߵǴ� ���
		if (before->next == NULL) {
			chunk* temp = (chunk*)malloc(sizeof(chunk));
			temp->block_number = block_number;
			temp->id = id;
			temp->start_idx = start;
			temp->end_idx = end;
			temp->next = NULL;

			before->next = temp;
		}

	}
	return 0;
}

int del(chunk *before, chunk* &cur) { 
	before->next = cur->next;
	free(cur);
	return 0;
}

int deletion() {
	chunk* before = filled_list;
	for (chunk* cur = filled_list->next; cur != NULL; before = cur, cur = cur->next) {
		if (cur->id == id) {
			add(empty_list, cur->block_number, 0, cur->start_idx, cur->end_idx);
			del(before, cur);
			cur = before;
		}
	}
	return 0;
}

int assign() {

	int remain = size;
	while (remain) {
		if (empty_list == NULL || empty_list->next == NULL) { // ���ʻ���̰ų� ���� ���� ���
			add(empty_list, ++block_count, 0, 0, 4999);
		}

		chunk *before = empty_list;
		for (chunk* cur = empty_list->next; cur != NULL; before = cur, cur = cur->next) {
			if (cur->end_idx - cur->start_idx + 1 > remain) { // chunk�� ������ ���� ���
				add(filled_list, cur->block_number, id, cur->start_idx, cur->start_idx + remain - 1); 
				cur->start_idx += remain;
				remain = 0;
				break;
			}
			else if (cur->end_idx - cur->start_idx + 1 == remain) { // chunk�� �� �´� ���
				add(filled_list, cur->block_number, id, cur->start_idx, cur->end_idx);
				del(before, cur);
				remain = 0;
				break;
			}
			else if (cur->end_idx - cur->start_idx + 1 < remain) { // chunk���� ��ġ�� ���
				add(filled_list, cur->block_number, id, cur->start_idx, cur->end_idx);
				remain -= (cur->end_idx - cur->start_idx + 1); // ***** ������ �κ� ***** ���� ���� ���� �� �޸� ������ �Ѵ�.
				del(before, cur);
				cur = before;
			}
		}
	}


	return 0;
}

int print() {
	fprintf(stdout, "block_count = %d\n", block_count);
	for (chunk* cur = filled_list->next; cur != NULL; cur = cur->next) {
		fprintf(stdout, "block_number = %d | id = %d | start = %d | end = %d\n", cur->block_number, cur->id, cur->start_idx, cur->end_idx);
		fprintf(stdout, "error = %d\n", check(cur->block_number, cur->id, cur->start_idx, cur->end_idx));
	}
	return 0;
}