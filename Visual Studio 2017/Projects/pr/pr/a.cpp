#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>
using namespace std;
int k, n, cnt, ck[100001], mini = 2e9, res, l, r;
pair<int, int> p[1000000];
int main() {
	scanf("%d%d", &k, &n);
	for (int i = 0; i < n; i++) scanf("%d%d", &p[i].first, &p[i].second);
	sort(p, p + n);
	while (r < n) {
		cnt += !ck[p[r++].second]++;
		while (cnt == k) {
			int t = p[r - 1].first - p[l].first + 1 >> 1;
			if (t < mini) mini = t, res = p[r - 1].first - t;
			cnt -= !--ck[p[l++].second];
		}
	}
	printf("%d", res);
	return 0;
}