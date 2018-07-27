#include <cstdio>
#include <algorithm>
#define MAX_N 250001
#define MAX 65536
using namespace std;
typedef long long ll;
ll seg[4 * MAX_N], a[MAX_N], n, k, res;
ll update(ll pos, ll val, ll node, ll x, ll y) {
	if (y < pos || pos < x)
		return seg[node];
	if (x == y)return seg[node] += val;
	ll mid = (x + y) >> 1;
	return seg[node] = update(pos, val, node * 2, x, mid) + update(pos, val, node * 2 + 1, mid + 1, y);
}
ll query(ll val, ll node, ll x, ll y) {
	ll mid = (x + y) >> 1;
	if (x == y)return x;
	if (seg[node * 2] >= val)return query(val, node * 2, x, mid);
	return query(val - seg[node * 2], node * 2 + 1, mid + 1, y);
}
int main() {
	scanf("%lld%lld", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	for (int i = 0; i < k - 1; i++)
		update(a[i], 1, 1, 0, MAX - 1);
	for (int i = k - 1; i < n; i++) {
		update(a[i], 1, 1, 0, MAX - 1);
		res += query((k + 1) / 2, 1, 0, MAX - 1);
		update(a[i - k + 1], -1, 1, 0, MAX - 1);
	}
	printf("%lld", res);
	return 0;
}

