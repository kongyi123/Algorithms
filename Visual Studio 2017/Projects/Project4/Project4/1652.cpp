#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char data[110][110];

int main(void) {
	int n;
	scanf("%d", &n);
	char buff;
	scanf("%c", &buff);
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			scanf("%c", &data[i][j]);
		}
		scanf("%c", &buff);
	}

	int x, y;
	x = y = 0;
	int cnt;
	for (int i = 1;i <= n;i++) {
		cnt = 0;
		for (int j = 1;j <= n;j++) {
			if (data[i][j] == 'X') {
				if (cnt >= 2) x++;
				cnt = 0;
			}
			else cnt++;
		}
		if (cnt >= 2) x++;
	}
	
	for (int j = 1;j <= n;j++) {
		cnt = 0;
		for (int i = 1;i <= n;i++) {
			if (data[i][j] == 'X') {
				if (cnt >= 2) y++;
				cnt = 0;
			}
			else cnt++;
		}
		if (cnt >= 2) y++;

	}
	printf("%d %d", x, y);
}