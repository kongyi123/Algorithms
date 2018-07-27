// 13분 + alpha
// 이분검색의 평가 기준이 되는 값 != 우리가 구하고자 하는 값

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int data[11000];
int n, m;

int eval(int limit) {
	int sum = 0;
	int max = 0;
	for (int i = 1;i <= n;i++) {
		if (limit > data[i]) {
			sum += data[i];
			if (max < data[i])
				max = data[i];
		}
		else {
			sum += limit;
			if (max < limit) 
				max = limit;
		}
	}

	if (sum > m) return -1;	// 배정 불가 판정
	return max;	// 배정된 예산들 중 최대값인 정수
}

int main(void) {
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		fscanf(stdin, "%d", &data[i]);
	}
	fscanf(stdin, "%d", &m);

	int s = 1, e = 100000;
	int result;
	int ans = 0;

	// 인덱스 관련된건 이렇게 해도 되는데
	// 어떤 값의 결정에 대한 이분검색은 while 조건문에 = 가 들어가야
	// 예를들어 1 같은 경우에 mid 값이 접근을 할 수가 없게 됨.
	while (s <= e) {
		int mid = (s + e + 1) / 2;
		if ((result = eval(mid)) != -1) {	
			if (ans < result) ans = result;				
			s = mid;
			if (s == e) break;
		}
		else {
			e = mid - 1;
		}
	}

	fprintf(stdout, "%d", ans);
	return 0;
}