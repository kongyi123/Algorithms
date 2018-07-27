#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define IN stdin
#define OUT stdout

//FILE *in = fopen("input.txt", "r");
//FILE *out = fopen("output.txt", "w");

int n;
int data[100][2];
int cnt[100];

int main(void) {
	
	fscanf(IN, "%d", &n);
	for (int i = 1;i <= n;i++) {
		fscanf(IN, "%d %d", &data[i][0], &data[i][1]);
		data[i][2] = i;
	}

	int i, j;
	for (i = 1;i <= n;i++) {
		for (j = 1;j <= n;j++) {
			if (data[i][0] < data[j][0] && data[i][1] < data[j][1]) cnt[i]++;
//			if (data[i][0] == data[j][0] && data[i][1] < data[j][1]) cnt[i]++;
//			if (data[i][0] < data[j][0] && data[i][1] == data[j][1]) cnt[i]++;
		}
	}

	for (i = 1;i <= n;i++) {
		fprintf(OUT, "%d ", cnt[i] + 1);
	}

	return 0;
}