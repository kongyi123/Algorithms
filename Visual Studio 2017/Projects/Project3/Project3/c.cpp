#define _CRT_SECURE_NO_WARNINGS
// hash 자료구조

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUCKET_COUNT        10007
#define MAX_STRING_LENGTH   100

struct node {
public:
	struct node* next;
	int hash_value;
};

int get_hash_value(char* key) {
	int value = 0, len = strlen(key);
	for (int i = 0; i < len; i++) {
		value = (value * 27 + key[i] - 'A' + 1) % MAX_STRING_LENGTH;
	}
	return value;
}

void insert(node** head, char* key) {
	int hash_value = get_hash_value(key);

	node* new_node = new node();
	new_node->hash_value = hash_value;
	if (!(*head)) { // 기존에 아무것도 없는 경우
		new_node->next = NULL;
		(*head) = new_node;
	}
	else { // 기존에 노드가 하나라도 있는 경우
		node* current_node;
		for (current_node = (*head); current_node->next != NULL; current_node = current_node->next) {
			if (current_node->hash_value == hash_value) {
				break;
			}
		}


		new_node->next = current_node;
		(current_node) = new_node;
	}
	return;
}

void erase(node** head, char* key) {
	int hash_value = get_hash_value(key);
	for (node* precedent_node = *head; precedent_node->next != NULL; precedent_node = precedent_node->next) {
		if (precedent_node->next->hash_value == hash_value) {
			precedent_node->next = precedent_node->next->next;
		}
	}
	return;
}

int count(node** head, char* key) {
	int counter = 0;
	int hash_value = get_hash_value(key);
	for (node* current_node = (*head)->next; current_node->next != NULL; current_node = current_node->next) {
		if (current_node->hash_value == hash_value) {
			counter++;
		}
	}
	return counter;
}

int main() {
	int n;
	scanf("%d", &n);

	node* hash[BUCKET_COUNT];

/*	for (int i = 0;i < BUCKET_COUNT;i++) {
		node* n = new node();
		n->next = NULL;
		hash[i] = n;
	}
	*/
	for (int i = 0; i < n; i++) {
		int command;
		char key[MAX_STRING_LENGTH + 1];
		scanf("%d %s", &command, key);
		//(*hash)->next = NULL;
		
		if (command == 1) insert(hash, key);
		else if (command == 2) erase(hash, key);
		else {
			if (0 < count(hash, key)) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
		}
	}

	return 0;
}