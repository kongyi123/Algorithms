typedef struct {
	int right;
	int left;
} Result;//1 : up , -1: down

extern Result scale(int f1, int r1, int f2, int r2);
///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

Result r;

int query(int dumpling)
{
	int mid;
	int s, e;
	int pres, pree;
	s = 0; e = dumpling - 1;

	int weight = 1; // ó���� weight > 0 ���� �����ϰ� ����

	while (s < e) { // ���� �ٽ� Ȯ���Ұ� *********************
		mid = (s + e) / 2;
		if ((e - s + 1) % 2 == 0) { // ¦������
			r = scale(s, mid, mid + 1, e);
			if (r.right == 1 && r.left == -1) {
				if (weight > 0) {
					pres = s; pree = e;
					e = mid;
				}
				else {
					pres = s; pree = e;
					s = mid + 1;
				}
			}
			else if (r.right == -1 && r.left == 1) {
				if (weight > 0) {
					pres = s; pree = e;
					s = mid + 1;
				}
				else {
					pres = s; pree = e;
					e = mid;
				}
			}
			else  // ¦�����ε��� �ұ��ϰ� ������ s == e �� �ƴѵ� �������������� weight�� �߸������Ѱ�
			{
				weight = -1;
				int nexts = s;
				int nexte = e;

				s = pres;
				e = pree;

				if (nexts == s) {
					s = (s + e) / 2 + 1;
				}
				else {
					e = (s + e) / 2;
				}

			}
		}
		else { // Ȧ������
			r = scale(s, mid - 1, mid + 1, e);
			if (r.right == 1 && r.left == -1) {
				if (weight > 0) {
					pres = s; pree = e;
					e = mid - 1;
				}
				else {
					pres = s; pree = e;
					s = mid + 1;
				}
			}
			else if (r.right == -1 && r.left == 1) {
				if (weight > 0) {
					pres = s; pree = e;
					s = mid + 1;
				}
				else {
					pres = s; pree = e;
					e = mid - 1;
				}
			}
			else return mid; // �߰�
		}
	}

	return s; // idx
}