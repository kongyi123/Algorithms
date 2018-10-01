// 40

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

using namespace std;
char arr[30];
int N, K;
int list[30], lcnt;

bool cmp(int a, int b) {
	if (a > b) return 1;
	return 0;
}

void rotate() {
	char temp;
	temp = arr[N];
	for (int i = N;i >= 2;i--) {
		arr[i] = arr[i - 1];
	}
	arr[1] = temp;
}

int HtoD(char input[]) {
	int t = 1;
	int sum = 0;
	for (int i = N/4 - 1;i >= 0;i--) {
		if (input[i] >= '0' && input[i] <= '9') {
			sum = sum + (input[i] - '0') * t;
		}
		else {
			sum = sum + (input[i] - 'A' + 10) * t;
		}
		t = t * 16;
	}

	return sum;
}

void cut() {
	for (int i = 1;i <= N;i += N/4) {
		list[lcnt++] = HtoD(&arr[i]);
	}
}

int process() {
	int ans = 0;
	for (int i = 1;i <= N / 4;i++) {
		cut();
		rotate();
	}

	sort(list, list + lcnt, cmp);

	int cnt = 0;
	for (int i = 0;i < lcnt;i++) {
		if (i > 0 && list[i] == list[i - 1]) continue;
		cnt++;
		if (cnt == K) {
			ans = list[i];
			break;
		}
	}
	return ans;
}

void init() {
	for (int i = 0;i < 30;i++) arr[i] = 0;
	for (int i = 0;i < 30;i++) list[i] = 0;
	lcnt = 0;
}

int main(void) {
	int T;
	scanf("%d", &T);
	for (int tc = 1;tc <= T;tc++) {
		init();

		scanf("%d%d", &N, &K);
		scanf("%s", &arr[1]);
		printf("#%d %d\n", tc, process());
	}
	return 0;
}