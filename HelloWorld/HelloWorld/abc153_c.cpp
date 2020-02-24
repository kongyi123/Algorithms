#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <stdio.h>
 
using namespace std;
 
int dat[200010];
int a, b;
 
int main(void) {
	scanf("%d %d", &a, &b);
  	for (int i = 1;i <= a;i ++) {
      scanf("%d", &dat[i]);
    }
  	sort(&dat[1], &dat[1]+a);
  	long sum = 0;
  	for (int i = 1;i <= a-b;i ++) {
    	sum += dat[i];
    }
  	printf("%ld", sum);
  	return 0;
}