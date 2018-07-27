// ���׸�Ʈ Ʈ��

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
	for (k = 1;k<n;k *= 2);				// ����Ʈ���� ������ �����͸� �ʱ�ȭ �� level�� ã�´�.
	for (int i = k;i<k + n;i++)			// ���� Ʈ���� ������ �ʱ�ȭ
		scanf("%lld", &tree[i]);		// ���� ��� �ʱ�ȭ


	for (int i = (k + n - 1) / 2;i >= 1;i--)		// �ٸ� ��� �ʱ�ȭ
		tree[i] = tree[i * 2] + tree[i * 2 + 1];

	long long int a, b, c;
	for (int i = 1;i <= m + l;i++) {
		scanf("%lld %lld %lld", &a, &b, &c);
		if (a == 1) {	// �� ����
			tree[k + b - 1] = c;			// ���� ��� ����
			int tmp = (k + b - 1) / 2;		// ���� ����� �� ������ ����
			while (tmp>0) {
				tree[tmp] = tree[tmp * 2] + tree[tmp * 2 + 1];
				tmp /= 2;
			}
			continue;
		}
		if (a == 2) {	// ���� �� ���ϱ�
			int x = k + b - 1;	// ��
			int y = k + c - 1;	// ��
			sum = 0;
			while (x <= y) {			// �� �찡 �������� �����϶� ���
				if (x % 2 == 1) {		// �� �ε� ��°�� 
					sum += tree[x];		// ���� ���ϰ� 
					x++;				// �θ��� ������ ��带 ����ϰ� ��ĭ ����������
				}

				if (y % 2 == 0) {		// �� �ε� ù°��
					sum += tree[y];		// ���� ���ϰ�
					y--;				// �θ��� ���� ��带 ����ϰ� ��ĭ ��������
				}
				x /= 2;
				y /= 2;
			}
			printf("%lld\n", sum);
		}
	}
}