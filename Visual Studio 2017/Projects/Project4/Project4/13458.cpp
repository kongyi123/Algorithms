//15
// ������ ��г��ڳ�... ����� longlong ������ �Ѿ�� ... ������ ¤�� �Ѿ��.
// �ƴ� �װͺ��ٵ� ���� ū �����͸� ������ �־�� ������ �ؾ�...
// ������ �ֱⰡ �����Ƽ� �ȳ־���. �׷� ���迡�� �����ٴ� �ΰ�� �������� �Ŵ�.
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