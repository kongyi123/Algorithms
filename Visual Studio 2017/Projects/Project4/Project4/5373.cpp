#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char tcol[3][3];

struct Square {
	char col[3][3];
	// col[0][1] 이 윗면
	Square(char ch) {
		for (int i = 0;i <= 2;i++) {
			for (int j = 0;j <= 2;j++) {
				col[i][j] = ch;
			}
		}
	}
	Square() {}

	void set(char ch) {
		for (int i = 0;i <= 2;i++) {
			for (int j = 0;j <= 2;j++) {
				col[i][j] = ch;
			}
		}
	}
	
	void turn_clockwise() {
		// 대각선을 기준으로 반전 + 좌우 반전 = 90도 시계방향 회전
		for (int i = 0;i <= 2;i++) {
			for (int j = 0;j <= 2;j++) {
				tcol[i][2-j] = col[j][i];
			}
		}

		for (int i = 0;i <= 2;i++) {
			for (int j = 0;j <= 2;j++) {
				col[i][j] = tcol[i][j];
			}
		}
	}
	void turn_counterclock() {
		turn_clockwise(); turn_clockwise(); turn_clockwise();
	}

	void turn_rev() {
		turn_clockwise(); turn_clockwise();
	}

	void turn_p() { // 수평
		for (int i = 0;i <= 2;i++) {
			for (int j = 0;j <= 2;j++) {
				tcol[i][2-j] = col[i][j];
			}
		}
		for (int i = 0;i <= 2;i++) {
			for (int j = 0;j <= 2;j++) {
				col[i][j] = tcol[i][j];
			}
		}
	}
	Square operator=(Square sq) {
		Square ts;
		for (int i = 0;i <= 2;i++) {
			for (int j = 0;j <= 2;j++) {
				ts.col[i][j] = sq.col[i][j];
			}
		}
		return ts;
	}

	void print() {
		for (int i = 0;i <= 2;i++) {
			for (int j = 0;j <= 2;j++) {
				printf("%c", col[i][j]);
			}
			printf("\n");
		}
	}
};

struct Cube {
	Square sq[3][4];
	Cube() {
		Square t;
		t.set('o');
		sq[0][1] = t;
		t.set('g');
		sq[1][0] = t;
		t.set('w');
		sq[1][1] = t;
		t.set('b');
		sq[1][2] = t;
		t.set('y');
		sq[1][3] = t;
		t.set('r');
		sq[2][1] = t;
	}

	void turn_A() {
		Square ts;
		sq[1][3].turn_p();
		ts = sq[1][3];
		sq[1][2].turn_p();
		sq[1][3] = sq[1][2];
		sq[1][2] = sq[1][1];
		sq[1][1] = sq[1][0];
		sq[1][0] = ts;
	}

	void turn_B() {
		Square ts;
		sq[1][3].turn_rev();
		ts = sq[1][3];
		sq[2][1].turn_rev();
		sq[1][3] = sq[2][1];
		sq[2][1] = sq[1][1];
		sq[1][1] = sq[0][1];
		sq[0][1] = ts;
	}
	
	void turnUp_clockwise() {
		sq[0][1].turn_clockwise();
//		Square ts;
//		ts = sq[1][2].col
	}
	void turnUp_counterclock() {
		sq[0][1].turn_counterclock();

	}

	void print() {
		for (int i = 0;i <= 2;i++) {
			for (int j = 0;j <= 3;j++) {
				sq[i][j].print();
				printf("\n");
			}
		}
	}

};


Cube cb;
int N;

void process() {
	// 돌릴 면을 갖다가 위쪽으로 이동시킨다.
	// 윗면을 돌린다.
	// 다시 제자리로 옮긴다. x 6
}


int main(void) {
	int T;

	cb.print();
	scanf("%d", &T);
	for (int tc = 1;tc <= T;tc++) {
		scanf("%d", &N);
		for (int i = 1;i <= N;i++) {
			process();
		}
		
		cb.sq[0][1].print();
	}
	return 0;
}