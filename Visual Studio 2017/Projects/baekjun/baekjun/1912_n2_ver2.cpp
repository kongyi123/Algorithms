// 어프로치...

// n ^ 2

// 수열의 합은 아니고
// 중복되는 부분을 살피면 시간 복잡들을 /n만큼 줄일 수도 있다.

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int data[110000];

int main(void) {
	int n;
	int max = -2000000000;
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		fscanf(stdin, "%d", &data[i]);
	}

	for (int i = 1;i <= n;i++) {	// 시작점
		int sum = 0;
		for (int j = i;j <= n;j++) {	// 끝점
			sum += data[j];
			if (max < sum) max = sum;
		}
/*
		for (int j = i;j <= n;j++) {		// 끝점
			int sum = 0;
			for (int k = i;k <= j;k++) {	// 시작점에서 끝점 까지 순회
				sum += data[k];			
				if (max < sum) max = sum;
			}
		}

		1, +2, +3, +4, +5, +6
		2, +3, +4 ,+5, +6
		3, +4, +5, +6
		4, +5, +6
		5, +6
		6



		// 겹치는 부분을 제거해 주는 개념인가??

		// 
*/

	}

	fprintf(stdout, "%d", max);

}