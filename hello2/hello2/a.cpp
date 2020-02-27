/*
// 생각을 하는 시간이 오래걸리는게 아니라 
// 헷갈려하는 시간이 가장 시간을 좀먹는다.
// 엄청나게 시간이 빨리간다. 차라리 노가다를 해서 명쾌하게 만드는게 가장 빠른 방법이다.



# 로그를 잘 써야한다. [모듈 짜고-검사] 하는 형태로 코딩의 흐름을 끊을게 아니라, [모듈을 짜는중에 필요한 로그정보 출력] 하는 형태로 코딩을 해야한다.
인간은 무조건 100프로 실수를 한다.
1. 실수를 최소한으로 만들기 위해 긴장한다.
2. 실수를 만들지 않기위한 습관을 만든다.
3. 실수를 하더라도 그것을 빠르게 찾아 고칠 수 있도록 해야한다.

> 각 함수의 인자의 변수 범위에 대한 에러로그
> 중간 결과값을 확인하는 로그

# null을 비롯한 변수에 들어갈 수 있는 모든 값의 경우를 따져야 한다. 그게, 코딩의 빠른 완성을 도와준다. (이게 안되면 1시간만에 풀걸 24시간이 걸리게 될지도 모른다. 이번에 겪은 내 경험담이다.)



# 이 문제의 경우 개수를 세는 단위와 숫자의 표현단위의 불일치 때문에, 헷갈리기도 했고 케이스가 중복되지 않게 하는 것도 힘들었다. 
앞으로 어떤 문제를 풀든 모든 단위를 동일화 하는 방향이 되어야할 것이다. 

ex) 123 1
1-9 / 10-99 / 100~123 >> 세 범위로 나눠서 세어야 하고, 개수 세는 단위를 자릿수로 해버리면 
또 100-123 은 100-109 / 110-123.....................

여는 세어보니까 단위 셀 수는 있는데, 이게 정확하게 끊어서 세기가 힘들다. 여튼 "모든 단위는 동일화 하는 방향으로" 하는게 핵심이다.

# brute force로 TC 체크 함수를 반드시 만들자. 이건 개발할때도 중요하다. 이건 습관화 되어야 한다. 내가 틀렸는지 스스로 확인할 수 있어야한다. 개발할 땐 더 중요하고, 
익스퍼트 시험에도 마찬가지이고,. 정말 단순한 문제라던가, 급박한 상황이 아니면 반드시 만들자. 


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
			if (n2 < 0) break;	// 이 한줄때문에 고생을 많이함. 함수에 입력받는 인자가 null (혹은 오면 안되는 값)이 오지 않도록, 혹은 오는지 디버그 로그를 달아줘야한다. 
			// 인수로 들어가는 모든 숫자의 상한, 하한의 임계가 어디까지인지 짚고 넘어가자.
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

