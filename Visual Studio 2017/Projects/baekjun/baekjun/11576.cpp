#include <stdio.h>

int data[30];
int dap[30];

int main(void) {
	int a, b;
	int m;
	fscanf(stdin, "%d %d", &a, &b);
	fscanf(stdin, "%d", &m);
	for (int i = 1;i <= m;i ++) fscanf(stdin, "%d", &data[i]);

	int dec = 0, t = 1;
	for (int i = m;i >= 1;i --) {
		dec = dec + (t*data[i]);
		t = t * a;
	}

	int cnt = 0;
	while (dec / b) {
		dap[++cnt] = dec % b;
		dec = dec / b;
	}
	fprintf(stdout, "%d ", dec);
	for (int i = cnt;i >= 1;i --) {
		fprintf(stdout, "%d ",dap[i]);
	}
	return 0;
}