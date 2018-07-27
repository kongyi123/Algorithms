#include <stdio.h>

int lower_bound(int[], int, int);

int main()
{
	int arr[10] = { 1, 3, 4, 5, 7, 9, 12, 13, 15, 18 }; // �����͵��� ũ������� ���ĵǾ� �ִ� �����̴�.
	int target = 10; // �� �� �� ��° �ε������� 10 �̻��� �Ǵ��� ã�ƺ����� ����.
	int n = 10; // �迭�� ũ��
	printf("lower bound is arr[%d]\n", lower_bound(arr, target, n));
	return 0;
}

int lower_bound(int arr[], int target, int size)
{
	int mid, start, end;
	start = 0, end = size - 1;

	while (end > start) // end�� start���� ���ų� �۾�����, �� ���� Lower Bound�̹Ƿ� �ݺ��� �����Ѵ�.
	{
		mid = (start + end) / 2;
		if (arr[mid] >= target) // �߰����� ���ϴ� ������ ũ�ų� ���� ���, ������ �߰������� �����Ͽ� �ٽ� Ž���Ѵ�.
			end = mid;
		else start = mid + 1; // �߰����� ���ϴ� ������ ���� ���, ���۰��� �߰���+1�� �����Ͽ� �ٽ� Ž���Ѵ�.
	}
	return end;
}