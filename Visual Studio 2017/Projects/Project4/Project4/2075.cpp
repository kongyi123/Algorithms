// 50.... 안타깝다. 이게 50분걸렸다니..
// 메모리 초과날줄알고 다른 방법을 고민했다.
// 일단 정렬로 풀림.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

using namespace std;

int N;
int arr[1500*1500];

int main(void) {
	scanf("%d", &N);
	for (int i = 0;i < N*N;i++) {
		int dat;
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + N*N);
	printf("%d", arr[N*N-N]);
	return 0;
}