#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#define IN in

FILE *in = fopen("input.txt", "r");

int type, id, size;

int print();
int deletion();
int assign();

int check_assign();
int check_deletion();

int block_count;

int main(void) {

	int n;
	fscanf(IN, "%d", &n);
	for (int i = 1;i <= n;i++) {
		fscanf(IN, "%d", &type);
		if (type == 0) { // 블록의 수, 사용자에 따른 자원 할당 디스크 공간 출력 
			print();
		}
		else if (type == 1) { // 할당
			fscanf(IN, "%d %d", &id, &size);
			int msg = assign();
			if (msg != 0) fprintf(stdout, "할당 에러\n");
			check_assign();
		}
		else if (type == 2) { // 삭제
			fscanf(IN, "%d", &id);
			deletion();
			check_deletion();
		}
	}

	fprintf(stdout, "\n\n\npress any key...\n"); _getch(); // 디버깅용
	return 0;
}