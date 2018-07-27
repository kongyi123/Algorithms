#include <stdio.h>

int lower_bound(int[], int, int);

int main()
{
	int arr[10] = { 1, 3, 4, 5, 7, 9, 12, 13, 15, 18 }; // 데이터들이 크기순으로 졍렬되어 있는 상태이다.
	int target = 10; // 이 중 몇 번째 인덱스부터 10 이상이 되는지 찾아보도록 하자.
	int n = 10; // 배열의 크기
	printf("lower bound is arr[%d]\n", lower_bound(arr, target, n));
	return 0;
}

int lower_bound(int arr[], int target, int size)
{
	int mid, start, end;
	start = 0, end = size - 1;

	while (end > start) // end가 start보다 같거나 작아지면, 그 값이 Lower Bound이므로 반복을 종료한다.
	{
		mid = (start + end) / 2;
		if (arr[mid] >= target) // 중간값이 원하는 값보다 크거나 같을 경우, 끝값을 중간값으로 설정하여 다시 탐색한다.
			end = mid;
		else start = mid + 1; // 중간값이 원하는 값보다 작을 경우, 시작값을 중간값+1로 설정하여 다시 탐색한다.
	}
	return end;
}