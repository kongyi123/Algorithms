// 알고리즘 : 펜윅 트리
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>

using namespace std;

long long sum(vector<long long> &tree, int i) {
	long long ans = 0;
	while (i > 0) {
		ans += tree[i];			
		i -= (i & -i);			// 가장 낮은 자리의 이분 영역의 값을 하나씩 빼가며 값을 더한다.
	}
	return ans;
}

void update(vector<long long> &tree, int i, long long diff) {
	while (i < tree.size()) {
		tree[i] += diff;		// 더해주는데
		i += (i & -i);			// 자신의 이분 영역에 더해준다. 
	}
}

int main() {
	int n, m, k;
	
	scanf("%d %d %d", &n, &m, &k);		// N : 데이터 수
	vector<long long> a(n + 1);			// M : 수의 변경이 일어나는 횟수
	vector<long long> tree(n + 1);		// K : 구간의 합을 구하는 횟수
	
	for (int i = 1; i <= n; i++) {		// 데이터 입력
		scanf("%lld", &a[i]);
		update(tree, i, a[i]);			// 트리에 업데이트
										// tree라는 벡터에 i번째 데이터에 해당하는 부분들에 a[i]만큼 더해준다.
	}

	m += k;
	while (m--) {
		int t1;
		scanf("%d", &t1);				// 입력 유형
		if (t1 == 1) {					// 유형이 1인 경우 => t2번째 수를 t3으로 변경
			int t2;
			long long t3;
			scanf("%d %lld", &t2, &t3); 
			long long diff = t3 - a[t2];	// t2번째 수에다가 diff만큼 값을 증가 시켜 줘서 t3으로 만든다.
			a[t2] = t3;						// 데이터의 val값도 변경해줌을 잊지 않는다.
			update(tree, t2, diff);			// 변경 업데이트
		}
		else {
			int t2, t3;
			scanf("%d %d", &t2, &t3);	// 유형이 2인 겨우 => t2 에서 t3 번째에 해당하는 값들의 합을 출력
			printf("%lld\n", sum(tree, t3) - sum(tree, t2 - 1));
		}
	}
	return 0;
}