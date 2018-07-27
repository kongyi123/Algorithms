#include <stdlib.h>

extern int block_count;
extern int type, id, size;

typedef struct node {
	int disk[5000];
	node* next;
} node;

node* disk_list = NULL;

int check_deletion() {
	for (node *cur = disk_list->next; cur != NULL; cur = cur->next) {
		for (int i = 0;i < 5000;i++) {
			if (cur->disk[i] == id) {
				cur->disk[i] = 0;
			}
		}
	}


	return 0;
}

int check_assign() {
	if (disk_list == NULL) {
		disk_list = (node*)malloc(sizeof(node));
		disk_list->next = NULL;
	
		node* temp = (node*)malloc(sizeof(node));
		for (int i = 0;i < 5000;i++) temp->disk[i] = 0;
		temp->next = NULL;
		disk_list->next = temp;
	}

	int remain = size;
	node* cur = disk_list->next;
	while (remain) {
		for (int i = 0;i < 5000;i++) {
			if (cur->disk[i] == 0 && remain > 0) {
				remain --;
				cur->disk[i] = id;
			}
			else if (remain == 0) break;
		}
		if (remain == 0) break;

		if (cur->next == NULL) { // ¸¸µé¾îÁà
			node *temp = (node*)malloc(sizeof(node));
			for (int i = 0;i < 5000;i++) temp->disk[i] = 0;
			temp->next = NULL;
			cur->next = temp;
		}
		cur = cur->next;
	}



	return 0;
}

int check(int block_number, int id, int start, int end) {
	int er = 0;
	node* cur = disk_list;
	for (int i = 1;i <= block_number;i ++) {
		cur = cur->next;
	}

	for (int i = start;i <= end;i++) {
		if (cur->disk[i] != id) {
			er = 1;
			break;
		}
	}

	return er;
}