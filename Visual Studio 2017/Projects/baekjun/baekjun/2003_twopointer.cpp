// 투 포인터 알고리즘 : 시간복잡도 O(n)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() {
	int n, m, arr[10000];
	fscanf(stdin, "%d %d", &n, &m);
	
	for (int i = 1; i <= n; i++) {
		fscanf(stdin, "%d", &arr[i]);
	}

	int result = 0, sum = 0, lo = 1, hi = 1;

	while (lo <= n) {
		if (sum < m) sum = sum + arr[hi++];
		else if (sum == m) {
			result++;
			sum = sum - arr[lo++];
		}
		else {
			sum = sum - arr[lo++];
		}
	}

	fprintf(stdout,"%d\n", result);
}



