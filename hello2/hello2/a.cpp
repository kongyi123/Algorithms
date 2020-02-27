/*
// ������ �ϴ� �ð��� �����ɸ��°� �ƴ϶� 
// �򰥷��ϴ� �ð��� ���� �ð��� ���Դ´�.
// ��û���� �ð��� ��������. ���� �밡�ٸ� �ؼ� �����ϰ� ����°� ���� ���� ����̴�.



# �α׸� �� ����Ѵ�. [��� ¥��-�˻�] �ϴ� ���·� �ڵ��� �帧�� ������ �ƴ϶�, [����� ¥���߿� �ʿ��� �α����� ���] �ϴ� ���·� �ڵ��� �ؾ��Ѵ�.
�ΰ��� ������ 100���� �Ǽ��� �Ѵ�.
1. �Ǽ��� �ּ������� ����� ���� �����Ѵ�.
2. �Ǽ��� ������ �ʱ����� ������ �����.
3. �Ǽ��� �ϴ��� �װ��� ������ ã�� ��ĥ �� �ֵ��� �ؾ��Ѵ�.

> �� �Լ��� ������ ���� ������ ���� �����α�
> �߰� ������� Ȯ���ϴ� �α�

# null�� ����� ������ �� �� �ִ� ��� ���� ��츦 ������ �Ѵ�. �װ�, �ڵ��� ���� �ϼ��� �����ش�. (�̰� �ȵǸ� 1�ð����� Ǯ�� 24�ð��� �ɸ��� ������ �𸥴�. �̹��� ���� �� ������̴�.)



# �� ������ ��� ������ ���� ������ ������ ǥ�������� ����ġ ������, �򰥸��⵵ �߰� ���̽��� �ߺ����� �ʰ� �ϴ� �͵� �������. 
������ � ������ Ǯ�� ��� ������ ����ȭ �ϴ� ������ �Ǿ���� ���̴�. 

ex) 123 1
1-9 / 10-99 / 100~123 >> �� ������ ������ ����� �ϰ�, ���� ���� ������ �ڸ����� �ع����� 
�� 100-123 �� 100-109 / 110-123.....................

���� ����ϱ� ���� �� ���� �ִµ�, �̰� ��Ȯ�ϰ� ��� ���Ⱑ �����. ��ư "��� ������ ����ȭ �ϴ� ��������" �ϴ°� �ٽ��̴�.

# brute force�� TC üũ �Լ��� �ݵ�� ������. �̰� �����Ҷ��� �߿��ϴ�. �̰� ����ȭ �Ǿ�� �Ѵ�. ���� Ʋ�ȴ��� ������ Ȯ���� �� �־���Ѵ�. ������ �� �� �߿��ϰ�, 
�ͽ���Ʈ ���迡�� ���������̰�,. ���� �ܼ��� ���������, �޹��� ��Ȳ�� �ƴϸ� �ݵ�� ������. 


*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#define DEBUG 1

using namespace std;

char str[200];
int n;

long long dy0[200][10];
long long dy1[200][10];

int d(int a, int b, int c) {
#ifdef DEBUG
	if (a < 0) printf("error : a < 0\n");
	if (b < 0) printf("error : b < 0\n");
	if (c < 0) printf("error : c < 0\n");
#endif

	if (a == 0) return 0;
	if (a == 1) return dy1[b][c];
	if (c > 0) {
		return d(1, b, c) + ((long long)a - 1) * dy0[b][c - 1];
	}
	else {
		return 0;
	}
}

//~ using namespace __gnu_pbds; 
#define mp make_pair
#define endl '\n'
typedef long long ll;

const int INF = 1e9 + 5;
const ll lim = (ll)3e16;
const int N = 1e6 + 5;
const int mod = 1e9 + 7;
const ll oo = 1e18 + 5;

//~ typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int check(string s, int k) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
	int n = (int)s.size();
	vector<vector<vector<ll>>> dp(n + 5, vector<vector<ll>>(k + 5, vector<ll>(2)));
	dp[0][0][0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 2; ++j) {
			for (int cnt = 0; cnt < k + 1; ++cnt) {
				int pre_num;
				if (j) pre_num = 9;
				else pre_num = s[i] - '0';
				for (int dig = 0; dig <= pre_num; ++dig) {
					dp[i + 1][cnt + (dig != 0)][j || dig < pre_num] += dp[i][cnt][j];
				}
			}
		}
	}
	//	cout << dp[n][k][0] + dp[n][k][1];
	return dp[n][k][0] + dp[n][k][1];
}





int main(void) {
	int result = scanf("%s %d", str, &n);
	
	dy0[0][0] = 1;
	dy1[0][1] ++;
	for (int i = 1; i <= 150; i++) {
		dy0[i][0] = 1;
		for (int j = 1; j <= 4; j++) {
			dy0[i][j] = dy0[i - 1][j] + 9 * dy0[i - 1][j - 1];
			dy1[i][j] = dy0[i][j];
		}
		dy1[i][1] ++;
	}


//	for (int k = 1; k <= 1000000; k++) {
//		n = 2;
//		sprintf(str, "%d", k);
		int len = strlen(str);

		int dap = 0;
		int n2 = n;
		for (int i = 0; i < len; i++) {
			if (n2 < 0) break;	// �� ���ٶ����� ����� ������. �Լ��� �Է¹޴� ���ڰ� null (Ȥ�� ���� �ȵǴ� ��)�� ���� �ʵ���, Ȥ�� ������ ����� �α׸� �޾�����Ѵ�. 
			// �μ��� ���� ��� ������ ����, ������ �Ӱ谡 ���������� ¤�� �Ѿ��.
			dap += d(str[i] - '0', len - i - 1, n2);
			if (str[i] != '0') n2--;
		}


//		int cval = check(str);
		printf("%d\n", dap);
//		printf("%d\n\n", check(string(str), n));
//		if (dap != cval) {
//			printf("error");
//			break;
//		}
//	}
	return 0;
}

