// 50.... ��Ÿ����. �̰� 50�аɷȴٴ�..
// �޸� �ʰ����پ˰� �ٸ� ����� ����ߴ�.
// �ϴ� ���ķ� Ǯ��.

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