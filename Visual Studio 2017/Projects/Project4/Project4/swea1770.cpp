#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define dbg printf

#define MAX 30000
//#define MAX 6

using namespace std;

int makeBlock(int module[][4][4]);

int main(void)
{
	freopen("input.txt", "r", stdin);
	static int module[MAX][4][4];

	srand(3); // 3 will be changed

	for (int tc = 1; tc <= 10; tc++)
	{
		for (int c = 0; c < MAX; c++)
		{
			int base = 1 + (rand() % 6);
			for (int y = 0; y < 4; y++)
			{
				for (int x = 0; x < 4; x++)
				{
					module[c][y][x] = base + (rand() % 3);
				}
			}
		}
		cout << "#" << tc << " " << makeBlock(module) << endl;
	}

	_getch();
	return 0;
}

#define INF 0x7fffffff
// to, from
void copy(int a[][4], int b[][4]) {
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			a[i][j] = b[i][j];
		}
	}
}

// to, from
void LURD_deching(int a[][4], int b[][4]) {
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			a[i][j] = b[j][i];
		}
	}
}

// to, from
void Ychuk_deching(int a[][4], int b[][4]) {
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			a[i][j] = b[i][3 - j];
		}
	}
}

// arr, mask
void arr_to_mask(const int a[][4], int &mask) {
	mask = 0;
	int t2 = 1;
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			mask += a[i][j] * t2;
			t2 = t2 * 3;
		}
	}
}

// mask, arr
void mask_to_arr(int mask, int a[][4]) {
	int t = 14348907;
	for (int i = 3;i >= 0;i--) {
		for (int j = 3;j >= 0;j--) {
			a[i][j] = mask / t;
			mask -= a[i][j] * t;
			t = t / 3;
		}
	}
}


struct Block {
	int type;
	int base;
	int height;

	Block() {}

	bool operator<(Block temp) {
		if (this->type < temp.type) {
			return 1;
		}
		else if (this->type == temp.type) {
			if (this->base > temp.base) {
				return 1;
			}
		}
		return 0;
	}
	
	bool operator<=(Block temp) {
		if (this->type < temp.type) {
			return 1;
		}
		else if (this->type == temp.type) {
			if (this->base >= temp.base) {
				return 1;
			}
		}
		return 0;
	}

	bool operator>=(Block temp) {
		if (this->type >= temp.type) return 1;
		return 0;
	}


	bool operator==(Block temp) {
		if (this->type == temp.type) return 1;
		return 0;
	}
};

Block arr[MAX];

template<typename T>
void quickSort(T input[], int first, int last)
{
	int pivot;
	int i;
	int j;
	T temp;

	if (first < last) {
		pivot = first;
		i = first;
		j = last;

		while (i < j) {
			while (input[i] <= input[pivot] && i < last) i++;
			while (input[pivot] < input[j]) j--;
			if (i < j) {
				temp = input[i];
				input[i] = input[j];
				input[j] = temp;
			}
		}

		temp = input[pivot];
		input[pivot] = input[j];
		input[j] = temp;

		quickSort(input, first, j - 1);
		quickSort(input, j + 1, last);
	}
}

template<typename T>
int lower_bound(T arr[], int s, int e, T val)
{
	int mid;
	while (s < e) {
		mid = (s + e) / 2;
		if (arr[mid] >= val) e = mid;
		else s = mid + 1;
	}

	if (arr[s] == val)
		return s;
	return -1;
}

int getPair(int mask) 
{
	int a[4][4];
	int b[4][4];
	int t = 14348907;
	int pair_mask = 0;
	int tmask = mask;
	int max = -INF;

	for (int i = 3;i >= 0;i--) {
		for (int j = 3;j >= 0;j--) {
			a[i][j] = tmask / t;
			if (max < a[i][j]) max = a[i][j];
			tmask = tmask - (a[i][j] * t);
			t = t / 3;
		}
	}

	Ychuk_deching(b, a);

	t = 14348907;
	for (int i = 3;i >= 0;i--) {
		for (int j = 3;j >= 0;j--) {
			pair_mask = pair_mask + ((max-b[i][j]) * t);
			t = t / 3;
		}
	}
	
	return pair_mask;
}


// mask를 시계방으로 돌려서 mask반환
int turnRight(int mask) {
	int a[4][4], b[4][4], c[4][4];
	int turn_mask;

	mask_to_arr(mask, a);
	LURD_deching(b, a);
	Ychuk_deching(c, b);
	arr_to_mask(c, turn_mask);

	return turn_mask;
}

int check[MAX];

int findEig(int mask) {
	int min = INF;
	for (int i = 0;i <= 3;i++) {
		if (min > mask) min = mask;
		mask = turnRight(mask);
	}

	return min;
}


int getMin(int tarr[][4]) {
	int min = INF;
	for (int y = 0;y < 4;y++) {
		for (int x = 0;x < 4;x++) {
			if (min > tarr[y][x])
				min = tarr[y][x];
		}
	}

	return min;
}

int getMax(int tarr[][4]) {
	int max = -INF;
	for (int y = 0;y < 4;y++) {
		for (int x = 0;x < 4;x++) {
			if (max < tarr[y][x])
				max = tarr[y][x];
		}
	}

	return max;
}

void transformation(int module[][4][4]) {
	int base;
	int t, mask;
	for (int i = 0;i < MAX;i++) {
		base = getMin(module[i]);	// base값을 구함
		t = 1; mask = 0;
		for (int y = 0;y < 4;y++) {
			for (int x = 0;x < 4;x++) {
				mask = mask + t * (module[i][y][x] - base);
				t = t * 3;
			}
		}

		arr[i].type = findEig(mask);
		arr[i].base = base;				// 가장 낮은 높이
		arr[i].height = getMax(module[i]); // 가장 높은 높이
	}

	quickSort(arr, 0, MAX - 1); // 정렬
}

int match(Block cur) {
	int idx;
	Block pair;
	pair.type = findEig(getPair(cur.type));
	idx = lower_bound(arr, 0, MAX - 1, pair);
	if (idx == -1) return 0;
	while (idx < MAX) {
		if (arr[idx].type != pair.type) break;
		if (check[idx] == 1) {
			idx++;
			continue;
		} else break;
	}

	if (arr[idx].type == pair.type) {
		check[idx] = 1;
		return arr[idx].height + cur.base;

//		아래가 안되는 이유는 Pair를 구할 때 Y축 대칭을 하기 때문.
//		return arr[idx].base + cur.base + arr[idx].type % 3 + getPair(arr[idx].type) % 3;
//		return arr[idx].base + cur.base + cur.type % 3 + getPair(cur.type) % 3;

	}

	return 0;
}

int makeBlock(int module[][4][4])
{
	for (int i = 0;i < MAX;i++) check[i] = 0;
	int sum = 0;
	transformation(module); // bitmask로 바꿔서 1차원 배열에 정렬된 형태로 넣음

	// 매칭
	for (int i = 0;i < MAX;i++) {
		if (check[i] == 1) continue;
		check[i] = 1;
		sum += match(arr[i]);
	}


	return sum;
}