// 그거로 한번 풀어보자.
// 정렬안하고 비트로 체크하기

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main(void) {
	int n;
	int arr[200002];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr, arr + n);
	
	int er = 0;
	for (int i = 0; i < n-1; i++) {
		if (arr[i] == arr[i + 1]) {
			er = 1;
			break;
		}
	}

	if (er) printf("NO");
	else printf("YES");
	return 0;
}