// 생각을 하는 시간이 오래걸리는게 아니라 
// 헷갈려하는 시간이 가장 시간을 좀먹는다.
// 엄청나게 시간이 빨리간다. 차라리 노가다를 해서 명쾌하게 만드는게 가장 빠른 방법이다.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
char str[200];
int n;

int dy[200][4];

int main(void) {
	scanf("%s %d", str, &n);
	int len = strlen(str);
	dy[0][0] = 1;
	for (int i = 1; i <= len; i++) {
		dy[i][0] = 1;
		for (int j = 1; j <= n; j++) {
			dy[i][j] = dy[i - 1][j] + 9 * dy[i - 1][j - 1];
		}
	}


	//printf("%d", dap);


	return 0;
}