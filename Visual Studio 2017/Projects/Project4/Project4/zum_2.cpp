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
		if (data[i] > data[i + 1]) { // �̻� �߰�
			if (flag == 0) {
				flag = 1;
				cnt = 0;
				if (i == 1) { // ù° ������ ���
					cnt++; // ù������ �߶��� ��
					if (data[i] <= data[i + 2]) { // �ι�° ������ �߶��� ��
						cnt++;
					}
					else if (cnt == 0) {
						fprintf(out, "0\n");
						return 0;
					}
				}
				else if (i == N-1) { // ������ �ٷ� �� ������ ���
					if (data[i - 1] <= data[i + 1]) { // ������ �� ������ �ڸ��� ���
						cnt++;
					}
					cnt++; // ������ ������ �ڸ��� ���
				}
				else { // �߰��� ���
					if (data[i - 1] <= data[i + 1]) { // ù������ �ƴ� ���
						cnt++;
					}
					else {
						fprintf(out, "0\n");
						return 0;
					}
				}

			}
			else if (flag == 1) { // �̻��� �ι� �̻� �߰ߵǴ� ���
				fprintf(out, "0\n");
				return 0;
			}
		}
	}

	if (cnt == 0) { // �� �����ΰ��
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
if (A[i] > A[i + 1]) { // �̻� �߰�
if (flag == 0) {
flag = 1;
cnt = 0;
if (i == 0) { // ù° ������ ���
cnt++; // ù������ �߶��� ��
if (A[i] <= A[i + 2]) { // �ι�° ������ �߶��� ��
cnt++;
}
else if (cnt == 0) {
return 0;
}
}
else if (i == N-2) { // ������ �ٷ� �� ������ ���
if (A[i - 1] <= A[i + 1]) { // ������ �� ������ �ڸ��� ���
cnt++;
}
cnt++; // ������ ������ �ڸ��� ���
}
else { // �߰��� ���
if (A[i - 1] <= A[i + 1]) { // ù������ �ƴ� ���
cnt++;
}
else {
return 0;
}
}

}
else if (flag == 1) { // �̻��� �ι� �̻� �߰ߵǴ� ���
return 0;
}
}
}

if (cnt == 0) { // �� �����ΰ��
return N;
}
else {
return cnt;
}

}

*/