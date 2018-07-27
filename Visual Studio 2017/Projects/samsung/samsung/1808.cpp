#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <memory.h>

int data[1200000];
int dy[1200000];
int cnt[1200000];

int main(void) {
	int t;
	fscanf(stdin, "%d", &t);
	for (int i = 1;i <= t;i++) {
		int n = 0;
		int x;

		for (int i = 0;i <= 9;i++) {
			int v;
			fscanf(stdin, "%d", &v);
			if (v == 1) data[++n] = i;
		}

		fscanf(stdin, "%d", &x);


		int m = n;
		int pa = 1, pb = n;
		int po = 10;
		int pcount = 2;

		memset(dy, 0, sizeof(dy));
		memset(cnt, 0, sizeof(cnt));


		for (int i = pa;i <= pb;i++) cnt[i] = 1;
		
		int flag = 1;
		while (flag) {
			for (int j = 1;j <= n;j++) {
	//			if (data[j] == 0) continue;
				for (int i = pa;i <= pb;i++) {
					data[++m] = data[i] + po*data[j];
					cnt[m] = pcount;
					if (data[m] > x) {
						flag = 0;
						j = n; i = pb;
						break;
					}
				}
			}

			
			pcount++;
			if (pcount == 7) break;
			pa = pb + 1;
			pb = m;
			po = po * 10;
		}


		for (int i = 1;i <= m;i++) {
			dy[data[i]] = cnt[i];
			for (int j = 1;j <= x;j++) {
				if (data[i] * j > x) break;
				if (dy[j] == 0) continue;
				if (dy[data[i] * j] == 0 || dy[data[i] * j] > dy[j] + cnt[i] + 1) {
					dy[data[i] * j] = dy[j] + cnt[i] + 1;
				}
			}
		}


		if (dy[x] == 0) fprintf(stdout, "#%d %d\n", i, -1);
		else fprintf(stdout, "#%d %d\n", i, dy[x] + 1);	// enter ∏¶ ¥ı«‘
	}
	return 0;

}