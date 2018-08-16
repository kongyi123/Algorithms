// 1:30 틀림..

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define INF 0x7fffffff

using namespace std;

int min_ = INF;
int dat[52][52];
int house_num, store_num;
int chicken_dist[110][15];	// 배열 크기를 52로 설정해서 틀렸음.
int house_pos[110][2];
int store_pos[15][2];
int N, M;
int q[15];

void back(int cur, int cnt) {
	if (cnt == M) {
		int city_chicken_dist = 0;
		for (int i = 1;i <= house_num;i++) {
			int cd_closest = INF;
			for (int j = 1;j <= cnt;j ++) {
				if (cd_closest > chicken_dist[i][q[j]])
					cd_closest = chicken_dist[i][q[j]];
			}
			
			city_chicken_dist += cd_closest;
			
		}

		if (min_ > city_chicken_dist) {
			min_ = city_chicken_dist;
		}

		return;  
				 
	}

	for (int i = cur + 1;i <= store_num;i++) {
		q[cnt + 1] = i;
		back(i, cnt + 1);
		q[cnt + 1] = 0;
	}
}

int abs(int val) {
	if (val < 0) return -val;
	return val;
}

int main(void) {
	scanf("%d %d", &N, &M);
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			scanf("%d", &dat[i][j]);
			if (dat[i][j] == 1) {
				house_num ++;
				house_pos[house_num][0] = i;
				house_pos[house_num][1] = j;
			}
			else if (dat[i][j] == 2) {
				store_num++;
				store_pos[store_num][0] = i;
				store_pos[store_num][1] = j;
			}
		}
	}

	for (int i = 1;i <= house_num;i++) {
		for (int j = 1;j <= store_num;j++) {
			chicken_dist[i][j] = abs(house_pos[i][0] - store_pos[j][0]) 
								+ abs(house_pos[i][1] - store_pos[j][1]);
		}
	}
	
	for (int i = 1;i <= store_num;i++) {
		q[1] = i;
		back(i, 1);
//		q[1] = 0;
	}
	
	printf("%d", min_);
	
	return 0;
}