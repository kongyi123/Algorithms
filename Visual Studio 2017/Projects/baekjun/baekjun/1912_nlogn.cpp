// nlogn
// 퀵소와 유사. 즉, 분할정복. 중요한기법이다.
// 중간, 좌측 덩어리, 우측덩어리 에서 봄
// 최대연속 부분합이기 때문에 중간서 부터 시작하는 덩어리가 가능한 것임

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MIN -2000000000

int data[110000];

int n;

int max(int a, int b) {
	if (a > b) return a;
	return b;
}

int fastMaxSum(int s, int e) {
	if (s <= e) {

		if (s == e) return data[s];

		int mid = (s + e) / 2;

		int left = MIN, right = MIN, sum = 0;
		for (int i = mid;i >= s;i--) {
			sum += data[i];
			if (left < sum) left = sum;
		}

		sum = 0;
		for (int i = mid + 1;i <= e;i++) {
			sum += data[i];
			if (right < sum) right = sum;
		}

		int single = max(fastMaxSum(1, mid), fastMaxSum(mid + 1, e));
		return max(single, left + right);
	}
}



int main(void) {
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		fscanf(stdin, "%d", &data[i]);
	}

	int result = fastMaxSum(1, n);

	fprintf(stdout, "%d", result);
	return 0;
}