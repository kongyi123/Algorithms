//... 걍 배열사용법...

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#include <string.h>

char str[10];
int st[10010];

int main(void) {
	int n;
	int val;
	int size = 0;
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		memset(str, 0, sizeof(str));
		fscanf(stdin, "%s", str);
		if (strcmp(str, "push") == 0) {
			fscanf(stdin, "%d", &val);
			st[size] = val;
			size++;
		}
		else if (strcmp(str, "top") == 0) {
			if (size == 0) fprintf(stdout, "-1\n");
			else {
				fprintf(stdout, "%d\n", st[size-1]);
			}
		}
		else if (strcmp(str, "size") == 0) {
			fprintf(stdout, "%d\n", size);
		}
		else if (strcmp(str, "empty") == 0) {
			if (size == 0) fprintf(stdout, "1\n");
			else fprintf(stdout, "0\n");
		}
		else if (strcmp(str, "pop") == 0) {
			if (size == 0) fprintf(stdout, "-1\n");
			else {
				fprintf(stdout, "%d\n", st[size - 1]);
				size--;
			}
		}

	}
	return 0;
}

