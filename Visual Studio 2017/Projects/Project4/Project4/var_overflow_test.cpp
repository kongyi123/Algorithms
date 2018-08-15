#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
const int MOD = 100003;

inline int mod(long long n) {
//	if (n >= 0) return n % MOD; 
	return ((-n / MOD + 1)*MOD + n) % MOD;
	//	return n % MOD;
}


int main(void) {
/*
	<변수값 순환>
	unsigned int 경우에는 0 ~ 4294967295   의 범위가 반복순환  (4294967296개의 수) 
	int 경우에는 -2147483648 ~ 0 ~ 2147483647 의 범위가 반복순환 (4294967296개의 수)

*/	
	
	
	int a = mod(10000000000000000000);
	int b = mod(10000000000000000005);

	unsigned int c = 0x7fffffff * 2 + 1;	// 4294967295
	unsigned int c2 = 0x7fffffff * 2 + 2;	// 0
	int d = 0x7fffffff + 1;					// -2147483648
	int d2 = 0x7fffffff + 2;				// -2147483647
	int d3 = 0x7fffffff + 0x7fffffff;		// -2
	int d4 = 0x7fffffff + 0x7fffffff + 0x7fffffff+ 10;		// -2147483641
	int d5 = 0x7fffffff + 0x7fffffff + 2 + 0x7fffffff + 1;	// -2147483648
	
	
	return 0;

	// integer => -2147483648 ~ 0 ~ 2147483647
}