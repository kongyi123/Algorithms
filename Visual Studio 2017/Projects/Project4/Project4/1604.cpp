#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ERR 0.00000001
#define MAX 300

double abs(double a) {
	if (a < 0) return -a;
	return a;
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

	int operator==(Line l) {
		if (a != 0) {
			if (l.a == 0) return 0;
			if (abs(b / a - l.b / l.a) <= ERR) {
				if (abs(c / a - l.c / l.a) <= ERR) {
					return 1;
				}
			}
		}
		else if (b != 0) {
			if (l.b == 0) return 0;
			if (abs(a / b - l.a / l.b) <= ERR) {
				if (abs(c / b - l.c / l.b) <= ERR) {
					return 1;
				}
			}
		}
		return 0;
	}
};

int ccw(double x1, double y1, double x2, double y2, double x3, double y3) {
	double val = x1*y2 + x2*y3 + x3*y1 - x1*y3 - x2*y1 - x3*y2;
	if (val > 0) {
		return 1;
	}
	else if (val < 0) {
		return -1;
	}
	return 0;
}

int isIntersec(Line l1, Line l2) {
	int t1, t2;
	t1 = ccw(l1.p.x, l1.p.y, l1.q.x, l1.q.y, l2.p.x, l2.p.y) * ccw(l1.p.x, l1.p.y, l1.q.x, l1.q.y, l2.q.x, l2.q.y);
	t2 = ccw(l2.p.x, l2.p.y, l2.q.x, l2.q.y, l1.p.x, l1.p.y) * ccw(l2.p.x, l2.p.y, l2.q.x, l2.q.y, l1.q.x, l1.q.y);
	if (t1 == 0 && t2 < 0) return 0; // T자형
	else if (t1 < 0 && t2 == 0) return 0; // T자형
	else if (t1 < 0 && t2 < 0) return 1; // X자형
//	else if (t1 == 0 && t2 == 0) return -1; // 평행 혹은 일치
	return -1;		// 교차안함
}


int N;
double tpoint[MAX * MAX][2];
double rect_line[4][4] = { { -10, -10, -10, 10 },{ -10, 10, 10, 10 },{ 10, 10, 10, -10 },{ 10, -10, -10, -10 } };
double new_line[MAX][4];
double dat_line[MAX][4];
int ncnt = 0;

int lineCheck(Line line) { // 선이 중복되면 1 반환, 중복안되면 0 반환
	for (int i = 1;i <= ncnt;i++) {
		Line tline(Point(new_line[i][0], new_line[i][1]), Point(new_line[i][2], new_line[i][3]));
		if (tline == line) {
			return 1;
		}
	}
	return 0;
}

Point getCrosspoint(Line l1, Line l2) {
	double a, b, c1;
	double c, d, c2;
	a = l1.a; b = l1.b; c1 = l1.c;
	c = l2.a; d = l2.b; c2 = l2.c;
	double tx, ty;
	if (a * d - b * c == 0) {	// 평행 혹은 일치하는 경우
		return Point(-11, -11);	// 교차점 없다고 가정한 반환
	}

	tx = -1 * (d * c1 - b * c2) / (a * d - b * c);
	ty = -1 * (-c * c1 + a * c2) / (a * d - b * c);

	return Point(tx, ty);
}


int solve() { // 영역의 수를 카운트하여 반환
	int sum = 1;
	int cnt;
	int tcnt;
	int flag, no;
	int tpcnt;
	int cross_with_rect_edge_cnt;
	int cross_with_rect_line_cnt;
	int temp;
//	printf(" \n");
	for (int i = 1;i <= N;i++) {
		Line l1(Point(dat_line[i][0], dat_line[i][1]), Point(dat_line[i][2], dat_line[i][3]));
		tcnt = 0;
		flag = 0;
		tpcnt = 0;
		cnt = 0;

		// 사각형을 지나는 직선인지
		cross_with_rect_line_cnt = cross_with_rect_edge_cnt = 0;
		for (int j = 0;j <= 3;j++) {
			Line l2(Point(rect_line[j][0], rect_line[j][1]), Point(rect_line[j][2], rect_line[j][3]));
			temp = isIntersec(l1, l2);
			if (temp == 1) cross_with_rect_line_cnt++;
			else if (temp == 0) cross_with_rect_edge_cnt++;
		}
		
		if (cross_with_rect_line_cnt == 2 ||  // 두 교차점이 선을 지나는 경우
			cross_with_rect_edge_cnt == 4 ||  // 두 교차점이 모서리를 지나는 경우
			(cross_with_rect_line_cnt == 1 && cross_with_rect_edge_cnt == 2)) { // 교차점 하나는 모서리 하나는 선을 지나는 경우

			// 선이 중복되는지
	//		if (lineCheck(l1) == 1) continue;

			for (int j = 0;j <= 3;j++) {
				Line l2(Point(rect_line[j][0], rect_line[j][1]), Point(rect_line[j][2], rect_line[j][3]));
				Point tp = getCrosspoint(l1, l2);	// 교차점

				if (l1 == l2) {	// 사각형의 변 위의 직선인 경우
					flag = 1;
					break;
				}
				if (tp.x < -10 || tp.x > 10) continue; // 선분의 교차점이 사각형 범위에 속하는지
				if (tp.y < -10 || tp.y > 10) continue;
				no = 1;
				if (j != 0) {
					no = 0;
					for (int k = 1;k <= tpcnt;k++) { // 서로다른 교차점인지
						if (abs(tpoint[k][0] - tp.x) <= ERR && abs(tpoint[k][1] - tp.y) <= ERR) {
							no = 1; break;
						}
					}
				}
				if (j == 0 || no == 0) {
					cnt++;
					tpcnt++;
					tpoint[tpcnt][0] = tp.x;
					tpoint[tpcnt][1] = tp.y;
				}
			}

			if (flag == 1) continue; // 다음 직선

			if (tpcnt != 2) continue;	// (서로다른) 교차점의 개수가 2인지
			// 서로다른 교차점이 두개인 선 찾아낸 상태

			Line l3(Point(tpoint[1][0], tpoint[1][1]), Point(tpoint[2][0], tpoint[2][1])); // 정사각형 위의 점으로 변경됨

			int cross_with_new_line_cnt = 0;
			for (int j = 1;j <= ncnt;j++) {
				Line l2(Point(new_line[j][0], new_line[j][1]), Point(new_line[j][2], new_line[j][3]));
				if (isIntersec(l3, l2) >= 0) cross_with_new_line_cnt++;
			}

			ncnt++;
			new_line[ncnt][0] = tpoint[1][0]; new_line[ncnt][1] = tpoint[1][1];
			new_line[ncnt][2] = tpoint[2][0]; new_line[ncnt][3] = tpoint[2][1];

			sum += cross_with_new_line_cnt + 1;
		}
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

