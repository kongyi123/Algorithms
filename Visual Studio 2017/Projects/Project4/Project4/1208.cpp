// �̰� ��¥...�־��� �����͵� 
// 0. ���� �׽�Ʈ ������					v
// 1. ������ Ÿ���� ����� �׽�Ʈ ������	x
// 2. �ð��� ����� �׽�Ʈ ������			v
// 3. ������ ����� �׽�Ʈ ������			v
// 1���� ���ؼ� Ʋ�ȴ�. �׽�Ʈ �����͸� �� �� ���������� ������ �ǰڴٴ� ������ �ϱ���� ����

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ZERO 4000000
#define TERM 4000000
#define dbg //printf

long long dy[8000010];
int dat[41];
int N;
int S;

int main(void) {
	scanf("%d %d", &N, &S);
	for (int i = 1;i <= N;i++) {
		scanf("%d", &dat[i]);
	}

	for (int i = 1;i <= N;i++) {
		if (dat[i] < 0) {
			for (int j = ZERO - TERM;j <= ZERO + TERM;j++) {
				if (dy[j] != 0 && j + dat[i] >= ZERO - TERM) {
					dy[j + dat[i]] += dy[j];
				}
			}
		}
		else {
			for (int j = ZERO + TERM;j >= ZERO - TERM;j--) {
				if (dy[j] != 0 && j + dat[i] <= ZERO + TERM) {
					dy[j + dat[i]] += dy[j];
				}
			}

		}
		dy[ZERO + dat[i]] ++; // �������� �ƴ� �κ������̶�� ������ ó�� �������� �� 0�� �ʱ�ȭ�� ���Խ�Ű��x
	}



	printf("%Ld", dy[ZERO + S]);


	return 0;
}


