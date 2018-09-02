// �޸������̼�
// �ٽ� : (����, ������ ����, �� ������ ����) => ���� ����
// �ð����⵵ => (�־��� ��� �� ���״ϱ�.. 2^20 * 22 * 3) * 50 = 30��..
// ��� ����� ����x����x���� �� �� �Ȱ��� ���...�� �־��� �����.


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int max(int a, int b) {
	if (a > b) return a;
	return b;
}

int N;
int T;
int dat[20][3];
int dy[1 << 20 + 1][20][3];

int back(int x, int y, int height, int type, int id, int visit) { // ����, ����, ���� (�������� ���� ��), ������ ������ ����, ������ ������ ��ȣ, ����
	if (dy[visit][id][type]) return dy[visit][id][type]; // �޸������̼�

	int vmax = 0;
	for (int i = 0; i < N;i++) {
		if (visit & (1 << i)) continue; // �̹� ���տ� ���ԵǾ� ������
		if ((dat[i][0] <= x && dat[i][1] <= y) || (dat[i][1] <= x && dat[i][0] <= y)) vmax = max(vmax, back(dat[i][0], dat[i][1], dat[i][2], 0, i, visit | (1 << i)));
		if ((dat[i][1] <= x && dat[i][2] <= y) || (dat[i][2] <= x && dat[i][1] <= y)) vmax = max(vmax, back(dat[i][1], dat[i][2], dat[i][0], 1, i, visit | (1 << i)));
		if ((dat[i][0] <= x && dat[i][2] <= y) || (dat[i][2] <= x && dat[i][0] <= y)) vmax = max(vmax, back(dat[i][0], dat[i][2], dat[i][1], 2, i, visit | (1 << i)));
	}
	dy[visit][id][type] = vmax + height;

	return dy[visit][id][type];
}

int main(void) {
	scanf("%d", &T);
	for (int tc = 1; tc <= T;tc++) {
		for (int i = 1;i <= 1 << 20;i++) { // �޸������̼��� ���� �ʱ�ȭ
			for (int j = 0;j < 20;j++) {
				for (int k = 0;k <= 2;k++) {
					dy[i][j][k] = 0;
				}
			}
		}
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d %d %d", &dat[i][0], &dat[i][1], &dat[i][2]);
		}

		int vmax = 0;
		for (int i = 0; i < N;i++) {
			vmax = max(vmax, back(dat[i][0], dat[i][1], dat[i][2], 0, i, (1 << i)));
			vmax = max(vmax, back(dat[i][1], dat[i][2], dat[i][0], 1, i, (1 << i)));
			vmax = max(vmax, back(dat[i][0], dat[i][2], dat[i][1], 2, i, (1 << i)));
		}

		printf("#%d %d\n", tc, vmax);
	}

	return 0;
}
