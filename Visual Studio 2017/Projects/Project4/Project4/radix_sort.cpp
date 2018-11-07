// 숫자 기수 정렬

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>

using namespace std;

int N;

int main(void) {
	int arr[100];
	queue<int> radix[10]; // 자리수에 대한 큐 배열
	
	scanf("%d", &N);
	for (int i = 0;i < N;i++) {
		scanf("%d", &arr[i]);
	}

	int max = arr[0];
	int d = 1; // 최대자리수
			   // 최대 자리수를 구하기 위해서 최댓값을 찾아낸다.
	for (int i = 1; i < N; i++)
		if (max < arr[i]) max = arr[i];

	// 최대 자리수를 구해낸다.
	while (max / 10) {
		d *= 10;
		max /= 10;
	}

	int mod = 10;
	int dMin = 1;

	while (dMin <= d) {
		for (int i = 0; i < N; i++) {
			radix[(arr[i] % mod) / dMin].push(arr[i]);
			// 특정 자리의 숫자를 빼내서 그에 해당하는 위치에 데이터를 push
		}

		// 큐에 들어간 값들을 자리수 크기 순으로 다시 배열에 집어넣는다.
		int j = 0;
		for (int i = 0;i <= 9;i++) {
			while (radix[i].size() > 0) {
				arr[j++] = radix[i].front();
				radix[i].pop();
			}
		}

		// 하나 더 높은 자리수로 이동
		dMin *= 10;
		mod *= 10;

	}

	for (int i = 0; i < N; i++) printf("%3d ", arr[i]);

	return 0;
}