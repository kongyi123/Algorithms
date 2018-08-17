// 1:00 �ð��ʰ�
// 1:08 Accepted .... �ܼ� �ùķ��̼����� backtracking�� �ϴ� �ð��ʰ�
// ������� �ϴ� ��� ���� 
// ����� : 1. ��ٸ��� �ϳ� �߰��Ҷ����� �ѽ��� �� ������ �� ����. ���� �����Ǿ���� ���� ���� ���� > ���� Ƚ�� �� ��� return
//          2. ������ ���� min���� �� depth�� Ŀ���� return

// 1~2���������ص� ���.... �ϳ� �߰��غ���. 3. ��ٸ��� �߰����� �� ������ ���� �ʴ� ��쿡�� return    <- �����ִµ�..
// ���ϳ� �߰�                               4. ��ٸ��� ���� ������ �ٷ� ��ĭ���� ������ return (�ߺ� ����) <- �̰� Ʋ��
//..... ���� �ߺ� ó�� �߰�.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define INF 0x7fffffff

int N, H, M;
int table[300][20];
int min = INF;

int goal(int s) {
	int y, x;
	y = 1; x = s;
	for (int y = 1;y <= H;y++) {
		if (table[y][x] == 1) x++;
		else if (table[y][x] == -1) x--;
	}
	return x;
}

int check() { // ¦�� �ٸ����� ���� ���
	int cnt = 0;
	for (int i = 1;i <= N;i++) {
		if (i != goal(i)) {
			cnt++;
		}
	}

	return cnt;
}

void back(int cnt, int ercnt, int row) {
	if (min < cnt) return;
	if (cnt <= 3) {
		int t;
		if ((t = check()) == 0) {
			if (min > cnt) {
				min = cnt;
			}
		}
		if (t > (3 - cnt)*2) return;


		for (int i = row;i <= H;i++) {			// ���� �����
			for (int j = 1;j <= N - 1;j++) {
				if (table[i][j] == 0 && table[i][j+1] == 0) {
					table[i][j] = 1; table[i][j + 1] = -1;
					back(cnt + 1, t, i);
					table[i][j] = table[i][j + 1] = 0;
				}
			}
		}

	}
	else return;
}

int main(void) {
	int a, b;
	scanf("%d %d %d", &N, &M, &H);
	
	for (int i = 1;i <= M;i++) {
		scanf("%d %d", &a, &b);
		table[a][b] = 1;
		table[a][b + 1] = -1;
	}

	back(0, INF, 1);																										

	if (min == INF) {
		printf("-1");
	}
	else printf("%d", min);
	return 0;
}