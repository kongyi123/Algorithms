#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Trie {
	int index;
	Trie* next[28] = { 0, };	// 초기화 해줘야. 자동 초기화 안된다. 전역 아니라서.
	Trie() {
		index = 0;
	}
	~Trie() {
		for (int i = 0;i < 28;i++)
			if (next[i]) delete next[i];
	}

	void insert(char str[], int idx);
	int get(char str[]);
};


void Trie::insert(char str[], int idx) {
	char cur = str[0];
	if (cur == '\0') {		// 문자열의 끝을 알리는 문자인지
		index = idx;
		return;
	}
	else {					// 아니면
		cur = cur - 'a'+1;
		if (next[cur] == 0) next[cur] = new Trie();
		next[cur]->insert(str + 1, idx);
	}
}

int Trie::get(char str[]) {
	if (str[0] == '\0') return index;
	char cur = str[0] - 'a'+1;
	if (next[cur]) return next[cur]->get(str + 1);
	return 0;
}

int main(void) {
	char str[100];
	scanf("%s", str);
	Trie trie;
	trie.insert(str, 1);
	printf("%d", trie.get(str));
	return 0;
}