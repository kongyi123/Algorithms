#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include <vector>
using namespace std;

#define MAX_N 20
#define MOD 1003

int N;

struct Box_s
{
	int x, y, z;
};

Box_s Box[MAX_N];

int visit = 0;
int cache[1 << (MAX_N - 1)+1][MAX_N][3];
int c1[(1 << (MAX_N - 1)) * 60 + 1];
char c2[(1 << (MAX_N - 1)) * 60 + 1];
char c3[(1 << (MAX_N - 1)) * 60 + 1];
int cnt;

int max(int a, int b) {
	if (a > b) return a;
	return b;
}

int back(int x, int y, int height, int n, int k) {
	if (cache[visit][n][k]) return cache[visit][n][k];

	int vmax = 0;
	for (int i = 0; i < N; i++) {
		if (visit & (1 << i)) continue;
		visit |= (1 << i);

		if ((Box[i].x <= x && Box[i].y <= y) || (Box[i].y <= x && Box[i].x <= y)) {
			if ((Box[i].x == x && Box[i].y == y) || (Box[i].y == x && Box[i].x == y)) {
				if (n < i) {
					vmax = max(vmax, back(Box[i].x, Box[i].y, Box[i].z, i, 0));
				}
			}
			else vmax = max(vmax, back(Box[i].x, Box[i].y, Box[i].z, i, 0));
		}

		if ((Box[i].y <= x && Box[i].z <= y) || (Box[i].z <= x && Box[i].y <= y)) {
			if ((Box[i].y == x && Box[i].z == y) || (Box[i].z == x && Box[i].y == y)) {
				if (n < i) {
					vmax = max(vmax, back(Box[i].y, Box[i].z, Box[i].x, i, 1));
				}
			}
			else vmax = max(vmax, back(Box[i].y, Box[i].z, Box[i].x, i, 1));
		}

		if ((Box[i].x <= x && Box[i].z <= y) || (Box[i].z <= x && Box[i].x <= y)) {
			if ((Box[i].x == x && Box[i].z == y) || (Box[i].z == x && Box[i].x == y)) {
				if (n < i) {
					vmax = max(vmax, back(Box[i].x, Box[i].z, Box[i].y, i, 2));
				}
			}
			else vmax = max(vmax, back(Box[i].x, Box[i].z, Box[i].y, i, 2));
			
		}

		visit &= ~(1 << i);
	}

	c1[cnt] = visit;
	c2[cnt] = n;
	c3[cnt] = k;
	cnt++;

	cache[visit][n][k] = vmax + height;

	return cache[visit][n][k];
}


int process() {

	for (int i = 0;i < cnt;i++) 
		cache[c1[i]][c2[i]][c3[i]] = 0;

	visit = 0;
	cnt = 0;
	int vmax = 0;

	for (int i = 0; i < N; i++) {
		visit |= (1 << i);
		vmax = max(vmax, back(Box[i].x, Box[i].y, Box[i].z, i, 0));
		vmax = max(vmax, back(Box[i].y, Box[i].z, Box[i].x, i, 1));
		vmax = max(vmax, back(Box[i].x, Box[i].z, Box[i].y, i, 2));
		visit &= ~(1 << i);
	}

	return vmax;
}

int main(void) {
	int T;
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &T);

	for (int tc = 1; tc <= T; ++tc) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) 
			scanf("%d %d %d", &Box[i].x, &Box[i].y, &Box[i].z);
		printf("#%d %d\n", tc, process());
	}

	return 0;
}