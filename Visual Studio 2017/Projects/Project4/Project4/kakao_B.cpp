#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int check[10];
int table[30];
int N;
char data[105][10];

char t[8] = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };

int abs(int a) {
	if (a < 0) return -a;
	return a;
}

int cnt;

void back(int o) {
	if (o == 8) {
		int er = 0;
		for (int i = 1;i <= N;i++) {
			if (data[i][3] == '=') {
				if (!(abs(table[data[i][0] - 'A'] - table[data[i][2] - 'A'])-1 == data[i][4] - '0')) {
					er = 1;
					break;
				}
			}
			else if (data[i][3] == '>') {
				if (!(abs(table[data[i][0] - 'A'] - table[data[i][2] - 'A'])-1 > data[i][4] - '0')) {
					er = 1;
					break;
				}
			}
			else if (data[i][3] == '<') {
				if (!(abs(table[data[i][0] - 'A'] - table[data[i][2] - 'A'])-1 < data[i][4] - '0')) {
					er = 1;
					break;
				}
			}
		}
		if (er == 0) cnt++;
		return;
	}
	for (int i = 1;i <= 8;i++) {
		if (check[i]) continue;
		check[i] = 1;
		table[t[o]-'A'] = i;
		back(o+1);
		check[i] = 0;
	}
}


int main(void) {
	fscanf(stdin, "%d", &N);
	for (int i = 1;i <= N;i++) {
		fscanf(stdin, "%s", data[i]);
	}

	cnt = 0;
	for (int a = 1;a <= 8;a++) {
		check[a] = 1;
		table[t[0]-'A'] = a;
		back(1);
		check[a] = 0;
	}

	fprintf(stdout, "%d", cnt);
	return 0;
}