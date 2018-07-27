#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100

FILE *in = fopen("input.txt", "r");
FILE *out = fopen("output.txt", "w");


int arr[MAX];
int size;

void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}

void push(int val) {
	if (size == 0) {
		arr[0] = val;
		size++;
		return;
	}
	else {
		arr[size] = val;
		int cur = size;
		
		size++;
		while (cur != 0) {
			int parent = (cur - 1) / 2;
			if (arr[cur] < arr[parent]) {
				swap(arr[cur], arr[parent]);
				cur = parent;
			}
			else break;
		}
	}
}

void input() {
	int N;
	fscanf(in, "%d", &N);
	for (int i = 1;i <= N;i++) {
		int val;
		fscanf(in, "%d", &val);
		push(val);
	}
}

int pop() {
	if (size == 0) {
		return -1;
	}
	
	int temp = arr[0];
	arr[0] = arr[size-1];
	size--;

	int cur = 0;
	int left, right;
	while (1) {
		left = cur * 2 + 1;
		right = cur * 2 + 2;
		if (left >= size) {
			break;
		}

		int tp = cur, tval = arr[cur];
		
		if (left < size && tval > arr[left]) {
			tval = arr[left];
			tp = left;
		}

		if (right < size && tval > arr[right]) {
			tval = arr[right];
			tp = right;
		}



		if (arr[cur] > tval) {
			swap(arr[cur], arr[tp]);
			cur = tp;
		}
		else break;
	}


	return temp;
}

void output() {
	while (1) {
		int temp;
		if ((temp = pop()) != -1) {
			fprintf(out, "%d ", temp);
		}
		else break;
	}

}


int main(void) {
	input();
	// check....ok.

	output();
	// check....ok.

	return 0;
}