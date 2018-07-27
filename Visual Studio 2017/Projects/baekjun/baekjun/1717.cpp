// �Ʒ� �ڵ��Ѱ� �̿ϼ�... �߸��� ���̰�.. 
// ���� �ʹ� �ʾ Ǯ�̸� ������ �غôµ�
// Ʈ�����·� �׷��� �����µ� �ƹ����� Ʈ���� ���� (� ��忡�� ��Ʈ���� ���µ� �ɸ��� �ִ� �Ÿ�) �� �� �Ϳ��ٰ� ª������ ���̴� ��������
// �׷��� �����ָ� �ִ�� �ɸ��� �Ǵ��� logN������ �ڽ��� �׷��� Ȯ���Ҽ� �ִ�. -> good �ڵ��Ͽ� accept ����
// �װ� �ַ����.

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
		if (a == 0) { // �̾��ش�.
			while (dir[b] != b) b = dir[b];
			while (dir[c] != c) c = dir[c];
			
			if (depth[b] > depth[c]) {
				dir[c] = b; depth[b] = max(depth[b], depth[c] + 1);
			}
			else {
				dir[b] = c; depth[c] = max(depth[b] + 1, depth[c]);
			}
		}
		else {		// Ȯ���Ѵ�.
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