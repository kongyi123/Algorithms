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
	while (!feof(in)) { // �������� ����(�����̽� Ȥ�� \n)�� ���� �ִ� ��� true�� ����
		memset(buffer, 0, sizeof(buffer)); // �ɰ��� ���۰��ù����� �־���...... �̰� �𸣸� �ٺ��ȴ�.
		fscanf(in, "%s", &buffer);			// �̰� ���� ���� Ǯ���� �ϴ� ������.
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
