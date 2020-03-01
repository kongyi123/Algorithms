// type conversion VS if VS 조건부 연산자(?:) 속도비교

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

short arr[10000];
unsigned arr2[10000];

int main(void) {
	int n = 10000;

	for (int i = 1; i <= n; i++) arr[i] = -12398;
	
	for (int i = 1; i <= 100000000; i++); // delay time buffer clear


	time_t st = clock();

	for (int j = 1; j <= 300000; j++) {
		for (int i = 1; i <= n; i++) {
			arr2[i] = (unsigned short)arr[i];
		}
	}

	time_t en = clock();

	printf("type conversion time : %lld\n", en - st);


	for (int i = 1; i <= 100000000; i++); // delay time buffer clear


	st = clock();
	for (int j = 1; j <= 300000; j++) {
		for (int i = 1; i <= n; i++) {
			if (arr[i] < 0) {
				arr2[i] = arr[i] + 32767;
			}
			else arr2[i] = arr[i];
		}
	}

	en = clock();
	printf("if time2 : %lld\n", en - st);

	for (int i = 1; i <= 100000000; i++); // delay time buffer clear


	st = clock();
	for (int j = 1; j <= 300000; j++) {
		for (int i = 1; i <= n; i++) {
			arr2[i] = arr[i] ? arr[i] : arr[i] + 32767;
		}
	}

	en = clock();
	printf("conditional expressions(?:) time3 : %lld", en - st);


	return 0;
}