// 16 -18

// �̾�.....
// �޸� ������ �Ƴ� �����...?? �ʹ� ���� ����� �ִµ�... �װ� ���ø��� ���߱���... �Ф�
// ���̷��� Ǯ�̿��� �����ϰ� �Ƴ�..

// �ٵ� �ʹ� ��å�Ұ;���. ������ �뷮��� ���� �� ����� ���� ���;ߵǴµ� �ȳ��Դٴ� �Ϳ� ���� ����� ����.
// �̻��¿��� ��� �ذ��ؾ����� ����� �Ϸ��� �������� �ʾұ� �����̴�.


// �����̵� �������????
// �� ���� ( Ư�� ���� )�� �������� ���� ���ϴ� �˰����� �ǹ�.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
int dat[100001][3];
int min[3][3];
int max[3][3];

int MIN(int a, int b) {
	if (a > b) return b;
	return a;
}

int MAX(int a, int b) {
	if (a > b) return a;
	return b;
}

int main(void) {
	scanf("%d", &N);
	for (int i = 0;i < N;i++) {
		scanf("%d%d%d", &dat[i][0], &dat[i][1], &dat[i][2]);
	}
	
	int t;
	int i;
	for (i = 0;i < N;i++) {
		t = i % 2;
		min[t][0] = dat[i][0] + MIN(min[1-t][0], min[1-t][1]);
		min[t][1] = dat[i][1] + MIN(MIN(min[1-t][0], min[1-t][1]), min[1-t][2]);
		min[t][2] = dat[i][2] + MIN(min[1-t][1], min[1-t][2]);
		max[t][0] = dat[i][0] + MAX(max[1-t][0], max[1-t][1]);
		max[t][1] = dat[i][1] + MAX(MAX(max[1-t][0], max[1-t][1]), max[1-t][2]);
		max[t][2] = dat[i][2] + MAX(max[1-t][1], max[1-t][2]);
	}
	t = i % 2;
	printf("%d %d", MAX(MAX(max[1-t][0], max[1-t][1]), max[1-t][2]), MIN(MIN(min[1-t][0], min[1-t][1]), min[1-t][2]));
	return 0;
}