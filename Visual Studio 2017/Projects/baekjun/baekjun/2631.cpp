// LIS로서 만들고자 하는 상태와 처음 상태에서    바꿀 필요가 없는 가장 큰 부분을 기준으로   나머지 것들은 자리를 바꿔야 할 수 밖에 없다는 것을 알아야.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n;
int data[300];
int dy[300];

int main()
{
	int t1;

	fscanf(stdin, "%d", &n);
	for (int i = 1; i <= n; i++) {
		fscanf(stdin, "%d", &data[i]);
	}
	
	for (int i = 1; i <= n; i++) {
		int max = -1;
		for (int j = 1;j <= i - 1;j++) {
			if (max < dy[j] && data[i] > data[j]) {
				max = dy[j];
			}
		}
		dy[i] = max + 1;
	}
	
	int dap = -1;
	for (int i = 1;i <= n;i++) {
		if (dap < dy[i])
			dap = dy[i];
	}

	fprintf(stdout, "%d", n - dap - 1);
	return 0;
}
