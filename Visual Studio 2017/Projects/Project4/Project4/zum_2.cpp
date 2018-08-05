#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>


using namespace std;

FILE *in = fopen("input.txt", "r");
FILE *out = fopen("output.txt", "w");

int data[1000];

int solution(vector<int> &A) {

	return 0;
}

int main(void) {
	int N;
	fscanf(in, "%d", &N);
	if (N == 1) {
		fprintf(out, "1\n");
		return 0;
	}
	else if (N == 2) {
		fprintf(out, "2\n");
		return 0;
	}

	for (int i = 1;i <= N;i++) {
		fscanf(in, "%d", &data[i]);
	}

	int flag = 0;
	int cnt = 0;
	for (int i = 1;i <= N-1;i++) {
		if (data[i] > data[i + 1]) { // 이상 발견
			if (flag == 0) {
				flag = 1;
				cnt = 0;
				if (i == 1) { // 첫째 나무인 경우
					cnt++; // 첫나무를 잘랐을 때
					if (data[i] <= data[i + 2]) { // 두번째 나무를 잘랐을 때
						cnt++;
					}
					else if (cnt == 0) {
						fprintf(out, "0\n");
						return 0;
					}
				}
				else if (i == N-1) { // 마지막 바로 전 나무인 경우
					if (data[i - 1] <= data[i + 1]) { // 마지막 전 나무를 자르는 경우
						cnt++;
					}
					cnt++; // 마지막 나무를 자르는 경우
				}
				else { // 중간의 경우
					if (data[i - 1] <= data[i + 1]) { // 첫나무가 아닌 경우
						cnt++;
					}
					else {
						fprintf(out, "0\n");
						return 0;
					}
				}

			}
			else if (flag == 1) { // 이상이 두번 이상 발견되는 경우
				fprintf(out, "0\n");
				return 0;
			}
		}
	}

	if (cnt == 0) { // 다 정상인경우
		fprintf(out, "%d\n", N);
	}
	else {
		fprintf(out, "%d\n", cnt);
	}


	return 0;
}


/*
// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int solution(int A[], int N) {
if (N == 1) return 1;
if (N == 2) return 2;

int flag = 0;
int cnt = 0;
for (int i = 0;i < N-1;i++) {
if (A[i] > A[i + 1]) { // 이상 발견
if (flag == 0) {
flag = 1;
cnt = 0;
if (i == 0) { // 첫째 나무인 경우
cnt++; // 첫나무를 잘랐을 때
if (A[i] <= A[i + 2]) { // 두번째 나무를 잘랐을 때
cnt++;
}
else if (cnt == 0) {
return 0;
}
}
else if (i == N-2) { // 마지막 바로 전 나무인 경우
if (A[i - 1] <= A[i + 1]) { // 마지막 전 나무를 자르는 경우
cnt++;
}
cnt++; // 마지막 나무를 자르는 경우
}
else { // 중간의 경우
if (A[i - 1] <= A[i + 1]) { // 첫나무가 아닌 경우
cnt++;
}
else {
return 0;
}
}

}
else if (flag == 1) { // 이상이 두번 이상 발견되는 경우
return 0;
}
}
}

if (cnt == 0) { // 다 정상인경우
return N;
}
else {
return cnt;
}

}

*/