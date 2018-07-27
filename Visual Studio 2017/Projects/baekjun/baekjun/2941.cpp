#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>

char str[150];
int ch[150];

int main(void) {
	fscanf(stdin, "%s", &str);
	int len = strlen(str);
	int cnt = 0;
	for (int i = 0;i < len;i++) {
		if (str[i] == '=') {
			if (i - 1 >= 0 && str[i - 1] == 'c') {
				ch[i - 1] = ch[i] = 1; cnt++;
			}
			else if (i - 2 >= 0 && str[i - 1] == 'z' && str[i - 2] == 'd') {
				ch[i - 1] = ch[i - 2] = ch[i] = 1; cnt++;
			}
			else if (i - 1 >= 0 && str[i - 1] == 's') {
				ch[i - 1] = ch[i] = 1; cnt++;
			}
			else if (i - 1 >= 0 && str[i - 1] == 'z') {
				ch[i - 1] = ch[i] = 1; cnt++;
			}
		}
		else if (str[i] == '-') {
			if (i - 1 >= 0 && str[i - 1] == 'c') {
				ch[i - 1] = ch[i] = 1; cnt++;
			}
			else if (i - 1 >= 0 && str[i - 1] == 'd') {
				ch[i - 1] = ch[i] = 1; cnt++;
			}
		}
		else if (str[i] == 'j') {
			if (i - 1 >= 0 && str[i - 1] == 'n') {
				ch[i - 1] = ch[i] = 1;
				cnt++;
			}
			else if (i - 1 >= 0 && str[i - 1] == 'l') {
				ch[i - 1] = ch[i] = 1;
				cnt++;
			}
		}
	}

	for (int i = 0;i < len;i++) {
		if (ch[i] == 0) cnt++;
	}

	fprintf(stdout, "%d", cnt);
	return 0;
}