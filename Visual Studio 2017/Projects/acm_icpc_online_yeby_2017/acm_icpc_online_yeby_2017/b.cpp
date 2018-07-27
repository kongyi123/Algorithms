#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define IN stdin
#define OUT stdout

//FILE *in = fopen("input.txt", "r");
//FILE *out = fopen("output.txt", "w");

int main(void) {
	int n, m;
	char buf[10];
	fscanf(IN, "%d %d", &n, &m);
	fgets(buf, 10, IN);
	int dir[4][2] = { {1, 0}, { 0, 1 }, { -1, 0 }, { 0, -1 }};
	int to = 0;
	int y, x;
	y = x = 0;
	for (int i = 1;i <= m;i++) {
		char command[10];
		int val;
		fscanf(IN, "%s %d", &command[1], &val);
		if (strcmp(&command[1], "MOVE") == 0) {
			x = x + val*dir[to][0];
			y = y + val*dir[to][1];
			if (x < 0 || x > n || y > n || y < 0) {
				fprintf(OUT, "-1");
				return 0;
			}
		}
		else if (strcmp(&command[1], "TURN") == 0) {
			if (val == 0) {
				to++;
				to = to % 4;
			}
			else {
				to--;
				if (to == -1) to = 3;
			}
		}
	}

	fprintf(OUT, "%d %d", x, y);
	return 0;
}

