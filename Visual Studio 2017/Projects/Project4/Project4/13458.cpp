//15
// 굉장히 기분나쁘네... 출력이 longlong 범위를 넘어갈지 ... 무조건 짚고 넘어가자.
// 아니 그것보다도 가장 큰 데이터를 무조건 넣어보고 제출을 해야...
// 데이터 넣기가 귀찮아서 안넣었다. 그럼 시험에는 귀찮다는 핑계로 떨어지는 거다.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
int dat[1000010];
int b, c;

int main(void) {
	scanf("%d", &N);
	for (int i = 1;i <= N;i++) {
		scanf("%d", &dat[i]);
	}
	scanf("%d %d", &b, &c);

	long long cnt = 0;
	for (int i = 1;i <= N;i++) {
		if (dat[i] <= b) cnt++;
		else {
			cnt += (dat[i] - b + c-1) / c  + 1;
		}
	}

	printf("%lld", cnt);
	return 0;
}