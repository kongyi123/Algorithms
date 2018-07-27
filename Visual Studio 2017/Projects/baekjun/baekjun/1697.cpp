// 18분
// 배열을 직접 손으로 채워보고 그에 맞게 채워지는지 확인하면서 코딩을 하라.
// 그게 제대로 코딩이 됐는지 검증하면서 코딩하는 방법이다.

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int n, k;
int check_time[110000];
int queue[110000][2];

int main(void) {
	fscanf(stdin, "%d %d", &n, &k);

	int head, tail;
	head = 0, tail = 1;
	queue[0][0] = n; // 위치
	queue[0][1] = 1; // 걸린시간 + 1
	check_time[n] = 1;
	while (head < tail) {
		int cur = queue[head][0];
		int time = queue[head][1];

		if (cur + 1 <= 100000 && check_time[cur + 1] == 0) {
			check_time[cur + 1] = time + 1;
			queue[tail][0] = cur + 1;
			queue[tail][1] = time + 1;
			tail++;
		}

		if (0 <= cur - 1 && check_time[cur - 1] == 0) {
			check_time[cur - 1] = time + 1;
			queue[tail][0] = cur - 1;
			queue[tail][1] = time + 1;
			tail++;
		}

		if (cur * 2 <= 100000 && check_time[cur * 2] == 0) {
			check_time[cur * 2] = time + 1;
			queue[tail][0] = cur * 2;
			queue[tail][1] = time + 1;
			tail++;
		}

		head++;
	}

	fprintf(stdout, "%d", check_time[k]-1);
	return 0;
}