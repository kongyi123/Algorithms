#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int main(void) {
	srand((unsigned int)NULL(time));
	int s = rand() % 100 + 1;
	int input, cnt = 0;
	while (1) {
		cnt++;
		printf("input number : ");
		scanf("%d", &input);
		if (input > s) printf("down\n");
		else if (input < s) printf("up\n");
		else {
			printf("correct!\n %d times tried.\n", cnt);
			break;
		}
	}
	_getch();
	return 0;
}