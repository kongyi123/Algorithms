// 이분 검색의 세밀한 조건들이 있다. 만만하게 보지 말자.
// 1. 최종 구해야 하는 값.
// 2. 어떤 기준이 되는 값.
// 1,2번이 다른 경우도 있고 같은 경우도 있다. 이 문제 같은 경우는 다르다.

// 46분 걸림

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int data[11000];

int n, m;

int check(int limit) { // rest를 만족 못하면 상한액을 줄여야 한다.
					   // rest는 충분히 만족하면  
	int rest = m;
	int max = 0;
	for (int i = 1;i <= n;i++) {
		if (data[i] <= limit) {
			rest -= data[i];
			if (max < data[i]) max = data[i];
		}
		else {
			rest -= limit;
			if (max < limit) max = limit;
		}
		if (rest < 0) return -1;
	}
	return max;
}

int main(void) {
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		fscanf(stdin, "%d", &data[i]);
	}
	fscanf(stdin, "%d", &m);

	int max = 0;
	int s = 1, e = 1000000000;
	while (s <= e) {
		int mid = (s + e) / 2;
		int result;
		if ((result = check(mid)) != -1) {
			if (max < result) max = result;
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}

	
	fprintf(stdout, "%d", max);

	return 0;
}