#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[100];
int n;


int search(int s, int e, int val) {
	while (s < e) {
		int mid = (s + e) / 2; // mid = (s + e + 1) / 2 가 되어도 상관이 없다. 왜냐하면 범위를 좁혀나갈 때 mid번째 첨자는 배제하기 때문이다.
		if (val == arr[mid]) return mid;
		else if (val < arr[mid]) e = mid - 1;
		else s = mid + 1;
	}

	if (val == arr[s]) return s;
	return -1;
}

int upper_bound(int s, int e, int val) {
	while (s < e) { // 아래 조건에 따른 s,e 결정 알고리즘 중에 e = mid가 있다. 무한 루프의 상황을 없애기 위해 = 을 뺀다.
		int mid = (s + e + 1) / 2;
		if (val == arr[mid]) s = mid + 1; // 기준 값 val 과 동일한 값이라면 우리가 찾는 값이 될 가능성이 없다. 따라서 mid 첨자는 배제
		else if (val < arr[mid]) e = mid; // 현재 주목하고 있는 mid 첨자에 있는 값이 우리가 찾는 값일 수도 있기 때문에 e = mid - 1 이 아닌 e = mid 이다.
		else s = mid + 1; // 기준 값 val 보다 작은 값이라면 우리가 찾는 값이 될 가능성이 없다. 따라서 mid 첨자는 배제       
	}
	if (s == n && arr[n] <= val) return n + 1;
	return s;
}


int main(void) {

	scanf("%d", &n);
	for (int i = 1;i <= n;i++) {
		scanf("%d", &arr[i]);
	}
	int val;
	while (1) {
		scanf("%d", &val);
		fprintf(stdout, "\ndap = %d\n\n", search(1, n, val));
//		fprintf(stdout, "\ndap = %d\n\n", upper_bound(1, n, val));
	}
	return 0;
}
