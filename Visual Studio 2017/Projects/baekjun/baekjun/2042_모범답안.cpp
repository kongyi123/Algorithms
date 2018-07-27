// 세그먼트 트리

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n, m, l;
long long int tree[2500000], sum;

int main()
{
	scanf("%d %d %d", &n, &m, &l);
	int k = 1;
	for (k = 1;k<n;k *= 2);				// 이진트리의 적당한 데이터를 초기화 할 level을 찾는다.
	for (int i = k;i<k + n;i++)			// 이진 트리에 데이터 초기화
		scanf("%lld", &tree[i]);		// 리프 노드 초기화


	for (int i = (k + n - 1) / 2;i >= 1;i--)		// 다른 노드 초기화
		tree[i] = tree[i * 2] + tree[i * 2 + 1];

	long long int a, b, c;
	for (int i = 1;i <= m + l;i++) {
		scanf("%lld %lld %lld", &a, &b, &c);
		if (a == 1) {	// 값 변경
			tree[k + b - 1] = c;			// 리프 노드 변경
			int tmp = (k + b - 1) / 2;		// 조상 노드의 값 줄줄이 갱신
			while (tmp>0) {
				tree[tmp] = tree[tmp * 2] + tree[tmp * 2 + 1];
				tmp /= 2;
			}
			continue;
		}
		if (a == 2) {	// 구간 합 구하기
			int x = k + b - 1;	// 좌
			int y = k + c - 1;	// 우
			sum = 0;
			while (x <= y) {			// 좌 우가 정상적인 관계일때 계속
				if (x % 2 == 1) {		// 좌 인데 둘째면 
					sum += tree[x];		// 본인 더하고 
					x++;				// 부모의 오른쪽 노드를 계산하게 한칸 오른쪽으로
				}

				if (y % 2 == 0) {		// 우 인데 첫째면
					sum += tree[y];		// 본인 더하고
					y--;				// 부모의 왼쪽 노드를 계산하게 한칸 왼쪽으로
				}
				x /= 2;
				y /= 2;
			}
			printf("%lld\n", sum);
		}
	}
}