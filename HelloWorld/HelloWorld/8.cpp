#include <stdio.h>

int main(void) {

	for (int k = 1; k <= 3; k++) {
		for (int j = 1; j <= k; j++) 
			printf("*");
		printf("\n");
	}
	return 0;
}