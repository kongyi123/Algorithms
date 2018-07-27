#include <stdlib.h>
#include <stdio.h>

extern int type, id, size;
extern int block_count;

int check(int block_number, int id, int start, int end);

typedef struct chunk { // 일반적으로 첫째 항은 주소 주머니로 쓰인다 - (o, 항이 있는데 값이 없는 주소 주머니 항으로서 존재)
					   // 항 삭제가 편한 구현방식 (그럼에도 마지막 항은 특수처리를 해야한다)
	int block_number; 
	int id;
	int start_idx;
	int end_idx;
	chunk *next;
} chunk;

chunk *filled_link = NULL; // 채운곳 리스트 포인터
chunk *empty_link = NULL; // 빈곳 리스트 포인터

int msg;					// 디버깅용 

int add(chunk* &list_link, int block_number, int id, int start, int end) {
	if (start <= end) {
		if (list_link == NULL) {	// 최초사용일때 -> 주소 주머니를 만들어줌
			list_link = (chunk*)malloc(sizeof(chunk));
			list_link->block_number = 0;
			list_link->id = 0;
			list_link->start_idx = 0;
			list_link->end_idx = 0;
			list_link->next = NULL;
		}


		// 최초사용이 아닌 경우 -> 항이 없을 때 -> 그냥 만들어준다.
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
			//						-> 항이 있을 때 -> 오름 차순 리스트를 유지하는 적당한 자리를 찾아 끼워 넣어줌.
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

			if (cur == NULL) { // 즉, 꼬리에 추가 시켜줘야 된다는 것임.
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

int del(chunk* before, chunk* &cur) { // 양방향 링크드 리스트 항 삭제 함수 - no prev ver.
	before->next = cur->next;
	free(cur);
	return 0;
}

int deletion() {
	chunk* before = filled_link;
	for (chunk* cur = filled_link->next; cur != NULL; cur = cur->next) {
		if (cur->id == id) {
			// empty_link 에 추가
			add(empty_link, cur->block_number, 0, cur->start_idx, cur->end_idx);
			// filled_link 에서 삭제
			del(before, cur);
			cur = before;
		}

		before = cur;
	}
	return 0;
}

int assign() {
	// 순차적으로 빈 chunk를 찾는다.
	// fprintf(stdout, "size = %d\n", size); // 디버깅용
	
	int remain = size;

	while (remain) {	// remain이 남지 않을때 까지 반복

		// 빈 chunk가 없는 경우 (최초사용인 경우 / 최초사용이 아닌경우) -> 새로운 블록을 만들어준다.
		if (empty_link == NULL || empty_link->next == NULL) {
			add(empty_link, ++block_count, 0, 0, 4999);
		}

		chunk* before = empty_link;
		for (chunk* cur = empty_link->next; cur != NULL; before = cur, cur = cur->next) {
			if (cur->end_idx - cur->start_idx + 1 > remain) {
				msg = add(filled_link, cur->block_number, id, cur->start_idx, cur->start_idx + remain - 1); // 채워진곳 링크드 리스트에 추가
				if (msg == 0) fprintf(stdout, "add가 비정상 동작 하였음\n");
				cur->start_idx += remain; // 빈chunk가 유지됨
				remain = 0;
				break;
			}
			else if (cur->end_idx - cur->start_idx + 1 == remain) {
				msg = add(filled_link, cur->block_number, id, cur->start_idx, cur->start_idx + remain - 1); // 채워진곳 링크드 리스트에 추가
				if (msg == 0) fprintf(stdout, "add가 비정상 동작 하였음\n");
				del(before, cur); // 해당 chunk 지우고 앞뒤 링크 연결해준다.
				remain = 0;
				break;
			}
			else if (cur->end_idx - cur->start_idx + 1 < remain) {
				msg = add(filled_link, cur->block_number, id, cur->start_idx, cur->end_idx); // 채워진곳 링크드 리스트에 추가
				if (msg == 0) fprintf(stdout, "add가 비정상 동작 하였음\n");
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