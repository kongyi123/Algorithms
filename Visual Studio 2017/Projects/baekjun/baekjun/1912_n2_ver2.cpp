// ������ġ...

// n ^ 2

// ������ ���� �ƴϰ�
// �ߺ��Ǵ� �κ��� ���Ǹ� �ð� ������� /n��ŭ ���� ���� �ִ�.

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int data[110000];

int main(void) {
	int n;
	int max = -2000000000;
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		fscanf(stdin, "%d", &data[i]);
	}

	for (int i = 1;i <= n;i++) {	// ������
		int sum = 0;
		for (int j = i;j <= n;j++) {	// ����
			sum += data[j];
			if (max < sum) max = sum;
		}
/*
		for (int j = i;j <= n;j++) {		// ����
			int sum = 0;
			for (int k = i;k <= j;k++) {	// ���������� ���� ���� ��ȸ
				sum += data[k];			
				if (max < sum) max = sum;
			}
		}

		1, +2, +3, +4, +5, +6
		2, +3, +4 ,+5, +6
		3, +4, +5, +6
		4, +5, +6
		5, +6
		6



		// ��ġ�� �κ��� ������ �ִ� �����ΰ�??

		// 
*/

	}

	fprintf(stdout, "%d", max);

}