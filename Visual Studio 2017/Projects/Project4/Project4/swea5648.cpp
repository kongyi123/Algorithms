// 1:36 - 41
// �Ｚ������ ������ �����ε��� �ȵ�.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

using namespace std;

int flag_count;

struct Pos_ {
	double y, x; // ��ġ
	double t; // ���� �ð�
	int aid, bid;

	Pos_() {
		y = x = t = 0;
		aid = bid = 0;
	}
/*
	int operator<(const Pos_ tt) {
		if (this->t < tt.t) return 1;
		else if (this->t == tt.t) {
			if (this->y < tt.y) return 1;
			else if (this->y == tt.y && this->x < tt.x) return 1;
		}

		return 0;
	}
	*/
};


int cmp(const Pos_ a, const Pos_ b) {
	if (a.t < b.t) return 1;
	else if (a.t == b.t) {
		if (a.y < b.y) return 1;
		else if (a.y == b.y && a.x < b.x) return 1;	
	}

	return 0;
}


struct Atom {
	double y;
	double x;
	int dir;
	int K;
	double end_time;
	double end_y;
	double end_x;
};

void swap(Atom& a, Atom&b) {
	Atom t;
	t = a;
	a = b;
	b = t;
}

int set[6][2] = { {3, 1}, {1, 2}, {3, 2}, {1, 0}, {3, 0}, {0, 2} };

// �� ���ڰ� �α����� �� ��ǥ�� ����
Pos_ predict(Atom a, Atom b) {
	// a�� ù��° ���ڷ�
	// b�� �ι�° ���ڷ� ��.
	if (a.x > b.x) swap(a, b);
	else if (a.x == b.x && a.y < b.y) swap(a, b);
	Pos_ P;
	int er;

	er = 1;
	for (int d = 0;d <= 5;d++) {
		if (!(a.dir == set[d][0] && b.dir == set[d][1])) continue;
		switch (d) {
		case 0:
			if (a.x < b.x && a.y < b.y) {
				P.x = b.x;
				P.y = a.y;
				P.t = P.x - a.x;
				if (P.t != b.y - P.y) er = 1;
				else er = 0;
			}
			break;
		case 1:
			if (a.x < b.x && a.y > b.y) {
				P.x = a.x;
				P.y = b.y;
				P.t = a.y - P.y;
				if (P.t != b.x - P.x) er = 1;
				else er = 0;
			}
			break;
		case 2:
			if (a.x < b.x && a.y == b.y) {
				P.x = (a.x + b.x) / 2;
				P.y = a.y;
				P.t = b.x - P.x;
				if (P.t != P.x - a.x) er = 1;
				else er = 0;
			}
			break;
		case 3:
			if (a.x == b.x && a.y > b.y) {
				P.x = a.x;
				P.y = (a.y + b.y) / 2;
				P.t = a.y - P.y;
				if (P.t != P.y - b.y) er = 1;
				else er = 0;
			}
			break;
		case 4:
			if (a.x < b.x && a.y > b.y) {
				P.x = b.x;
				P.y = a.y;
				P.t = P.x - a.x;
				if (P.t != P.y - b.y) er = 1;
				else er = 0;
			}
			break;
		case 5:
			if (a.x < b.x && a.y < b.y) {
				P.x = a.x;
				P.y = b.y;
				P.t = P.y - a.y;
				if (P.t != b.x - P.x) er = 1;
				else er = 0;
			}
			break;
		}
	}

	if (er == 1) {
		P.x = P.y = P.t = -1;
		return P;
	}

	return P;
}

int N;
Atom arr[1001];
Pos_ list[1001];
int lcnt;

int process() {

	for (int i = 1;i <= N;i++) {
		for (int j = i+1;j <= N;j++) {
			Pos_ P = predict(arr[i], arr[j]);
			if (P.t == -1) continue;
			P.aid = i;
			P.bid = j;
			lcnt++;
			list[lcnt] = P;
		}
	}

	sort(&list[1], &list[1] + lcnt, cmp);

	int sum = 0;
	int a, b;
	for (int i = 1;i <= lcnt;i++) {
		a = list[i].aid;
		b = list[i].bid;
		// �ϴ� �Ѵ� ó�� ������ ���.
		if (arr[a].end_time == 0 && arr[b].end_time == 0) {
			sum += arr[a].K + arr[b].K;
			arr[a].end_time = arr[b].end_time = list[i].t; // ��� �ð��� �������� ����.
			arr[a].end_y = arr[b].end_y = list[i].y;
			arr[a].end_x = arr[b].end_x = list[i].x;		// ��� ��ġ�� �������� ����
		}
		else 
		// �� �� �ϳ��� �̹� �����ִ� ��� 
		// ������ �ð��� ��ġ�� �����ϸ� ���� ������.
		if (arr[a].end_time == 0) { // aid�� ������ ���
			if (list[i].t != arr[b].end_time) continue; // ������ �ð��� �ٸ��� ��ŵ
			if (!(list[i].y == arr[b].end_y && list[i].x == arr[b].end_x)) continue;
			sum += arr[a].K;
			arr[a].end_time = list[i].t; // ��� �ð��� �������� ����.
			arr[a].end_y = arr[b].end_y = list[i].y;
			arr[a].end_x = arr[b].end_x = list[i].x;		// ��� ��ġ�� �������� ����

		}
		else if (arr[b].end_time == 0) {
			if (list[i].t != arr[a].end_time) continue; // ������ �ð��� �ٸ��� ��ŵ
			if (!(list[i].y == arr[a].end_y && list[i].x == arr[a].end_x)) continue;
			sum += arr[b].K;
			arr[b].end_time = list[i].t; // ��� �ð��� �������� ����.
			arr[b].end_y = list[i].y;
			arr[b].end_x = list[i].x;		// ��� ��ġ�� �������� ����

		}
	}

	return sum;
}

void init() {
	// �ʱ�ȭ
	for (int i = 1;i <= 1000;i++) {
		arr[i].end_time = arr[i].end_x = arr[i].end_y = arr[i].dir = arr[i].K = arr[i].x = arr[i].y = 0;
	}
	
	for (int i = 1;i <= lcnt;i++) {
		list[i].t = list[i].x = list[i].y = list[i].aid = list[i].bid = 0;
	}
	lcnt = 0;

}


int main(void) {
	int T;
	scanf("%d", &T);
	for (int tc = 1;tc <= T;tc++) {
		init();
		scanf("%d", &N);
		for (int i = 1;i <= N;i++) {
			scanf("%lf%lf%d%d", &arr[i].x, &arr[i].y, &arr[i].dir, &arr[i].K);
		}
		printf("#%d %d\n", tc, process());
	}
	return 0;
}