// 이건 진짜...최악의 데이터도 
// 0. 동작 테스트 데이터					v
// 1. 데이터 타입을 고려한 테스트 데이터	x
// 2. 시간을 고려한 테스트 데이터			v
// 3. 공간을 고려한 테스트 데이터			v
// 1번을 안해서 틀렸다. 테스트 데이터를 좀 더 전략적으로 만들어야 되겠다는 생각을 일깨우는 문제

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
		dy[ZERO + dat[i]] ++; // 공집합이 아닌 부분집합이라고 했으니 처음 공집합의 합 0은 초기화에 포함시키지x
	}



	printf("%Ld", dy[ZERO + S]);


	return 0;
}


