#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>

char buf[110];

int main(void) {
	int n;
	fscanf(stdin, "%d\n", &n);
	for (int i = 1;i <= n;i++) {
		memset(buf, 0, sizeof(buf));
		fgets(buf, 100, stdin);
		if (buf[0] >= 'a' && buf[0] <= 'z') buf[0] = buf[0] + ('A'-'a');
		fprintf(stdout, "%s", buf);
	}
	return 0;
}