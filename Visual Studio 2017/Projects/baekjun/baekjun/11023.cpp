#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define IN stdin

//FILE *in = fopen("input.txt", "r");

int main(void) {
	int sum = 0;
	while (1) { // while�� ���ο� feof ������ ������ �ƴ϶�
		int data;
		fscanf(IN, "%d", &data); 
		if (feof(IN)) break;			// �ݵ�� �߰��� �־���� �Ѵ�.  �׷��� ������ ������ ���� �ι� �޴� ��찡 ����
		sum = sum + data;
	}

	fprintf(stdout, "%d", sum);
	return 0;
}