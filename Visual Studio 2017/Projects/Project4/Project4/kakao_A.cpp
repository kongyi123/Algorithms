#include <stdio.h>

int main(void) {
	int N;
	fscanf(stdin, "%d", &N);
	for (int i = 1;i <= N;i++) {
		fprintf(stdout, "Welcome to Kakao Code Festival!\n");
	}

	return 0;
}