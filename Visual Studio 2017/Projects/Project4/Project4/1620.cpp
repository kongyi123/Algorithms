#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>

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
queue<Poke*> radix[30];

int atoi(char str[]) {
	int len = strlen(str);
	int t = 1;
	int sum = 0;
	for (int i = len-1;i >= 0 ;i--) {
		sum = sum + t * (str[i] - '0');
		t = t * 10;
	}

	return sum;
}

void radix_sort() {
	int d = 20;
	for (int j = d;j >= 0;j--) {
		for (int i = 1;i <= N;i++) {
			if (list[i]->name[j] < 'a' || list[i]->name[j] > 'z') radix[0].push(list[i]);
			else radix[list[i]->name[j] - 'a' + 1].push(list[i]);
		}

		int k = 1;
		for (int i = 0;i < 27;i++) {
			while (radix[i].size() > 0) {
				list[k++] = radix[i].front();
				radix[i].pop();
			}
		}
	}
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

	radix_sort();

	int num;
	for (int i = 1;i <= M;i++) {
		scanf("%s", str);
		if (str[0] >= '0' && str[0] <= '9') {
			num = atoi(str);
			printf("%s\n", dat[num]);
		}
		else {
			
		}
	}
	return 0;
}