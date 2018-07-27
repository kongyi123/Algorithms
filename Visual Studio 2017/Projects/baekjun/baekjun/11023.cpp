#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define IN stdin

//FILE *in = fopen("input.txt", "r");

int main(void) {
	int sum = 0;
	while (1) { // while의 내부에 feof 조건을 넣을게 아니라
		int data;
		fscanf(IN, "%d", &data); 
		if (feof(IN)) break;			// 반드시 중간에 넣어줘야 한다.  그렇지 않으면 마지막 값을 두번 받는 경우가 생김
		sum = sum + data;
	}

	fprintf(stdout, "%d", sum);
	return 0;
}