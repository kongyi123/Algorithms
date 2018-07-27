#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char str[30];
int num[100];

int main(void) {

	fscanf(stdin, "%s", &str);
	num['A'] = num['B'] = num['C'] = 2;
	num['D'] = num['E'] = num['F'] = 3;
	num['G'] = num['H'] = num['I'] = 4;
	num['J'] = num['K'] = num['L'] = 5;
	num['M'] = num['N'] = num['O'] = 6;
	num['P'] = num['Q'] = num['R'] = num['S'] = 7;
	num['T'] = num['U'] = num['V'] = 8;
	num['W'] = num['X'] = num['Y'] = num['Z'] = 9;

	int len = strlen(str);
	int cnt = len;
	for (int i = 0;i < len;i++) {
		cnt += num[str[i]];
	}

	fprintf(stdout, "%d", cnt);

	return 0;
}