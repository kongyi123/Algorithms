#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int a[1000001];
int b[1000001];
int c[2000010];

int main(void) {
	int n, m;
	fscanf(stdin, "%d %d", &n, &m);
	for (int i = 1;i <= n;i++) {
		fscanf(stdin, "%d", &a[i]);
	}

	for (int i = 1;i <= m;i++) {
		fscanf(stdin, "%d", &b[i]);
	}

	int acnt, bcnt;
	int ccnt = 0;
	acnt = bcnt = 1;
	while (acnt <= n && bcnt <= m) {
		if (a[acnt] > b[bcnt]) {
			c[++ccnt] = b[bcnt++];
		}
		else {
			c[++ccnt] = a[acnt++];
		}
	}

	while (acnt <= n) c[++ccnt] = a[acnt++];
	while (bcnt <= m) c[++ccnt] = b[bcnt++];

	for (int i = 1;i <= ccnt;i++) {
		fprintf(stdout, "%d ", c[i]);
	}
	

	return 0;
}
