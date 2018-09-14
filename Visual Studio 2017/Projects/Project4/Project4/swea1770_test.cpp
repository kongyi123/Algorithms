#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#define MAX 10000


struct Block {
	int type;
	int base;
	Block(int type, int base) {
		this->type = type;
		this->base = base;
	}

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


int main(void) {
	srand((unsigned)time(NULL));
	int a, b;
	for (int i = 0;i < MAX;i++) {
		a = rand() % 100 + 2;
		b = rand() % 100 + 2;
		arr[i].type = a;
		arr[i].base = b;
	}

	quickSort(arr, 0, MAX - 1);

	Block val;
	int idx;
	for (int i = 1;i <= 100;i++) {
		val.type = i;
		idx = lower_bound(arr, 0, MAX - 1, val);
		if (idx == -1) continue;
		if (val.type != arr[idx].type) {
			printf("%d %d\n", val.type, arr[idx].type);
		}
	}

	return 0;
}