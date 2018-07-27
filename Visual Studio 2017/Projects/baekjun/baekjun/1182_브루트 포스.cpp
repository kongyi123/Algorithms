// 브루트 포스
// 일반적인 냅색으로 했을 때는 메모리 초과나옴 (but 특수하게 두 배열로 주고 받으면 억셉됨)
// 항상 이러한 방식을 쓸 때는 세트로 두가지로 생각을 할 수 있도록 하자. 냅색처럼 하거나 혹은 브루트 포스로 하거나

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define IN stdin
#define OUT stdout
#define MAX 1058576

//FILE *out = fopen("output.txt", "w");
//FILE *in = fopen("input.txt", "r");

int data[22];
int n, m;
int dy[MAX];

int main(void) {
	fscanf(IN, "%d%d", &n, &m);
	for (int i = 1;i <= n;i++) {
		fscanf(IN, "%d", &data[i]);
	}

	int i, j;
	int k = 0;
	int dap = 0;
	for (i = 1;i <= n;i++) {
		int cnt = 0;
		for (j = 0;j <= k;j++) {
			cnt ++;
			dy[k + cnt] = dy[j] + data[i];
			if (dy[k + cnt] == m) dap++;
		}
		k = k + cnt;
	}

	fprintf(OUT, "%d", dap);


	return 0;
}