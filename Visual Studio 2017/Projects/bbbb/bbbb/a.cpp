#include <stdio.h>

int arr[100];

int search(int s, int e, int val) {
	while (s <= e) {
		int mid = (s + e) / 2;
		if (val == arr[mid]) s = mid + 1;
		else if (val < arr[mid]) e = mid - 1;
		else s = mid + 1;
	}
	return s;
}



int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 1;i <= n;i++) {
		scanf("%d", &arr[i]);
	}
	int val;
	scanf("%d", &val);

	fprintf(stdout, "\ndap = %d", search(1, n, val));
	return 0;
}
