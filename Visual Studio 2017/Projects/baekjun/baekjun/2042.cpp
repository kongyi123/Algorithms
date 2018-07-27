#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define IN stdin
#define OUT stdout

//FILE *in = fopen("input.txt", "r");
//FILE *out = fopen("output.txt", "w");

int n, m, k;
long long sum[1000100];
int shift[10100][2], scnt;
int check[1000100];
int data[1000100];

int main(void) {
	fscanf(IN, "%d %d %d", &n, &m, &k);
	for (int i = 1;i <= n;i++) {
		fscanf(IN, "%d", &data[i]);
		sum[i] = sum[i-1] + data[i];
	}

	for (int i = 1;i <= m + k;i++) {
		int a, b, c;
		fscanf(IN, "%d %d %d", &a, &b, &c);
		if (a == 1) {
			scnt++;
			shift[scnt][0] = b;
			shift[scnt][1] = c;
//			data[b] = c;
		}
		else {
			long long t;
			if (b > c) {
				int t = b;
				b = c;
				c = t;
			}
			
			t = sum[c] - sum[b - 1];
			for (int j = scnt;j >= 1;j--) {
				if (check[shift[j][0]] == i) continue;
				check[shift[j][0]] = i;
				if (c >= shift[j][0] && shift[j][0] > b-1) {
					t = t + (shift[j][1] - data[shift[j][0]]);
				}
			}
			fprintf(OUT, "%lld\n", t);
		}
	}
	return 0;
}