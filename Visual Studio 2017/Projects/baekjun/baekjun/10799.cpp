#include <stdio.h>
#include <string.h>

int len;
char str[100100];
int stack[100100];

int main(void) {
	fscanf(stdin, "%s", &str);
	len = strlen(str);
	int cnt = 0;
	int sum = 0;
	for (int i = 0;i < len;i ++) {
		if (str[i] == '(') {
			if (str[i+1] == ')') {
				stack[cnt]++;
				i ++;
				continue;
			} else {
				cnt ++;
			}
		} else if (str[i] == ')') {
			sum = sum + stack[cnt]+1;
			cnt --;
			stack[cnt] += stack[cnt+1];
			stack[cnt+1] = 0;
		}
	}

	fprintf(stdout, "%d", sum);

	return 0;
}