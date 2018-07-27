// 이것도 틀린 방법은 아니고 비효율 적인 방법일 수는 있지만, 어쩄든 백준에서는 메모리 초과로 나올 수 있다. 일반적으로 n x m의 배열을 쓰지만
// m크기의 배열 두개로 주고 받아 쓰면 메모리 초과 없이 채점결과 "맞았습니다" 나온다.
// 메모리를 계산했을때 계산상으로는 초과 아닌데... 음....  아무튼
// 항상 이러한 방식을 쓸 때는 두가지로 생각을 할 수 있도록 하자. 냅색처럼 하거나 혹은 브루트 포스로 하거나

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define IN stdin
#define OUT stdout
#define M 1000000

//FILE *out = fopen("output.txt", "w");
//FILE *in = fopen("input.txt", "r");

int data[22];
int n, m;
int dy[2][2000100];

int main(void) {
	fscanf(IN, "%d%d", &n, &m);
	for (int i = 1;i <= n;i++) {
		fscanf(IN, "%d", &data[i]);
	}
	
	int i, j;
	int A, B;
	for (i = 1;i <= n;i++) {
		if (i % 2 == 0) {
			A = 0; B = 1;
		}
		else {
			A = 1; B = 0;
		}
		for (j = 2000000;j >= 0;j--) dy[B][j] = 0;
		for (j = 2000000;j >= 0;j--) {
			if (dy[A][j] > 0) {
				dy[B][j + data[i]] += dy[A][j];
				dy[B][j] += dy[A][j];
			}
		}
		dy[B][data[i] + M] = dy[B][data[i] + M] + 1;
	}
	
	fprintf(OUT, "%d", dy[B][M + m]);

	return 0;
}