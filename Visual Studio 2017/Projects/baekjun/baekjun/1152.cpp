#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define IN stdin
#define OUT stdout

//FILE *in = fopen("input.txt", "r");
//FILE *out = fopen("output.txt", "w");

char str[1000100];

int main(void) {
	fgets(str, 1000100, IN);
	int len = strlen(str);
	int cnt = 0;
	int flag = 0;
	for (int i = 0;i < len;i++) {
		if (str[i] == '\n') break;
		if (str[i] == 0) continue;
		if (flag == 0 && str[i] != ' ') {
			flag = 1;
			cnt++;
		}
		if (str[i] == ' ' && flag == 1) {
			flag = 0;
		}
	}


	fprintf(OUT, "%d", cnt);
	return 0;
}