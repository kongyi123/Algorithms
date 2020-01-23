#include <stdio.h>

int main(void) {

	for (int i = 1; i <= 9; i = i + 2) 
	{
		printf("2 * %d = %d\n", i, 2*i);

		/*
			2 * 1 = 2
			2 * 3 = 6
			2 * 5 = 10
			2 * 7 = 14
			2 * 9 = 18

		*/
	}
	

	return 0;
}
