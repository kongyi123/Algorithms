#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;
#define MAX 100

int data[MAX][MAX];
int dy[MAX][MAX];
int cnt[100];
int N;

void input() {
	fscanf(stdin, "%d", &N);
	for (int i = 1;i <= N;i++) {
		char t;
		fscanf(stdin, "%c", &t);
		for (int j = 1;j <= N;j++) {
			fscanf(stdin, "%c", &data[i][j]);
		}
	}
}

int max(int a, int b) {
	if (a > b) return a;
	return b;
}

void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}

void clear() {
	for (int i = 1;i <= N;i++)
		for (int j = 1;j <= N;j++)
			dy[i][j] = 0;
}

int count() {
	int cnt = 0;
	clear();
	for (int i = 1;i <= N;i++) {
		for (int j = 2;j <= N;j++) {
			if (data[i][j] == data[i][j - 1]) {
				dy[i][j] = dy[i][j - 1] + 1;
				cnt = max(cnt, dy[i][j]);
			}
		}
	}
	// ok

	clear();
	for (int j = 1;j <= N;j++) {
		for (int i = 2;i <= N;i++) {
			if (data[i - 1][j] == data[i][j]) {
				dy[i][j] = dy[i - 1][j] + 1;
				cnt = max(cnt, dy[i][j]);
			}
		}
	}
	// ok.
	return cnt+1;
}

int main(void) {
	input(); // ok.

	int ans = 0;  
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N - 1;j++) {
			swap(data[i][j], data[i][j + 1]);
			ans = max(ans, count());
			swap(data[i][j], data[i][j + 1]);

		}
	}

	for (int i = 1;i <= N - 1;i++) {
		for (int j = 1;j <= N;j++) {
			swap(data[i][j], data[i + 1][j]);
			ans = max(ans, count());
			swap(data[i][j], data[i + 1][j]);
		}
	}

	fprintf(stdout, "%d\n", ans);

	return 0;
}