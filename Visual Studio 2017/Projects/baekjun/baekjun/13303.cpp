// 코딩중에 이분 검색이 부족 한듯하여 이분검색 정리

#define _CRT_SECURE_NO_WARNGINS

#include <stdio.h>

int n;
int sy, ex;

typedef struct bar {
	int x;
	int y1;
	int y2;
};

bar data[110000];

void swap(bar &a, bar &b) {
	bar t;
	t = a;
	a = b;
	b = t;
}

int main(void) {
	fscanf(stdin, "%d", &n);
	fscanf(stdin, "%d %d", &sy, &ex);
	for (int i = 1;i <= n;i++) {
		int a, b, c;
		fscanf(stdin, "%d %d %d", &a, &b, &c);
		data[i].x = a;
		data[i].y1 = b;
		data[i].y2 = c;
		for (int j = i;j > 1;j = j / 2) {
			if (data[j].x < data[j / 2].x) swap(data[j], data[j / 2]);
			else if (data[j].x == data[j/2].x && data[j].y2 >= )
		}
	}


	return 0;
}