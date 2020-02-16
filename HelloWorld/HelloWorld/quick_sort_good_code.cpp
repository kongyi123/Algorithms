#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[100];

void quick_sort(int s, int e)
{
	int p = arr[(s + e) / 2];
	int l = s, r = e;

	do
	{
		while (arr[l] < p)l++;
		while (p < arr[r])r--;

		if (l <= r)
		{
			char tmp = arr[l];
			arr[l] = arr[r];
			arr[r] = tmp;
			l++;
			r--;
		}
	} while (l <= r);
	if (s < r) quick_sort(s, r);
	if (l < e) quick_sort(l, e);
}


int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n;i ++) {
		scanf("%d", &arr[i]);
	}

	quick_sort(1, n);

	for (int i = 1; i <= n; i++) {
		printf("%3d", arr[i]);
	}
	return 0;
}