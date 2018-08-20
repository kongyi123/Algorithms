// 쓰잘데 없는 확인
// short, register int ... 이문제에서는 속도개선 아예 티도안남.
// j = i+1 해서 약간 줄이고, 이중for문 sum구하기 조금 개선해서 약간 줄임
// 그리고 min 가지치기...
// 의미없다............


#include<iostream>

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define INF 0x7fffffff

int N, half;
int dat[30][30];
int min = INF;
int total;
int list[30], list2[30];

// 뽑은 사람 수, bitmask주소, 남은 사람중 가장 작은 번호


int sum1, sum2;
int p, q;
void back(int cnt, int next) {
	if (min <= 0) return;
	if (cnt == half) {
		sum1 = sum2 = 0;
		p = 1; q = 0;
		for ( int i = 1;i <= N;i++) {
			if (list[p] != i) list2[++q] = i;
			else p++;
		}
		for ( int i = 1;i <= cnt;i++) {
			for ( int j = i + 1;j <= cnt;j++) {
				sum2 += dat[list2[i]][list2[j]] + dat[list2[j]][list2[i]];
				sum1 += dat[list[i]][list[j]] + dat[list[j]][list[i]];
			}
		}

		if (min > abs(sum1 - sum2)) {
			min = abs(sum1 - sum2);
		}
		return;
	}

	for ( int i = next;i <= N;i++) {
		list[cnt + 1] = i;
		back(cnt + 1, i + 1);
	}
}

int main(void) {
	scanf("%d", &N);
	half = N / 2;
	for ( int i = 1;i <= N;i++) {
		for ( int j = 1;j <= N;j++) {
			scanf("%d", &dat[i][j]);
			total += dat[i][j];
		}
	}

	back(0, 1);
	printf("%d", min);
	return 0;
}