#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

char st[3];
int check[3];

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);

	if (n != 1) {
		st[0] = '1';
	}
	else st[0] = '0';
	st[1] = '0';
	st[2] = '0';
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (check[a - 1] == 0) {
			check[a - 1] = 1;
			st[a - 1] = '0' + b;
		}
		else if (st[a - 1] == '0' + b) {
			continue;
		}
		else {
			printf("-1");
			return 0;
		}
	}
	
	
	if (n > 1 && st[0] == '0') printf("-1");
	else {
		for (int i = 0; i < n; i++) {
			printf("%c", st[i]);
		}
	}

	return 0;
}