// ¶óºó-Ä«ÇÁ

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <vector>
#define MOD 100000

using namespace std;

struct Poke {
	char* name;
	int idx;
};

int N, M;
char name[100001][22];
Poke* list[100001];
Poke dat[100001];
char str[22];

vector<Poke*> table[MOD + 1];

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

inline int mod(int n) {
	if (n >= 0) return n % MOD;
	return ((-n / MOD + 1)*MOD + n) % MOD;
}

int hash_function(char word[]) {
	int sum = 0, t = 1;
	int len = strlen(word);
	for (int j = 0;j < len;j++) {
		sum = mod(sum + t*(word[j] - 'a'));
		t = t * 26;
	}

	return sum;
}

// ÇØ½Ì
void process() {
	for (int i = 1;i <= N;i++) {
		int hash_value = hash_function(list[i]->name);
		table[hash_value].push_back(list[i]);
	}
}

int cmp(char a[], char b[]) {
	int lena = strlen(a);
	int lenb = strlen(b);
	int lenc = lena>lenb ? lenb : lena;
	for (int i = 0;i < lenc;i++) {
		if (a[i] < b[i]) return -1;
		else if (a[i] > b[i]) return 1;
	}

	if (lena > lenb) return 1;
	else if (lena < lenb) return -1;
	return 0;
}


int main(void) {
	scanf("%d%d", &N, &M);
	for (int i = 1;i <= N;i++) {
		scanf("%s", name[i]);
		name[i][0] = name[i][0] - 'A' + 'a';
		dat[i].name = name[i];
		dat[i].idx = i;
		list[i] = &dat[i];
	}

	process();

	int num;
	for (int i = 1;i <= M;i++) {
		scanf("%s", str);
		if (str[0] >= '0' && str[0] <= '9') {
			num = atoi(str);
			dat[num].name[0] = dat[num].name[0] - 'a' + 'A';
			printf("%s\n", dat[num].name);
			dat[num].name[0] = dat[num].name[0] - 'A' + 'a';
		}
		else {
			str[0] = str[0] - 'A' + 'a';
			int hash_value = hash_function(str);
			int len = table[hash_value].size();
			for (int i = 0;i < len;i++) {
				if (cmp(str, table[hash_value][i]->name) == 0) {
					printf("%d\n", table[hash_value][i]->idx);
					break;
				}
			}

		//	printf("%d\n", binary_search(1, N, str));
		}
	}
	return 0;
}
