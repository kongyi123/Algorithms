// 아래 코딩한건 미완성... 잘못된 논리이고.. 
// 밤이 너무 늦어서 풀이를 생각만 해봤는데
// 트리형태로 그룹을 나누는데 아무래도 트리의 길이 (어떤 노드에서 루트까지 가는데 걸리는 최대 거리) 가 긴 것에다가 짧은것을 붙이는 형식으로
// 그룹을 합쳐주면 최대로 걸리게 되더라도 logN번만에 자신의 그룹을 확인할수 있다. -> good 코딩하여 accept 받음
// 그게 솔루션임.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int dir[1000010];
int depth[1000010];

int max(int a, int b) {
	if (a > b) return a;
	return b;
}

int main(void) {
	int a, b, c;
	int n, m;
	fscanf(stdin, "%d %d", &n, &m);

	for (int i = 1;i <= 1000010;i++) dir[i] = i;

	for (int i = 1;i <= m;i++) {
		fscanf(stdin, "%d %d %d", &a, &b, &c);
		if (a == 0) { // 이어준다.
			while (dir[b] != b) b = dir[b];
			while (dir[c] != c) c = dir[c];
			
			if (depth[b] > depth[c]) {
				dir[c] = b; depth[b] = max(depth[b], depth[c] + 1);
			}
			else {
				dir[b] = c; depth[c] = max(depth[b] + 1, depth[c]);
			}
		}
		else {		// 확인한다.
			while (dir[b] != b) {
				b = dir[b];
			}
			while (dir[c] != c) {
				c = dir[c];
			}
			if (b == c) fprintf(stdout, "YES\n");
			else fprintf(stdout, "NO\n");
		}

	}
	return 0;
}