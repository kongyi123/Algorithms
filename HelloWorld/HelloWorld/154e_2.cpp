// ������ �ϴ� �ð��� �����ɸ��°� �ƴ϶� 
// �򰥷��ϴ� �ð��� ���� �ð��� ���Դ´�.
// ��û���� �ð��� ��������. ���� �밡�ٸ� �ؼ� �����ϰ� ����°� ���� ���� ����̴�.

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