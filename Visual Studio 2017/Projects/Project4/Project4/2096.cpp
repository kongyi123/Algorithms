// 16 -18

// 이야.....
// 메모리 공간을 아낄 방법은...?? 너무 쉬운 방법이 있는데... 그걸 떠올리지 못했구나... ㅠㅠ
// 왜이렇게 풀이에만 집착하게 됐나..

// 근데 너무 자책할것없다. 변수의 용량계산 했을 때 충분히 답이 나와야되는데 안나왔다는 것에 대한 고민을 했지.
// 이상태에서 어떻게 해결해야할지 고민을 하려고 마음먹지 않았기 때문이다.


// 슬라이딩 윈도우란????
// 일 순간 ( 특정 영역 )의 값만으로 값을 구하는 알고리즘을 의미.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
int dat[100001][3];
int min[3][3];
int max[3][3];

int MIN(int a, int b) {
	if (a > b) return b;
	return a;
}

int MAX(int a, int b) {
	if (a > b) return a;
	return b;
}

int main(void) {
	scanf("%d", &N);
	for (int i = 0;i < N;i++) {
		scanf("%d%d%d", &dat[i][0], &dat[i][1], &dat[i][2]);
	}
	
	int t;
	int i;
	for (i = 0;i < N;i++) {
		t = i % 2;
		min[t][0] = dat[i][0] + MIN(min[1-t][0], min[1-t][1]);
		min[t][1] = dat[i][1] + MIN(MIN(min[1-t][0], min[1-t][1]), min[1-t][2]);
		min[t][2] = dat[i][2] + MIN(min[1-t][1], min[1-t][2]);
		max[t][0] = dat[i][0] + MAX(max[1-t][0], max[1-t][1]);
		max[t][1] = dat[i][1] + MAX(MAX(max[1-t][0], max[1-t][1]), max[1-t][2]);
		max[t][2] = dat[i][2] + MAX(max[1-t][1], max[1-t][2]);
	}
	t = i % 2;
	printf("%d %d", MAX(MAX(max[1-t][0], max[1-t][1]), max[1-t][2]), MIN(MIN(min[1-t][0], min[1-t][1]), min[1-t][2]));
	return 0;
}