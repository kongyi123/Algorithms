#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#include <conio.h>
#define INF 0x7fffffff

struct Customer {
	int anum;
	int bnum;
};

struct Buffer {
	int come_time;
	int cid;
};

Customer c[1001];
int in_time[1001];
Buffer buffer[2][1001];
Buffer counter[2][10];
int a[10], b[10];
// 0번이 첫번째 버퍼, 1번이 두번째 버퍼

int N, M, K, A, B;

bool push_buffer_id(int cid, int time, int type) {
	for (int i = 1;i <= 1000;i++) {
		if (buffer[type][i].cid == 0) {
			buffer[type][i].cid = cid;
			buffer[type][i].come_time = time;
			return 1;
		}
	}

	return 0;
}

int get_least_id_from_buffer(int type) {
	int id_min = INF;
	for (int i = 1;i <= 1000;i++) {
		if (buffer[type][i].cid != 0) {
			if (id_min > buffer[type][i].cid)
				id_min = buffer[type][i].cid;
		}
	}

	if (id_min == INF) return -1;
	return id_min;
}

int get_best_id_for_fix_counter() {
	int mintime = INF;
	int tid = -1;
	for (int i = 1;i <= 1000;i++) {
		if (buffer[1][i].cid != 0) {
			if (mintime > buffer[1][i].come_time) {
				mintime = buffer[1][i].come_time;
				tid = buffer[1][i].cid;
			}
			else if (mintime == buffer[1][i].come_time) {
				if (c[tid].anum > c[buffer[1][i].cid].anum) {
					tid = buffer[1][i].cid;
				}
			}
		}
	}

	return tid;
}

int get_vac_min_index(int type) {
	int len = ((type == 0) ? (N) : (M));
	for (int i = 1;i <= len;i++) {
		if (counter[type][i].cid == 0) {
			return i;	// 자리가 있다면 가장 작은 창구 번호가 리턴됨
		}
	}

	return -1; // 자리가 없는 경우
}

int buffer_pop_byId(int type, int id) {
	for (int i = 1;i <= 1000;i++) {
		if (id == buffer[type][i].cid) {
			buffer[type][i].cid = 0;
			buffer[type][i].come_time = 0;
			return id;
		}
	}

	return -1;
}

void counter_push_on_index(int type, int index, int id, int time) {
	counter[type][index].cid = id;
	counter[type][index].come_time = time;
}

// index자리에 있던 id를 반환
int counter_pop_byIndex(int type, int index) {
	int temp = counter[type][index].cid;
	counter[type][index].cid = 0;
	counter[type][index].come_time = 0;
	return temp;
}

// 빼낼 수 있는 가장 작은 id를 반환
int counter_pop_min_id(int type, int time) {
	switch (type) {
	case 0:
		for (int i = 1;i <= N;i++) {
			if (counter[type][i].cid == 0) continue;
			if (a[i] == time - counter[type][i].come_time) {
				int tid = counter[type][i].cid;
				counter[type][i].cid = counter[type][i].come_time = 0;
				c[tid].anum = i;
				return tid;
			}
		}
		break;
	case 1:
		for (int i = 1;i <= M;i++) {
			if (counter[type][i].cid == 0) continue;
			if (b[i] == time - counter[type][i].come_time) {
				int tid = counter[type][i].cid;
				counter[type][i].cid = counter[type][i].come_time = 0;
				c[tid].bnum = i;
				return tid;
			}
		}
		break;
	}

	return -1;
}

int process() {
	int ans = 0;
	int p = 1;
	int count = 0;
	int id, pos;
	for (int time = 0;time <= 41010;time++) { // 1개의 창구로 처리시간이 20이면, 1000명 x 40 최악의 경우 40000의 시간이 걸릴 수 있다. + 시간1000에 사람이 몰린다면?

		// 정비 끝난사람 제거 + counting
		while (1) {
			int id = counter_pop_min_id(1, time);
			if (id != -1) {
				count++;
			}
			else break;
		}


		// 접수 끝난사람 버퍼1로
		while (1) {
			int id = counter_pop_min_id(0, time); // 접수가 끝난사람들을 버퍼1로 옮기는데, 가장 창구번호가 작은애들부터 
			if (id != -1) {
				push_buffer_id(id, time, 1);
			}
			else break;
		}

		// 정비 창구에 다리가 있고, 버퍼1에 기다리는 고객이 있다면, 바로 넣는다.
		while (1) {
			id = get_best_id_for_fix_counter(); // ① 먼저 기다리는 고객이 우선한다. 
												// ② 두 명 이상의 고객들이 접수 창구에서 동시에 접수를 완료하고 정비 창구로 이동한 경우, 이용했던 접수 창구번호가 작은 고객이 우선한다.
			pos = get_vac_min_index(1); // ③ 빈 창구가 여러 곳인 경우 정비 창구번호가 작은 곳으로 간다.
			if (id != -1 && pos != -1) {
				buffer_pop_byId(1, id);
				counter_push_on_index(1, pos, id, time);
			}
			else break;
		}

		// 버퍼0에 넣는다.
		while (p <= K && time == in_time[p]) {
			push_buffer_id(p, time, 0);
			p++;
		}

		// 접수 창구에 자리가 있고, 버퍼0에 기다리는 고객이있다면, 바로 넣는다.
		while (1) {
			id = get_least_id_from_buffer(0);	//   ① 여러 고객이 기다리고 있는 경우 고객번호가 낮은 순서대로 우선 접수한다.
			pos = get_vac_min_index(0); //    ② 빈 창구가 여러 곳인 경우 접수 창구번호가 작은 곳으로 간다.
			if (id != -1 && pos != -1) {
				buffer_pop_byId(0, id);
				counter_push_on_index(0, pos, id, time);
			}
			else break;
		}
		if (count == K) break;
	}


	for (int i = 1;i <= K;i++) {
		if (c[i].anum == A && c[i].bnum == B) {
			ans += i;
		}
	}


	if (ans == 0) return -1;
	return ans;
}


void init() {
	for (int i = 1;i <= 1000;i++) {
		c[i].anum = c[i].bnum = 0;
		in_time[i] = 0;
		buffer[0][i].cid = buffer[0][i].come_time = 0;
		buffer[1][i].cid = buffer[1][i].come_time = 0;
	}

	for (int i = 0;i <= 9;i++) {
		a[i] = b[i] = 0;

		counter[0][i].cid = counter[0][i].come_time = 0;
		counter[1][i].cid = counter[1][i].come_time = 0;
	}
}

int main(void) {
	int T;
	scanf("%d", &T);
	for (int tc = 1;tc <= T;tc++) {
		init();
		scanf("%d%d%d%d%d", &N, &M, &K, &A, &B);
		for (int i = 1;i <= N;i++) 
			scanf("%d", &a[i]);
		for (int i = 1;i <= M;i++)
			scanf("%d", &b[i]);
		for (int i = 1;i <= K;i++) {
			scanf("%d", &in_time[i]);
		}

		printf("#%d %d\n", tc, process());
	}

	return 0;
}