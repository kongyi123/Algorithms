// 해쉬 값을 구하는 함수 + LinkedList

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

#define BUCKET_COUNT        10007
#define MAX_STRING_LENGTH   100

template<typename T>
struct LinkedList {
	struct Node {
		T val;
		Node* next;
		Node(T val) {
			this->val = new char[strlen(val)+1];
			strcpy(this->val, val);
			this->next = NULL;
		}
		~Node() {
			delete (this->val);
		}
	};

	Node* pStart;
	Node* pEnd;
	int cnt;

	LinkedList() : cnt(0), pStart(NULL), pEnd(NULL) {}

	~LinkedList() {
		Node* prev;
		Node* cur = pStart;

		while (cur != NULL) {
			prev = cur;
			cur = cur->next;
			delete prev;
		}

	}

	void add(T val) {
		cnt++;
		if (pStart == NULL) {
			Node* newNode = new Node(val);
			pStart = pEnd = newNode;
		}
		else {
			Node* newNode = new Node(val);
			pEnd->next = newNode;
			pEnd = newNode;
		}
	}



	bool del(T val) { // 특정 값을 찾아서 삭제하는 경우
		if (cnt == 0) return false; // 값이 아예  없는 경우

		if (strcmp(pStart->val,val) == 0) {	// 첫번째 노드의 값이 해당하는 경우
			Node* temp = pStart->next;
			delete pStart;
			pStart = temp;
			cnt--;
			return true;
		}
		else {						// 해당되는 값이 두번째 혹은 그 이후에 있는 경우
			Node* prev = pStart;
			Node* cur = pStart->next;
			while (cur != NULL) {
				if (strcmp(cur->val, val) == 0) {
					prev->next = cur->next;
					delete cur;
					cnt--;
					return true;
				}
				prev = cur;
				cur = cur->next;
			}
		}

		return false;
	}

};


int get_hash_value(char* key) { // 해쉬 값을 구하는 함수
	int value = 0, len = strlen(key);
	for (int i = 0; i < len; i++)
		value = (value * 27 + key[i] - 'A' + 1) % MAX_STRING_LENGTH;
	return value;
}

void insert(LinkedList<char*>* head, char* key) {
	int hash_value = get_hash_value(key);
	head[hash_value].add(key);
}

void erase(LinkedList<char*>* head, char* key) {
	int hash_value = get_hash_value(key);
	head[hash_value].del(key);
}

int count(LinkedList<char*>* head, char* key) {
	int hash_value = get_hash_value(key);
	return head[hash_value].cnt;
}

int main() {
	int n;
	scanf("%d", &n);

	LinkedList<char*> hash[BUCKET_COUNT];
	for (int i = 0; i < n; i++) {
		int command;
		char key[MAX_STRING_LENGTH + 1];
		scanf("%d %s", &command, key);

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
