#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#define SIZE 1048576
#define HASH 65536
#define ruint register unsigned int
#define rint register int
#define uint unsigned int

#define UPPER 0xFFFF0000
#define LOWER 0x0000FFFF

using namespace std;

extern void test_sort(short data[1024]);
bool check[65536];
short temp[SIZE];
int origin[SIZE];
int tcnt;

void test(unsigned int data[SIZE])
{
	// 카운팅 소트를 하기 위해 종류별로 오름차순 정렬.... 그냥 정렬하는게 빠르겠다. 어차피 2048개밖에 안되는데..
	for (int i = 0; i < SIZE; i++) {
		int val = (UPPER & data[i]) >> 16;
		if (!check[val]) {
			check[val] = true;
			temp[tcnt] = (short)val;
			origin[tcnt++] = val;
		}
	}

	for (int i = tcnt; i < 2048; i++) temp[i] = 32767;
	
	test_sort(temp);
	test_sort(&temp[1024]);

	int temp2[2048], t2cnt = 0;
	int p = 0, q = 1024;
	while (p < 1024 && q < tcnt) {
		if (temp[p] > temp[q]) temp2[t2cnt++] = temp[q++];
		else temp2[t2cnt++] = temp[p++];
		
	}
	while (p < 1024) temp2[t2cnt++] = temp[p++];
	while (q < tcnt) temp2[t2cnt++] = temp[q++];
	int start = 0;
	for (int i = 0; i < tcnt; i++) {
		if (temp2[i] < 0) {
			start++;
			temp2[i] += 65536;
		}
	}

	int aa[2048],acnt = 0;
	for (int i = start; i < tcnt; i++) 
		aa[acnt++] = temp2[i];
	for (int i = 0; i < start; i++)
		aa[acnt++] = temp2[i];

	//aa에 있음.
	
	
	printf("tcnt = %d\n", tcnt);


}

