#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

string S = "SMS messages are really short";
int K = 12;

FILE *out = fopen("output.txt", "w");

int table[500], m;
int min = 9999;

void back(int cur, int cnt) {
	if (cur == m) {
		if (min > cnt) {
			min = cnt;
		}
		return;
	}

	int sum = 0;
	for (int i = cur+1;i <= m;i++) {
		sum += table[i];
		if (sum <= K) {
			back(i, cnt + 1);
		}
		else break;
	}
}

int main(void) {
	int cnt = 0;
	for (int i = 0;i < S.length();i++) {
		if (S.at(i) == ' ') {
			table[++m] = cnt;
			cnt = 0;
		}
		else cnt++;
	}
	table[++m] = cnt;

	back(0, 0);
	return 0;
}

/*
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int table[500], m;
int min_ = 9999;

void back(int cur, int cnt, int K) {
if (cur == m) {
if (min_ > cnt) {
min_ = cnt;
}
return;
}

int sum = 0;
for (int i = cur+1;i <= m;i++) {
sum += table[i];
if (sum <= K) {
back(i, cnt + 1, K);
}
else break;
}
}

int solution(string &S, int K) {
int cnt = 0;
for (int i = 0;i < S.length();i++) {
if (S.at(i) == ' ') {
table[++m] = cnt;
cnt = 0;
}
else cnt++;
}
table[++m] = cnt;

back(0, 0, K);
return min_;
}


*/