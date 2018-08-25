// 생각이 정리 된 후 다시 짜본 코드
// 오래걸린 이유 : 각 모듈 단위로 확실한 확인이 안됐던게 가장 큰 이유.
// 결국은 모듈 단위 테스트가 확실히 안됐다..

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
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
};

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	int val = x1*y2 + x2*y3 + x3*y1 - x1*y3 - x2*y1 - x3*y2;
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
	else if (t1 == 0 && t2 == 0) return 0; // L자형
	return -1;      // 교차안함
}


int N;
double rect_line[4][4] = { { -10, -10, -10, 10 },{ -10, 10, 10, 10 },{ 10, 10, 10, -10 },{ 10, -10, -10, -10 } };
double new_line[MAX][4];
double dat_line[MAX][4];
int ncnt = 0;


Point getCrosspoint(Line l1, Line l2) {
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

	return Point(tx, ty);
}


int solve() { // 영역의 수를 카운트하여 반환
	int sum = 1;
	int cnt;
	int cross_with_rect_edge_cnt;
	int cross_with_rect_line_cnt;
	int temp;
	for (int i = 1;i <= N;i++) {
		Line l1(Point(dat_line[i][0], dat_line[i][1]), Point(dat_line[i][2], dat_line[i][3]));
		cnt = 0;

		cross_with_rect_line_cnt = cross_with_rect_edge_cnt = 0;
		for (int j = 0;j <= 3;j++) {
			Line l2(Point(rect_line[j][0], rect_line[j][1]), Point(rect_line[j][2], rect_line[j][3]));
			temp = isIntersec(l1, l2);
			if (temp == 1) cross_with_rect_line_cnt++;
			else if (temp == 0) cross_with_rect_edge_cnt++;
		}
		
		if (!(cross_with_rect_line_cnt == 2 ||  // 두 교차점이 선을 지나는 경우
			cross_with_rect_edge_cnt == 4 ||  // 두 교차점이 모서리를 지나는 경우
			(cross_with_rect_line_cnt == 1 && cross_with_rect_edge_cnt == 2))) continue; // 교차점 하나는 모서리 하나는 선을 지나는 경우


		for (int j = 1;j <= ncnt;j++) {
			Line l2(Point(new_line[j][0], new_line[j][1]), Point(new_line[j][2], new_line[j][3]));
//			if (isIntersec(l1, l2) < 0) continue; // 교차안하면 볼것도 x
			Point tp = getCrosspoint(l1, l2);
			if (tp.x <= -10 || tp.x >= 10) continue;
			if (tp.y <= -10 || tp.y >= 10) continue;
			
			cnt++;
		}

		ncnt++;
		for (int j = 0;j <= 3;j ++)	new_line[ncnt][j] = dat_line[i][j];

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