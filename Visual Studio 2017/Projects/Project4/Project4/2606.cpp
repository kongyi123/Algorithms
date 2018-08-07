#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int arr[110][110];
int visited[110];
int n, m;


int back(int c) {
	int	cnt = 0;
	for (int i = 1;i <= 100;i++) {
		if (arr[c][i] == 1 && visited[i] == 0) {
			visited[i] = 1;
			cnt += back(i) + 1;
		}
	}

	return cnt;
}

int main(void) {
	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 1;i <= m;i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a][b] = arr[b][a] = 1;
	}

	visited[1] = 1;
	printf("%d", back(1));
	
	return 0;
}