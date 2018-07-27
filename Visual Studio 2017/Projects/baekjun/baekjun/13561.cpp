#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

typedef struct node {
	int pos;
	int type;
} node;

node data[1000010];
int check[100010];

void swap(node &a, node &b) {
	node t = a;
	a = b;
	b = t;
}

int main(void) {
	int n, k;
	fscanf(stdin, "%d %d", &k, &n);
	
	for (int i = 1;i <= n;i++) {
		fscanf(stdin, "%d %d", &data[i].pos, &data[i].type);
		for (int j = i;j > 1;j = j >> 1) {
			if (data[j].pos > data[j >> 1].pos) swap(data[j], data[j >> 1]);
		}
	}

	for (int i = 1;i <= n;i++) {
		swap(data[1], data[n - i + 1]);
		for (int j = 1;;) {
			int k = j * 2;
			if (k > n - i) break;
			if (k + 1 <= n - i && data[k + 1].pos > data[k].pos) k++;
			if (data[k].pos > data[j].pos) {
				swap(data[k], data[j]);
				j = k;
			}
			else break;
		}
	}

	int end = 0;
	int cnt = 0;
	int p1, p2;
	p1 = 1;
	p2 = 0;
	int dap_p1, dap_p2, min;
	min = 2000000000;

	while (1) {
		if (cnt == k) {
			if (data[p2].pos - data[p1].pos < min) {
				min = data[p2].pos - data[p1].pos;
				dap_p1 = p1;
				dap_p2 = p2;
			}

			if (p1 > 0) {
				check[data[p1].type] --;
				if (check[data[p1].type] == 0) cnt--;
			}
			p1++;
			continue;
		}
		else if (p2 <= n && end == 0) {
			if (p2 + 1 > n) end = 1;
			else p2++;
			if (check[data[p2].type] == 0) {
				cnt++;

				if (cnt == k) {
					if (data[p2].pos - data[p1].pos < min) {
						min = data[p2].pos - data[p1].pos;
						dap_p1 = p1;
						dap_p2 = p2;
					}
				}
			}
			check[data[p2].type] ++;

			
		}
		else break;
	}

	fprintf(stdout, "%d", (data[dap_p1].pos+data[dap_p2].pos)/2);
		
	
	return 0;

}