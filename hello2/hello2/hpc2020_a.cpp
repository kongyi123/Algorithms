#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char str[15];
	scanf("%s", str);
	if (strlen(str) % 2 != 0) {
		printf("No");
		return 0;
	} 
	else {
		for (int i = 0; i < strlen(str); i+=2) {
			if (!(str[i] == 'h' && str[i + 1] == 'i')) {
				printf("No");
				return 0;
			}
		}
	}
	printf("Yes");

	return 0;
}