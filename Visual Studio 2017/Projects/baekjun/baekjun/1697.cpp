// 18��
// �迭�� ���� ������ ä������ �׿� �°� ä�������� Ȯ���ϸ鼭 �ڵ��� �϶�.
// �װ� ����� �ڵ��� �ƴ��� �����ϸ鼭 �ڵ��ϴ� ����̴�.

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int n, k;
int check_time[110000];
int queue[110000][2];

int main(void) {
	fscanf(stdin, "%d %d", &n, &k);

	int head, tail;
	head = 0, tail = 1;
	queue[0][0] = n; // ��ġ
	queue[0][1] = 1; // �ɸ��ð� + 1
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