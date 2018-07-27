// ��, bitmask dp��
// check[2][2][2][2][2][2][2][2][2][2] = 1;
// �̷������� �ڵ��ϱ�� ��ǻ� �Ұ��� �ϱ� ������ �̰��� 2,3����ȭ �Ͽ� üũ�� �ϴ�... �׷��� üũ ����� �� ���̳����� �ǹ��Ѵ�.

#define _CRT_SECURE_NO_WARNINGS
#include<functional>
#include<algorithm>
#include<iostream>
#include<climits>
#include<cstring>
#include<iomanip>
#include<cstdio>
#include<vector>
#include<string>
#include<limits>
#include<cmath>
#include<stack>
#include<queue>
#include<list>
#include<set>
#include<map>
#define IN in
#define OUT out
using namespace std;

FILE *in = fopen("input.txt", "r");
FILE *out = fopen("output.txt", "w");

int dp[11][1 << 11];
char board[11][11];
int n, m;

int check(int current, int previous) {
	for (int i = 1; i < (1 << m); i <<= 1) {
		if ((current & i)) {	// �̹� ���� i��° ���� �л��� �ɾ� ������
			if ((previous & (i * 2)) || (previous & (i / 2))) // ���� ���� i-1 or i+1 ��° ���� �л��� �ɾ� ������
				return false;	// fail�̴�.
		}
	}
	return true;
}
int visited[11] = { 0 };

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int t;
	fscanf(IN, "%d", &t);	// �׽�Ʈ ���̽� �Է�
	while (t--) {		// �׽�Ʈ ���̽� �ݺ�
		
		// �ʱ�ȭ
		memset(dp, 0, sizeof(dp));		
		memset(dp, 0, sizeof(board));
		
		// �Է�
		fscanf(IN, "%d %d", &n, &m);
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < m; j++) {
				fscanf(IN, "%c", &board[i][j]);
			}
		}




		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < (1 << m); j++) { // 1 << m   =>    2�� m��  , ��, �л��� ���� �� �ִ� ��� ���¸� �ǹ�
				
				
				// 1. ���ӵ� �ڸ� �������� ����
				// 2. ������� �ɾ� �ִ� ������ üũ
				int mmax = 0, bit = 0; 
				bool isPossible = true;
				int idx = m - 1;
				for (int k = 1; k < (1 << m); k <<= 1) {				//		k = 0001, 0010, 0100, 1000
					if ((j & k) && board[i][idx] == '.') bit++;			// �� �ڸ��� ����� �̸� ++
					if (j & k && j & (k << 1)) {	// ���ɼ� Ȯ��  (	// k << 1 = 0010, 0100, 1000, ...
						isPossible = false;								// ���� �ٷ� ���ڸ��� �л��� �ִٰ� �ߴٸ�.. �װ��� ���� ��, 0110 �̷������� �ڸ� ������ �������� �� ���¸� �����ϰ� ����Ϸ���
						break;
					}
					idx--;
				}
				if (!isPossible) continue;	// ���ӵ� �ڸ������� ����
				
				

				int a = 0;
				for (int k = 0; k < (1 << m); k++) {
					if (check(j, k)) {	 // �̹� �࿡�� ������ ���� �� üũ �� �����ϸ� ���߿��� max ���� ����
						if (mmax < dp[i - 1][k]) {
							mmax = max(dp[i - 1][k], mmax);
							a = k;
						}

					}
				}
				dp[i][j] = mmax + bit; // �̹� �࿡ ���� �� �ִ� �ִ� �л��� + ���� ���� max
				ans = max(ans, dp[i][j]);			// �ִ밪 ����
			}
		}
		fprintf(OUT, "%d", ans);
	}
}