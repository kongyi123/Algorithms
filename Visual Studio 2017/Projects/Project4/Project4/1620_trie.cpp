// 트라이
// 스택 오버플로우라고 가정하고

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <vector>
#define MOD 100000

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
	char cur = str[0];
	if (cur == '\0') {		// 문자열의 끝을 알리는 문자인지
		index = idx;
		return;
	}
	else {					// 아니면
		cur = cur - 'a' + 1;
		int isThere = -1;
		for (int i = 0;i < next.size();i++) {
			if (next[i].first == cur) {
				isThere = i;
				break;
			}
		}

		if (isThere == -1) {
			next.push_back(pair<int, Trie*>(cur, new Trie()));
			isThere = next.size() - 1;
		}
		next[isThere].second->insert(str + 1, idx);
	}
}

int Trie::get(char str[]) {
	if (str[0] == '\0') return index;
	char cur = str[0] - 'a' + 1;
	int isThere = -1;
	for (int i = 0;i < next.size();i++) {
		if (next[i].first == cur) {
			isThere = i;
			break;
		}
	}

	return next[isThere].second->get(str + 1);
}


int main(void) {
	Trie trie;
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
