// ���Ʈ ����
// �Ϲ����� �������� ���� ���� �޸� �ʰ����� (but Ư���ϰ� �� �迭�� �ְ� ������ �����)
// �׻� �̷��� ����� �� ���� ��Ʈ�� �ΰ����� ������ �� �� �ֵ��� ����. ����ó�� �ϰų� Ȥ�� ���Ʈ ������ �ϰų�

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define IN stdin
#define OUT stdout
#define MAX 1058576

//FILE *out = fopen("output.txt", "w");
//FILE *in = fopen("input.txt", "r");

int data[22];
int n, m;
int dy[MAX];

int main(void) {
	fscanf(IN, "%d%d", &n, &m);
	for (int i = 1;i <= n;i++) {
		fscanf(IN, "%d", &data[i]);
	}

	int i, j;
	int k = 0;
	int dap = 0;
	for (i = 1;i <= n;i++) {
		int cnt = 0;
		for (j = 0;j <= k;j++) {
			cnt ++;
			dy[k + cnt] = dy[j] + data[i];
			if (dy[k + cnt] == m) dap++;
		}
		k = k + cnt;
	}

	fprintf(OUT, "%d", dap);


	return 0;
}