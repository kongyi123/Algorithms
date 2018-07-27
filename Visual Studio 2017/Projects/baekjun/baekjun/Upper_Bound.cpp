// a값을 초과하는 값이 처음 발견되는 위치를 의미

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <algorithm>

using namespace std;

int dat[100];
int n;

int main(void) {
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		fscanf(stdin, "%d", &dat[i]);
	}

	int a;
	fscanf(stdin, "%d", &a);

	int s, e;
	s = 1, e = n;
	while (s < e) {
		int mid = (s + e) / 2;
		if (a == dat[mid]) s = mid+1;
		else if (a < dat[mid]) e = mid;
		else s = mid+1;
	}

	fprintf(stdout, "%d\n", s);
	fprintf(stdout, "%d", std::upper_bound(dat + 1, dat + n, a) - dat);
	// std::lower_bound(dat+1, dat1+n, a) 는 주소 절대 위치
	// 따라서 -dat 을 붙여야 배열에서의 인덱스.
	return 0;
}