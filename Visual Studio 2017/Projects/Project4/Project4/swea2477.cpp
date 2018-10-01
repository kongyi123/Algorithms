#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#define INF 0x7fffffff

struct Customer {
	int anum;
	int bnum;
};

struct Buffer {
	int come_time;
	int cid;
};

Customer c[1010];
int in_time[1010];
Buffer buffer[2][1010];
Buffer counter[2][1010];
int a[1010], b[1010];
// 0번이 첫번째 버퍼, 1번이 두번째 버퍼

int N, M, K, A, B;

bool push_buffer(int cid, int time, int type) {
	for (int i = 1;i <= 1000;i++) {
		if (buffer[type][i].cid == 0) {
			buffer[type][i].cid = cid;
			buffer[type][i].come_time = time;
			return 1;
		}
	}

	return 0;
}

int get_least_id(int type) {
	int min = INF;
	for (int i = 1;i <= 1000;i++) {
		if (buffer[type][i].cid != 0) {
			if (min > buffer[type][i].cid)
				min = buffer[type][i].cid;
		}
	}

	if (min == INF) return -1;
	return min;
}

int get_one(int type) {
	int mintime = INF;
	int tid = -1;
	for (int i = 1;i <= 1000;i++) {
		if (buffer[type][i].cid != 0) {
			if (mintime > buffer[type][i].come_time) {
				mintime = buffer[type][i].come_time;
				tid = buffer[type][i].cid;
			}
			else if (mintime == buffer[type][i].come_time) {
				if (c[tid].anum > c[buffer[type][i].cid].anum) {
					tid = buffer[type][i].cid;
				}
			}
		}
	}

	return tid;
}


int get_vac_pos(int type) {
	int len = (type == 0 ? N : M);
	for (int i = 1;i <= len;i++) {
		if (counter[type][i].cid == 0) {
			return i;	// 자리가 있다면 가장 작은 창구 번호가 리턴됨
		}
	}

	return -1; // 자리가 없는 경우
}

int buffer_pop(int type, int id) {
	for (int i = 1;i <= 1000;i++) {
		if (id == buffer[type][i].cid) {
			buffer[type][id].cid = 0;
			buffer[type][id].come_time = 0;
			return id;
		}
	}

	return -1;
}

void counter_push(int type, int pos, int id, int time) {
	counter[type][pos].cid = id;
	counter[type][pos].come_time = time;
}

int counter_pop_bypos(int type, int pos) {
	int temp = counter[type][pos].cid;
	counter[type][pos].cid = 0;
	counter[type][pos].come_time = 0;
	return temp;
}

// 빼내는 사람의 id를 return
int counter_pop(int type, int time) {
	switch (type) {
	case 0:
		for (int i = 1;i <= N;i++) {
			if (counter[type][i].cid == 0) continue;
			if (a[i] == time - counter[type][i].come_time) {
				int tid = counter[type][i].cid;
				counter[type][i].cid = counter[type][i].come_time = 0;
				c[counter[type][i].cid].anum = i;
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
				c[counter[type][i].cid].bnum = i;
				return tid;
			}
		}
		break;
	}

	return -1;
}

void print(int time) {
	printf("time : %d\n", time);
	for (int i = 1;i <= 9;i++) {
		printf("%3d", buffer[0][i].cid);
	}
	printf("\n");

	for (int i = 1;i <= 9;i++) {
		printf("%3d", counter[0][i].cid);
	}
	printf("\n");
	for (int i = 1;i <= 9;i++) {
		printf("%3d", buffer[0][i].cid);
	}
	printf("\n");
	for (int i = 1;i <= 9;i++) {
		printf("%3d", counter[1][i].cid);
	}
	printf("\n");
	printf("\n");
	_getch();
}

int process() {
	int ans = 0;
	int p = 1;
	int count = 0;
	int id, pos;
	for (int time = 0;time <= 1000;time++) {
		print(time);
		// 정비 끝난사람 제거 + counting
		if (time == 20) {
			time = time;
		}

		while (1) {
			int id = counter_pop(1, time);
			if (id != -1) count++;
			else break;
		}

		
		// 정비
		while (1) {
			id = get_one(1);
			pos = get_vac_pos(1);
			if (id != -1 && pos != -1) {
				buffer_pop(1, id);
				counter_pop_bypos(1, pos);
				counter_push(1, pos, id, time);
			}
			else break;
		}



		// 접수 끝난사람 buffer2로
		while (1) {
			int id = counter_pop(0, time);
			if (id != -1) {
				push_buffer(id, time, 1);
			}
			else break;
		}

		// 접수
		while (1) {
			id = get_least_id(0);
			pos = get_vac_pos(0);
			if (id != -1 && pos != -1) {
				buffer_pop(0, id);
				counter_pop_bypos(0, pos);
				counter_push(0, pos, id, time);
			}
			else break;
		}

		// 버퍼에 넣는다.
		while (time == in_time[p] && p <= K) {
			push_buffer(p, time, 0);
			p++;
		}

	}

	return ans;
}

int main(void) {
	int T;
	scanf("%d", &T);
	for (int tc = 1;tc <= T;tc++) {
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