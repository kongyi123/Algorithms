#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

FILE *in = fopen("input.txt", "r");

int getint(char buffer[], int idx) {
	int i;
	for (i = idx;;i++) {
		if (buffer[i] < '0' || buffer[i] > '9') {
			break;
		}
	}

	int t = 1;
	int sum = 0;
	while (i > idx) {
		i--;
		if (i < 0) break;
		sum += t*(buffer[i] - '0');
		t = t * 10;
	}

	return sum-5500;
}

int main(void) {
	freopen("output.txt", "w", stdout);
	char buffer[100] = { 0, };
	while (1) {
		buffer[0] = '^';
		fgets(buffer, 100, in);
		if (buffer[0] == '^') break;
		int t;
		if (buffer[1] == 'S' && buffer[2] == 'Y') {
			t = getint(buffer, 12);
			for (int i = 0;i < 12;i++) {
				printf("%c", buffer[i]);
			}
			printf("%d", t);
			for (int i = 12;i < strlen(buffer);i++) {
				if (buffer[i] >= '0' && buffer[i] <= '9') continue;
				printf("%c", buffer[i]);
			}
		}
		else {
			printf("%s", buffer);
		}

	}
	return 0;
}