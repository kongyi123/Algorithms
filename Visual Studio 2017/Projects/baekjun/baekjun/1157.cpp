#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define IN stdin
#define OUT stdout

//FILE *in = fopen("input.txt", "r");
//FILE *OUT = fopen("output.txt", "w");

char buf[1000020];
int cnt[100];

int main(void) {
	fgets(buf, 1000010, IN);
	int len = strlen(buf);
	for (int i = 0;i < len;i++) {
		if (buf[i] >= 'a' && buf[i] <= 'z') cnt[buf[i] - 'a'] ++;
		if (buf[i] >= 'A' && buf[i] <= 'Z') cnt[buf[i] - 'A'] ++;

	}

	int max = -1;
	int flag = 0;
	char dap;
	for (int i = 0;i < 100;i++) {
		if (max < cnt[i]) {
			max = cnt[i];
			dap = i + 'A';
			flag = 0;
		}
		else if (max == cnt[i]) {
			flag = 1;
		}
	}

	if (flag == 1) fprintf(OUT, "?");
	else fprintf(OUT, "%c", dap);
	return 0;
}