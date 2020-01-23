#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {



	int value;
	
	scanf("%d", &value);

	if (value >= 50) {
		printf("50 이상입니다.");
	}
    
	if (value == 50) {
		printf("50 입니다.");
	} 
	else if (value < 50) {
		printf("50 미만입니다.");
	}
	// 40 : 50 미만입니다.
	// 50 : 50 이상입니다.
	// 60 : 50 이상입니다.

	// 40 : 50 미만입니다.
	// 50 : 50 이상입니다. 50 입니다.
	// 60 : 50 이상입니다.

	return 0;
}