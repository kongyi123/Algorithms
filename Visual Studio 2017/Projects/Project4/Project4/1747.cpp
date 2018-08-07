#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAX 1003001

bool check[MAX+10]; // 소수인지

char str[7];
int len, mid;

bool isPalindrome(const int in) {
	sprintf(str, "%d", in);
	len = strlen(str);
	mid = len / 2;
	for (int i = 0;i < mid;i++) {
		if (str[i] != str[len - i - 1]) return false;
	}
	return true;


	/*	int val = in, pval = 0;
		while (pval < val) {
		pval *= 10;
		pval += (val % 10);
		val = val / 10;
	}

	if (pval == val || pval/10 == val) return true;
	return false;
	*/


} // ok

int main(void) {
//	freopen("input.txt", "r", stdin);
	int N; // 에라토스테네스의 체(?)
	scanf("%d", &N);
	check[1] = 1;
	int root = (int)sqrt((double)MAX);
	for (int i = 2;i <= root;i++) {
		for (int j = i + i;j <= MAX;j += i) {
			check[j] = 1;
		}
	}

/*
// test code 
	printf("%d\n", check[2]);
	printf("%d\n", check[3]);
	printf("%d\n", check[4]);
	printf("%d\n", check[5]);
	printf("%d\n", check[19]);
*/

/* // test code
	bool c;
	printf("%d\n", isPalindrome(12321));
	printf("%d\n", isPalindrome(123));
	printf("%d\n", isPalindrome(131));
	printf("%d\n", isPalindrome(2332));
	printf("%d\n", isPalindrome(11112));
*/


	for (int i = N;i <= MAX;i++) {
		if (check[i] == 0 && isPalindrome(i)) {
			printf("%d", i);
			return 0;
		}
	}

	return 0;
}


