#include <stdio.h>
#include <string.h>
#include <memory.h>

char str[1010];
int check[100];

int main(void) {
	int n;
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i ++) {
		memset(str, 0, sizeof(str));
		memset(check, 0, sizeof(check));
		fscanf(stdin, "%s", &str);
		int len = strlen(str);
		for (int j = 0;j < len;j ++) {
			check[str[j]] = 1;
		}

		int sum = 0;
		for (int j = 65;j <= 90;j ++) {
			if (check[j] == 0) sum = sum + j;
		}
		
		fprintf(stdout, "%d\n", sum);
	}
	return 0;
}