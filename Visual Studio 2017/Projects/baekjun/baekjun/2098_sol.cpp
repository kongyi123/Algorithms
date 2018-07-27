#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <algorithm>
#define MAX_VALUE 987654321.0

using namespace std;
int n;

int cache[17][65536], dist[17][17];

// �� ������ ���ɴ�.
// visitid => ��Ʈ ����ũ�� �̹� �湮�� �������� üũ
// cache[���� ��ġ][������ �湮�� ����] => �޸������̼��� ���� 

int TSP(int cur, int visited) {
	// ���� 10����� 10000000000 - 1 = 01111111111
	// ��, ���� �� �湮�ߴٸ�
	if (visited == (1 << n) - 1) return dist[cur][0];

	int &ret = cache[cur][visited];		// �޸������̼� �迭�� �̹� ������ �ִٸ�
	if (ret != 0) return ret;			// ���� ���� ������ �ʰ� ����.

	// ���� ó�� ���ϴ� �Ŷ��, 

	// ���� visited���� cur���� üũ�� �� ��Ȳ�̴�.
	ret = MAX_VALUE;					
	for (int next = 0; next <= n; next++) {					// ������ �湮�� ��� �ĺ� ��ȸ
		if (visited&(1 << next)) continue;					// ������� �̹� �湮�� ���� ������ ��ŵ				
		if (dist[cur][next] == 0) continue;					// ���� cur�� next�� ���ų� �׷��� ���� ��쳪 ���� ������ ���� ���°�� 
		ret = min(ret, TSP(next, visited | (1 << next)) + dist[cur][next]);
		
		// ���� ���¿��� ��� ���ٰ� �� ������� 
		
		// TSP(next, visited) ����  state(next,vitited) ������ �������� �������� return �ǳ�? 
		// backtracking���� ���̴�.
	

		// return func(); �̷������� �ۼ��ϸ� �� ���� ������ �������� ���� ���� �� �׺��� �� �ٷ� �� �ܰ� ū ������ ��������
		//					���ϴ� ������ ���� �������� ù layer�� ������ ���� ��ȯ�ϸ鼭 ����ȴ�.

	}
	return ret;	// ���翡�� ���� �ܰ�� ���µ� (��� ��������) �� ���� ���� �������� return �ϴ� ��.
}

int main(void) {
	scanf("%d", &n);
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			scanf("%d", &dist[i][j]);			// ���� ����� �Է¹޴´�.
		}
	}
	printf("%d", TSP(0, 1));
	return 0;
}