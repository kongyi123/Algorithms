#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int x1, x2, x3, x4;
int y1, y2, y3, y4;

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	int val = x1*y2 + x2*y3 + x3*y1 - x1*y3 - x2*y1 - x3*y2;
	if (val > 0) {
		return 1;
	}
	else if (val < 0) {
		return -1;
	}
	return 0;
}


int main(void) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		scanf("%d %d", &x3, &y3);

		printf("%d", ccw(x1, y1, x2, y2, x3, y3));
	
	return 0;

}