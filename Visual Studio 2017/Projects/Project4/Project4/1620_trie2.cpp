// 트라이
// 스택 오버플로우라고 가정하고 재귀 없는 함수로 구현
// 그래도 용량 초과 나옴.
// 즉, 재귀 없음 + 맵핑 방식으로 구현해도 메모리 초과.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int N, M;
char name[100001][22];
char str[22];

int atoi(char str[]) {
	int len = strlen(str);
	int t = 1;
	int sum = 0;
	for (int i = len - 1;i >= 0;i--) {
		sum = sum + t * (str[i] - '0');
		t = t * 10;
	}

	return sum;
}

struct Trie {
	int index;
	vector<pair<int, Trie*>> next;
	Trie() {
		index = 0;
	}

	void insert(char str[], int idx);
	int get(char str[]);
};


void Trie::insert(char str[], int idx) {
	int x = 0;
	Trie* ptr = this;
	
	while (1) {
		char cur = str[x];
		if (cur == '\0') {		// 문자열의 끝을 알리는 문자인지
			ptr->index = idx;
			return;
		}
		else {					// 아니면
			cur = cur - 'a' + 1;
			int isThere = -1;
			for (int i = 0;i < ptr->next.size();i++) {
				if (ptr->next[i].first == cur) {
					isThere = i;
					break;
				}
			}

			if (isThere == -1) {
				Trie* newNode = new Trie();
				ptr->next.push_back(pair<int, Trie*>(cur, newNode));

				isThere = ptr->next.size() - 1;
			}
			
			ptr = ptr->next[isThere].second;
		}

		x++;
	}
}

int Trie::get(char str[]) {
	int x = 0;
	Trie* ptr = this;

	while (1) {
		if (str[x] == '\0') return ptr->index;
		char cur = str[x] - 'a' + 1;
		int isThere = -1;
		for (int i = 0;i < ptr->next.size();i++) {
			if (ptr->next[i].first == cur) {
				isThere = i;
				break;
			}
		}

		ptr = ptr->next[isThere].second;
		x++;
	}
}


int main(void) {
	Trie trie;
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &N, &M);
	for (int i = 1;i <= N;i++) {
		scanf("%s", name[i]);
		name[i][0] = name[i][0] - 'A' + 'a';
		trie.insert(name[i], i);
	}

	int num;
	for (int i = 1;i <= M;i++) {
		scanf("%s", str);
		if (str[0] >= '0' && str[0] <= '9') {
			num = atoi(str);
			name[num][0] = name[num][0] - 'a' + 'A';
			printf("%s\n", name[num]);
			name[num][0] = name[num][0] - 'A' + 'a';
		}
		else {
			str[0] = str[0] - 'A' + 'a';
			printf("%d\n", trie.get(str));
		}
	}
	return 0;
}
