// �̰͵� Ʋ�� ����� �ƴϰ� ��ȿ�� ���� ����� ���� ������, ��� ���ؿ����� �޸� �ʰ��� ���� �� �ִ�. �Ϲ������� n x m�� �迭�� ������
// mũ���� �迭 �ΰ��� �ְ� �޾� ���� �޸� �ʰ� ���� ä����� "�¾ҽ��ϴ�" ���´�.
// �޸𸮸� ��������� �������δ� �ʰ� �ƴѵ�... ��....  �ƹ�ư
// �׻� �̷��� ����� �� ���� �ΰ����� ������ �� �� �ֵ��� ����. ����ó�� �ϰų� Ȥ�� ���Ʈ ������ �ϰų�

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define IN stdin
#define OUT stdout
#define M 1000000

//FILE *out = fopen("output.txt", "w");
//FILE *in = fopen("input.txt", "r");

int data[22];
int n, m;
int dy[2][2000100];

int main(void) {
	fscanf(IN, "%d%d", &n, &m);
	for (int i = 1;i <= n;i++) {
		fscanf(IN, "%d", &data[i]);
	}
	
	int i, j;
	int A, B;
	for (i = 1;i <= n;i++) {
		if (i % 2 == 0) {
			A = 0; B = 1;
		}
		else {
			A = 1; B = 0;
		}
		for (j = 2000000;j >= 0;j--) dy[B][j] = 0;
		for (j = 2000000;j >= 0;j--) {
			if (dy[A][j] > 0) {
				dy[B][j + data[i]] += dy[A][j];
				dy[B][j] += dy[A][j];
			}
		}
		dy[B][data[i] + M] = dy[B][data[i] + M] + 1;
	}
	
	fprintf(OUT, "%d", dy[B][M + m]);

	return 0;
}