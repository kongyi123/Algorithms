// 22분
// if (k > n-i) break; 조건문에서 k > n-k 로 정신이 맛이 갔었음.
// 디버깅을 일단 시작하게 되면 시간이 배로 걸린다고 생각해야 한다.
// 단계 단계를 잘 확인하며 코딩을 해야함.

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

typedef struct st {
	int x, y;
};

st data[110000];

void swap(st &a, st &b) {
	st t;
	t = a;
	a = b;
	b = t;
}

int main(void) {
	int n;

	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		fscanf(stdin, "%d %d", &data[i].x, &data[i].y);
		for (int j = i;j > 1;j = j / 2) {
			if (data[j].x > data[j / 2].x || (data[j].x == data[j / 2].x && data[j].y > data[j / 2].y)) {
				swap(data[j], data[j / 2]);
			}
		}
	}

	for (int i = 1;i <= n;i++) {
		swap(data[1], data[n - i + 1]);
		for (int j = 1;;) {
			int k = j * 2;
			if (k > n - i) break;
			if (k + 1 <= n - i) {
				if (data[k].x < data[k + 1].x || (data[k].x == data[k + 1].x && data[k].y < data[k + 1].y)) k++;
			}
			if (data[j].x < data[k].x || (data[j].x == data[k].x && data[j].y < data[k].y)) {
				swap(data[j], data[k]);
				j = k;
			}
			else break;
		}
	}

	for (int i = 1;i <= n;i++) {
		fprintf(stdout, "%d %d\n", data[i].x, data[i].y);
	}
	return 0;
}