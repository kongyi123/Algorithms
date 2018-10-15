#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int T;
int check[1000000];
int len;
char table[6];
int limit;
int max_;
int n;

bool cmp(char a, char b) {
	if (a > b) return 1;
	return 0;
}

void swap(char &a, char &b) {
	char t = a;
	a = b;
	b = t;
}

int StringToInt() {
	int sum = 0;
	int t = 1;
	for (int i = len - 1;i >= 0;i--) {
		sum = sum + t*(table[i] - '0');
		t = t * 10;
	}

	return sum;
}

void back(int cnt) { // 여지껏 교환 횟수
	int tnum = StringToInt();
	if (check[tnum] != 0 && check[tnum] < cnt) return;
	if (cnt-2 > n) return;
	check[tnum] = cnt;
	if (cnt-1 <= n && max_ < tnum) {
		max_ = tnum;
	}
//	if (limit < cnt) limit = cnt;
	for (int i = 0;i < len;i++) {
		for (int j = i + 1;j < len;j++) {
			swap(table[i], table[j]);
			back(cnt + 1);
			swap(table[i], table[j]);
		}
	}
}

int main(void) {
	int same;
	scanf("%d", &T);
	for (int tc = 1;tc <= T;tc++) {
		same = 0;
		scanf("%s %d", table, &n);
		len = strlen(table);
		for (int i = 0;i < len;i++) {
			for (int j = i + 1;j < len;j++) {
				if (table[i] == table[j]) {
					same = 1;
					break;
				}
			}
		}
		max_ = 0;
		back(1); // check에는 원래 횟수 +1이 들어있음.
		
		sort(table, table + len, cmp);
		int tmax = StringToInt();

		printf("#%d ", tc);
		if (check[tmax] <= n+1 && check[tmax] != 0) {
			limit = check[tmax]-1;
			if (same == 0) {
				if ((n - limit) % 2 == 1) {
					sort(table, table + len, cmp);
					swap(table[len - 1], table[len - 2]);
					printf("%s\n", table);
					swap(table[len - 1], table[len - 2]);
				}
				else {

					sort(table, table + len, cmp);
					printf("%s\n", table);
				}
			}
			else {
				sort(table, table + len, cmp);
				printf("%s\n", table);
			}
		}
		else {
			printf("%d\n", max_);
		}
	}

	return 0;
}