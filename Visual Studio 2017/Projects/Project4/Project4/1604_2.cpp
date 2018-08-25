#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 300

double abs(double a) {
	if (a < 0) return -a;
	return a;
}

double min(double a, double b) {
	if (a > b) return b;
	return a;
}

double max(double a, double b) {
	if (a > b) return a;
	return b;
}

struct Point {
	double x, y;
	Point(double x, double y) {
		this->x = x;
		this->y = y;
	}

	Point() {}
};

struct Line {
	double a, b, c;
	Point p, q;
	Line(Point p, Point q) {
		a = p.y - q.y;
		b = -(p.x - q.x);
		c = -(p.y - q.y) * p.x + (p.x - q.x) * p.y;
		this->p = p;
		this->q = q;
	}
};


int N;
double rect_line[4][4] = { { -10, -10, -10, 10 },{ -10, 10, 10, 10 },{ 10, 10, 10, -10 },{ 10, -10, -10, -10 } };
double new_line[MAX][4];
double dat_line[MAX][4];
int ncnt = 0;


Point getCrosspoint(Line l1, Line l2) {
	// 직선의 교차점을 구하는 함수
	// 직선이냐 선분이냐에 따라 결과가 달라짐....
	double a, b, c1;
	double c, d, c2;
	a = l1.a; b = l1.b; c1 = l1.c;
	c = l2.a; d = l2.b; c2 = l2.c;
	double tx, ty;
	if (a * d - b * c == 0) {   // 평행 혹은 일치하는 경우
		return Point(-11, -11); // 교차점 없다고 가정한 반환
	}

	tx = -1 * (d * c1 - b * c2) / (a * d - b * c);
	ty = -1 * (-c * c1 + a * c2) / (a * d - b * c);

	if (!(min(l1.p.x, l1.q.x) <= tx && tx <= max(l1.p.x, l1.q.x)) || !(min(l2.p.x, l2.q.x) <= tx && tx <= max(l2.p.x, l2.q.x))) {
		return Point(-11, -11); // 교차점 없다고 가정한 반환
	}

	return Point(tx, ty);
}

int solve() { // 영역의 수를 카운트하여 반환
	int sum = 1;
	int cnt;
	int check_cnt;
	int edge;
	for (int i = 1;i <= N;i++) {
		Line l1(Point(dat_line[i][0], dat_line[i][1]), Point(dat_line[i][2], dat_line[i][3]));
		cnt = 0;

		// 사각형과 직선 사이의 교차점을 찾아서 직선이 사각형을 가르는 직선인지 확인
		edge = check_cnt = 0;
		for (int j = 0;j <= 3;j++) {
			Line l2(Point(rect_line[j][0], rect_line[j][1]), Point(rect_line[j][2], rect_line[j][3]));
			Point tp = getCrosspoint(l1, l2);
			if (tp.x < -10 || tp.x > 10) continue;
			if (tp.y < -10 || tp.y > 10) continue;

			check_cnt++;
			if ((tp.x == 10 && tp.y == 10) || (tp.x == 10 && tp.y == -10) || (tp.x == -10 && tp.y == 10) || (tp.x == -10 && tp.y == -10)) edge++;
		}

		if (!((edge == 2 && check_cnt == 2) || (edge == 0 && check_cnt == 2) || (edge == 2 && check_cnt == 3) || (edge == 4 || check_cnt == 4))) continue;

		// i번째 직선과 이전 직선들과의 교차점이 사각형 내부에 형성되는지 확인
		for (int j = 1;j <= ncnt;j++) {
			Line l2(Point(new_line[j][0], new_line[j][1]), Point(new_line[j][2], new_line[j][3]));
			Point tp = getCrosspoint(l1, l2);
			if (tp.x <= -10 || tp.x >= 10) continue;
			if (tp.y <= -10 || tp.y >= 10) continue;

			cnt++;
		}

		// 직선 DB추가
		ncnt++;
		for (int j = 0;j <= 3;j++)	new_line[ncnt][j] = dat_line[i][j];

		sum += cnt + 1;

	}
	return sum;
}

int main(void) {
	scanf("%d", &N);
	for (int i = 1;i <= N;i++) {
		for (int j = 0;j <= 3;j++) {
			scanf("%lf", &dat_line[i][j]);
		}
	}

	printf("%d", solve());
	return 0;
}