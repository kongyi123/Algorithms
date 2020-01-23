#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{

	int math, english, total;

	printf("수학점수 입력?");
	scanf("%d", &math);
	printf("영어점수 입력?");
	scanf("%d", &english);

	total = math + english;
	printf("수학 점수는 %d 점\n", math);
	printf("영어 점수는 %d 점\n", english);
	printf("총점은 %d 점\n", total);

	return 0;
}
