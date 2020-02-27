// dy ���Ǹ� �߸��Ͽ� �ʹ� �����ϰ� ������ ���� �ȳ���. 
// �����ϰ� dy ���Ǹ� ��¦ �ٲ㼭 ���� ¥��
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, k;

int dy[1000][4];

void init(int len) {
	dy[0][0] = 1;
	for (int k = 1; k <= len; k++) { // ��ü �ڸ���
		dy[k][0] = 0;
		for (int j = 1; j <= k; j++) { // 0�� �ƴ� ������ ��
			int cnt = 0;
			for (int i = k - 1; i >= 0; i--) {
				cnt += dy[i][j - 1];
			}
			dy[k][j] = 9 * cnt;
		}
	}
}


int main(void) {
	char str[200];
	scanf("%s %d", &str, &n);
	
	int dap = 0;
	int len = strlen(str);


	init(len);

	for (int i = 1; i <= len; i++) { // Ȯ���� �ڸ� ��

		// �� ���� 0�϶�
		if (len - i > 0) {
			for (int k = len - i; k >= 0; k--) {
				int a = k, b = n - (i - 1);
				dap += dy[a][b];
			}
		}

		if (i > n) break;

		int temp_n = str[i-1] - '0';
		if (temp_n >= 1) {
			int cnt = 0;
			for (int k = len - i; k >= 0; k--) {
				int a = k, b = n - i;
				cnt += dy[a][b];
			}
			dap += (temp_n - 1) * cnt;
		}

	}


	for (int i = 0; i < len; i++) {
		if (str[i] != '0') n--;
	}
	if (n == 0) dap++;
	printf("%d", dap+1);

	return 0;
}