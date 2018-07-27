#include <stdio.h>

int a[11];
int b[11];

int main(void) {
	int scorea = 0;
	int scoreb = 0;
	for (int i = 1;i <= 10;i ++) {
		fscanf(stdin, "%d", &a[i]);
	}
	for (int i = 1;i <= 10;i ++) {
		fscanf(stdin, "%d", &b[i]);
	}

	int flag = 0;
	for (int i = 1;i <= 10;i ++) {
		if (a[i] == b[i]) {
			scorea ++;
			scoreb ++;
		} else if (a[i] > b[i]) {
			scorea = scorea + 3;
			flag = 1;
		} else {
			scoreb = scoreb + 3;
			flag = 2;
		}
	}

	fprintf(stdout, "%d %d\n", scorea, scoreb);
	if (scorea > scoreb || (scorea == scoreb && flag == 1)) fprintf(stdout, "A");
	else if (scorea < scoreb || (scorea == scoreb && flag == 2)) fprintf(stdout, "B");
	else fprintf(stdout, "D");

	return 0;
}