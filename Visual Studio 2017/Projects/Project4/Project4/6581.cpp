#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define in stdin
#define out stdout

//FILE *in = fopen("input.txt", "r");
//FILE *out = fopen("output.txt", "w");

char buffer[100];
int cnt;

int main(void) {
	while (!feof(in)) { // 마지막에 공백(스페이스 혹은 \n)이 남아 있는 경우 true가 나옴
		memset(buffer, 0, sizeof(buffer)); // 심각한 버퍼관련문제가 있었음...... 이거 모르면 바보된다.
		fscanf(in, "%s", &buffer);			// 이건 원래 쉽게 풀려야 하는 문제임.
		if (strcmp(buffer, "<br>") == 0) {
			fprintf(out, "\n");
			cnt = 0;
		}
		else if (strcmp(buffer, "<hr>") == 0) {
			if (cnt > 0) fprintf(out, "\n");
			for (int i = 1;i <= 80;i ++) fprintf(out, "-");
			fprintf(out, "\n");
			cnt = 0;
		}
		else {
			if (cnt+1+strlen(buffer) > 80) {
				cnt = strlen(buffer);
				fprintf(out, "\n%s", buffer);
			}
			else if (cnt == 0) {
				fprintf(out, "%s", buffer);
				cnt += strlen(buffer);
			}
			else if (cnt > 0) {
				fprintf(out, " %s", buffer);
				cnt += strlen(buffer) + 1;
			}
		}
	}
	if (cnt != 0) fprintf(out, "\n");
	return 0;
}
