#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {



	int value;
	
	scanf("%d", &value);

	if (value >= 50) {
		printf("50 �̻��Դϴ�.");
	}
    
	if (value == 50) {
		printf("50 �Դϴ�.");
	} 
	else if (value < 50) {
		printf("50 �̸��Դϴ�.");
	}
	// 40 : 50 �̸��Դϴ�.
	// 50 : 50 �̻��Դϴ�.
	// 60 : 50 �̻��Դϴ�.

	// 40 : 50 �̸��Դϴ�.
	// 50 : 50 �̻��Դϴ�. 50 �Դϴ�.
	// 60 : 50 �̻��Դϴ�.

	return 0;
}