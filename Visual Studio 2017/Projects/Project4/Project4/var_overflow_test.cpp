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
	<������ ��ȯ>
	unsigned int ��쿡�� 0 ~ 4294967295   �� ������ �ݺ���ȯ  (4294967296���� ��) 
	int ��쿡�� -2147483648 ~ 0 ~ 2147483647 �� ������ �ݺ���ȯ (4294967296���� ��)

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