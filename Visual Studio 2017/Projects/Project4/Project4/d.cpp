// Trie 자료구조

#include <cstdio>
using namespace std;

struct Trie {
	bool finish;
	Trie* next[26];
	Trie() : finish(false) {
		for (int i = 0;i <= 25;i++) next[i] = NULL;
	}

	~Trie() {
		for (int i = 0;i <= 25;i++) {
			if (next[i]) delete next[i];
		}
	}

	void insert(const char *ptr) {
		if (*ptr == '\0') finish = true;
		else {
			int cur = *ptr - 'a';
			if (next[cur] == NULL) next[cur] = new Trie();
			next[cur]->insert(ptr + 1);
		}
	}

	bool search(const char *ptr) {
		if (*ptr == '\0') return finish;
		int cur = *ptr - 'a';
		if (next[cur] == NULL) return false;
		return next[cur]->search(ptr + 1);
	}
};

int main(void) {
	Trie* t = new Trie();
	t->insert("abc");
	t->insert("abd");
	t->insert("asdf");
	t->insert("axf");

	if (t->search("abs")) printf("abs IN\n");
	if (t->search("abc")) printf("abc IN\n");
	if (t->search("ab")) printf("ab IN\n");
	if (t->search("ax")) printf("ax IN\n");
}