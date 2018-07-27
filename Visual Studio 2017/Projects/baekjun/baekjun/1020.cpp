#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define INPUT stdin
#define OUTPUT stdout

//FILE *in = fopen("input.txt", "r");
//FILE *out = fopen("output.txt", "w");

int CNT[10];
char str[100];
int len;

int main(void) {
	CNT[0] = 6;
	CNT[1] = 2;
	CNT[2] = 5;
	CNT[3] = 5;
	CNT[4] = 4;
	CNT[5] = 5;
	CNT[6] = 5;
	CNT[7] = 3;
	CNT[8] = 7;
	CNT[9] = 5;

	fscanf(INPUT,"%s", &str[1]);
	len = strlen(&str[1]);

	int cnt = 0;
	for (int i = 1;i <= len;i++) {
		cnt += CNT[str[i] - '0'];
	}
	int origin = cnt;

	int count = 0;
	while (1) {
		
		count++;
		
		str[len] += 1;
		int i = len;
		while (str[i] > '9') {
			str[i] = '0';
			str[--i] += 1;
		}
		

		cnt = 0;
		for (int i = 1;i <= len;i++) {
			cnt += CNT[str[i] - '0'];
		}
		if (cnt == origin) break;
	}	

	fprintf(OUTPUT, "%d", count);
}