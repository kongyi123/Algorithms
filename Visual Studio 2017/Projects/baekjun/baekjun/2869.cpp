#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int a, b, v;
	double t1;
	int i_t1;

//	double t2;
	fscanf(stdin, "%d %d %d", &a, &b, &v);
	t1 = (double)(v - (2 * a) + b) / (a - b);
	i_t1 = int(t1*10);
	if (i_t1 % 10 > 0) i_t1 = i_t1 / 10 + 1;
	else i_t1 = i_t1 / 10;

	v = v - (i_t1*(a - b));

	int sum = 0;
	while (1) {
		sum = sum + a;
		i_t1++;
		if (sum >= v) break;
		sum = sum - b;
	}

	fprintf(stdout, "%d", i_t1);

	//t2 = (v - a) / (a - b);
	return 0;
}

/*

#include <iostream>
using namespace std;

int main() {
int a, b, v;
scanf("%d %d %d", &a, &b, &v);
v-=b;
int c=a-b;
int ans=v/c;
if (v%c!=0) ans+=1;
printf("%d", ans);
return 0;
}

		
v =		a-b a-b a-b x   ---->    1 <= x <= a
v-b =   a-b a-b a-b x-b

1) x=a,
a-b a-b a-b a-b
---------------		=   k
a-b

2) 1<=x<=a,
a-b a-b a-b x-b
---------------		=   (k-1) + 0.xxx
a-b

따라서 2)의 경우에는 ans+1 해줌
====> 다른것과 비슷한 형태로 바꿔주는 것도 풀이 관찰의 좋은 기술인듯.
*/