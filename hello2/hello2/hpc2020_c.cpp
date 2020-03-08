#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <unordered_map>

using namespace std;

int n, t;
int a[200000], b[200000];
bool check[200000];
unordered_map<int, int> map;

int main(void) {
	scanf("%d%d", &n, &t);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &a[i], &b[i]);
	}

	map[1] = 2;

	int time = 1;
	int cnt = 0, p;
	for (int i = 1; i <= n; i++) {
		if (time > t) break;
		int min = 2000000000;
		for (int j = 1; j <= n; j++) {
			if (check[j]) continue;
			if (min > time* a[j] + b[j]) {
				min = time * a[j] + b[j];
				p = j;
			}
		}
		if (min != 2000000000) {
			check[p] = 1;
			if (time + min > t) break;
			time += min + 1;
			cnt++;
		}
		
	}

	printf("%d", cnt);
	return 0;
}