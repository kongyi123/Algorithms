// https://www.acmicpc.net/blog/view/22
// sort stl 사용방법 및 class operator 재정의 방법
// strlen

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

using namespace std;

int strlen(char* ch) {
	int cnt = 0;
	while (*ch != 0) { ch++, cnt++; }
	return cnt;
}

class string {
public:
	char str[11] = { 0, };
	int len;
	string() {}
	string(char input[]) {
		len = strlen(input);
		for (int i = 0; i < len; i++)
			str[i] = input[i];
	}
	bool operator<(string b) {
		for (int i = 0; i < 11; i++) {
			if (str[i] < b.str[i]) return 1;
			else if (str[i] > b.str[i]) return 0;
		}

		return 0;
	}
	bool operator==(string b) {
		if (strlen(b.str) != len) return 0;
		for (int i = 0; i < len; i++) {
			if (str[i] != b.str[i]) return 0;
		}

		return 1;
	}

};

int n;
string dat[200001];


int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char ch[11];
		scanf("%s", &ch);
		dat[i] = string(ch);
	}
//	sort(dat, dat + n, cmp);
	sort(dat, dat + n);
	printf("\n");
	int cnt[200001] = { 0, }, max = 0;
	for (int i = 0; i < n-1; i++) {
		if (dat[i] == dat[i + 1]) {
			cnt[i+1] = cnt[i]+1;
			if (max < cnt[i+1]) max = cnt[i+1];
		}
		else cnt[i+1] = 0;
	}

	for (int i = 0; i < n; i++) {
		if (cnt[i] == max) {
			printf("%s\n", dat[i].str);
		}
	}

	

	return 0;
}