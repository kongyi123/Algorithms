#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{

	int math, english, total;

	printf("�������� �Է�?");
	scanf("%d", &math);
	printf("�������� �Է�?");
	scanf("%d", &english);

	total = math + english;
	printf("���� ������ %d ��\n", math);
	printf("���� ������ %d ��\n", english);
	printf("������ %d ��\n", total);

	return 0;
}
