// %c는 전부 진짜 모조리 다받는다. 스페이스까지도.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, m;
char data[20];
char buf[20];
int check[30];
int next[30];

void back(int cur) {
	if (cur == n + 1) {
		int cntmo = 0, increase = 1;
		buf[n + 1] = 'z' + 1;
		for (int i = 1;i <= n;i++) {
			if (buf[i] == 'a' || buf[i] == 'e' || buf[i] == 'i' || buf[i] == 'o' || buf[i] == 'u') cntmo++;
			if (buf[i] > buf[i + 1]) {
				increase = 0;
				break;
			}
		}
		buf[n + 1] = 0;
		if (cntmo >= 1 && n - cntmo >= 2 && increase == 1) {
			printf("%s\n", &buf[1]);
		}
		return;
	}

	for (int i = 0;i <= 29;i++) {
		if (check[i] == 0 && next[i] == 1) {
			if ((cur >= 2 && buf[cur - 1] < i + 'a') || cur == 1) {
				check[i] = 1;
				buf[cur] = i + 'a';
				back(cur + 1);
				check[i] = 0;
			}
		}
	}
}

int main(void) {
	scanf("%d %d", &n, &m);
	char buff;
	scanf("%c", &buff);
	for (int i = 1;i <= m;i++) {
		scanf("%c", &data[i]);
		next[data[i]-'a'] = 1;
		scanf("%c", &buff);
	}

	back(1);
	return 0;
}
