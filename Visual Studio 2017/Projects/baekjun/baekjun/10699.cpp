#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

int main(void) {
	time_t timer;
	timer = stime(NULL);

	return 0;
}