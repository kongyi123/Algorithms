#include <stdio.h>

int inv(int a) {
	int t2 = 0;
	while (a) {
		t2 = t2 * 10 + a % 10;
		a = a / 10;
	}

	return t2;
}

int main(void) {
	int n;
	int data;
	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i ++) {
		fscanf(stdin, "%d", &data);
		int t = data, t2;

		t2 = inv(data) + data;


		if (t2 == inv(t2)) {
			fprintf(stdout, "YES\n");
		} else fprintf(stdout, "NO\n");
	}
	return 0;
}