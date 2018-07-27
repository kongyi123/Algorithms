#include <stdio.h>
#include <string.h>

char str[100];
int len;

int table[4];

void swap(int a, int b) {
	int t = table[a];
	table[a] = table[b];
	table[b] = t;
}


int main(void) {
	fscanf(stdin, "%s", &str);
	len = strlen(str);
	table[1] = 1;
	for (int i = 0;i < len;i ++) {
		if (str[i] == 'A') swap(1, 2);
		if (str[i] == 'B') swap(2, 3);
		if (str[i] == 'C') swap(1, 3);
	}

	for (int i = 1;i <= 3;i ++) {
		if (table[i] == 1) {
			fprintf(stdout, "%d", i);
			break;
		}
	}
	return 0;
}