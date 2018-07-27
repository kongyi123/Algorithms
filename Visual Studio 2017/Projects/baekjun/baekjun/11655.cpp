#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char str[210];

int main(void) {
	//fscanf(stdin, "%s", &str);
	fgets(str, 200, stdin);
	int len;
	for (int i = 0;i < 200;i++) {
		if (str[i] != 0) len = i;
	}
	for (int i = 0;i <= len;i ++) {
		if (('a' <= str[i] && str[i] <= 'm') || ('A' <= str[i] && str[i] <= 'M')) fprintf(stdout, "%c", str[i]+13);
		else if (('n' <= str[i] && str[i] <= 'z') || ('N' <= str[i] && str[i] <= 'Z')) fprintf(stdout, "%c", str[i]-13);
		else fprintf(stdout, "%c", str[i]);
	}
	return 0;
}