// LIS�μ� ������� �ϴ� ���¿� ó�� ���¿���    �ٲ� �ʿ䰡 ���� ���� ū �κ��� ��������   ������ �͵��� �ڸ��� �ٲ�� �� �� �ۿ� ���ٴ� ���� �˾ƾ�.

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
