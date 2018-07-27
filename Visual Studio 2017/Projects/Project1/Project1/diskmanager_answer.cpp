#include <stdlib.h>
#include <stdio.h>

extern int type, id, size;
extern int block_count;

int check(int block_number, int id, int start, int end);

typedef struct chunk { // �Ϲ������� ù° ���� �ּ� �ָӴϷ� ���δ� - (o, ���� �ִµ� ���� ���� �ּ� �ָӴ� �����μ� ����)
					   // �� ������ ���� ������� (�׷����� ������ ���� Ư��ó���� �ؾ��Ѵ�)
	int block_number; 
	int id;
	int start_idx;
	int end_idx;
	chunk *next;
} chunk;

chunk *filled_link = NULL; // ä��� ����Ʈ ������
chunk *empty_link = NULL; // ��� ����Ʈ ������

int msg;					// ������ 

int add(chunk* &list_link, int block_number, int id, int start, int end) {
	if (start <= end) {
		if (list_link == NULL) {	// ���ʻ���϶� -> �ּ� �ָӴϸ� �������
			list_link = (chunk*)malloc(sizeof(chunk));
			list_link->block_number = 0;
			list_link->id = 0;
			list_link->start_idx = 0;
			list_link->end_idx = 0;
			list_link->next = NULL;
		}


		// ���ʻ���� �ƴ� ��� -> ���� ���� �� -> �׳� ������ش�.
		if (list_link->next == NULL) {
			chunk* temp = (chunk*)malloc(sizeof(chunk));
			temp->block_number = block_number;
			temp->id = id;
			temp->start_idx = start;
			temp->end_idx = end;

			temp->next = list_link->next;
			list_link->next = temp;
		}
		else {
			//						-> ���� ���� �� -> ���� ���� ����Ʈ�� �����ϴ� ������ �ڸ��� ã�� ���� �־���.
			chunk* cur = list_link->next;
			chunk* before = list_link;
			for (; cur != NULL; before = cur, cur = cur->next) {
				if (cur->block_number == block_number && cur->start_idx < start) continue;
				if (cur->block_number < block_number) continue;

				chunk* temp = (chunk*)malloc(sizeof(chunk));
				temp->block_number = block_number;
				temp->id = id;
				temp->start_idx = start;
				temp->end_idx = end;

				before->next = temp;
				temp->next = cur;

				break;
			}

			if (cur == NULL) { // ��, ������ �߰� ������� �ȴٴ� ����.
				chunk* temp = (chunk*)malloc(sizeof(chunk));
				temp->block_number = block_number;
				temp->id = id;
				temp->start_idx = start;
				temp->end_idx = end;

				temp->next = NULL;
				before->next = temp;
			}

		}

		return 1;
	}

	return 0;
}

int del(chunk* before, chunk* &cur) { // ����� ��ũ�� ����Ʈ �� ���� �Լ� - no prev ver.
	before->next = cur->next;
	free(cur);
	return 0;
}

int deletion() {
	chunk* before = filled_link;
	for (chunk* cur = filled_link->next; cur != NULL; cur = cur->next) {
		if (cur->id == id) {
			// empty_link �� �߰�
			add(empty_link, cur->block_number, 0, cur->start_idx, cur->end_idx);
			// filled_link ���� ����
			del(before, cur);
			cur = before;
		}

		before = cur;
	}
	return 0;
}

int assign() {
	// ���������� �� chunk�� ã�´�.
	// fprintf(stdout, "size = %d\n", size); // ������
	
	int remain = size;

	while (remain) {	// remain�� ���� ������ ���� �ݺ�

		// �� chunk�� ���� ��� (���ʻ���� ��� / ���ʻ���� �ƴѰ��) -> ���ο� ����� ������ش�.
		if (empty_link == NULL || empty_link->next == NULL) {
			add(empty_link, ++block_count, 0, 0, 4999);
		}

		chunk* before = empty_link;
		for (chunk* cur = empty_link->next; cur != NULL; before = cur, cur = cur->next) {
			if (cur->end_idx - cur->start_idx + 1 > remain) {
				msg = add(filled_link, cur->block_number, id, cur->start_idx, cur->start_idx + remain - 1); // ä������ ��ũ�� ����Ʈ�� �߰�
				if (msg == 0) fprintf(stdout, "add�� ������ ���� �Ͽ���\n");
				cur->start_idx += remain; // ��chunk�� ������
				remain = 0;
				break;
			}
			else if (cur->end_idx - cur->start_idx + 1 == remain) {
				msg = add(filled_link, cur->block_number, id, cur->start_idx, cur->start_idx + remain - 1); // ä������ ��ũ�� ����Ʈ�� �߰�
				if (msg == 0) fprintf(stdout, "add�� ������ ���� �Ͽ���\n");
				del(before, cur); // �ش� chunk ����� �յ� ��ũ �������ش�.
				remain = 0;
				break;
			}
			else if (cur->end_idx - cur->start_idx + 1 < remain) {
				msg = add(filled_link, cur->block_number, id, cur->start_idx, cur->end_idx); // ä������ ��ũ�� ����Ʈ�� �߰�
				if (msg == 0) fprintf(stdout, "add�� ������ ���� �Ͽ���\n");
				remain -= (cur->end_idx - cur->start_idx + 1);
				del(before, cur);
				cur = before;
			}
		}
	}

	return remain;
}

int print() {
	fprintf(stdout, "block_count = %d\n", block_count);
	for (chunk* cur = filled_link->next; cur != NULL; cur = cur->next) {
		fprintf(stdout, "block_number = %d | id = %d | start = %d | end = %d\n", cur->block_number, cur->id, cur->start_idx, cur->end_idx);
		fprintf(stdout, "error = %d\n", check(cur->block_number, cur->id, cur->start_idx, cur->end_idx));
	}

	return 0;
}