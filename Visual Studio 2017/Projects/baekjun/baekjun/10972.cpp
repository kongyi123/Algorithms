#include <stdio.h>

int data[20001];
int check[20001];

int main(void) {
	int n;
	int i;
	fscanf(stdin, "%d", &n);
	for (i = 1;i <= n;i ++) {
		fscanf(stdin, "%d", &data[i]);
	}

	int t = 0;
	for (i = n;i >= 1;i --) {
		if (t < data[i]) {
			t = data[i];
			check[t] = 1;
		} else break;
	}

	if (i == 0) fprintf(stdout, "-1");
	else {
		t = i;
		int flag = 0;
		for (i = data[t]+1;i <= n;i ++) {
			if (check[i] == 1) {
				check[data[t]] = 1;
				data[t] = i;
				check[i] = 0;
				flag = 1;
				break;
			}
		}

		if (flag == 0) {
			for (i = 1;i < t;i ++) {
				if (check[i] == 1) {
					check[data[t]] = 1;
					data[t] = i;
					check[i] = 0;
					flag = 1;
					break;
				}
			}
		}

		for (i = 1;i <= n;i ++) {
			if (check[i] == 1) {
				data[++t] = i;
			}
		}
	
	
		for (int i = 1;i <= n;i ++) {
			fprintf(stdout, "%d ", data[i]);		
		}

	}

	
	return 0;
}