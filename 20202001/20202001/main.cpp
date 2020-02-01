// ���� ����

/*
[Score�� ��°��� �������� �� ���� ������ �޴´�]
main �ڵ带 �м��Ͽ� �� ���� ������ �޵��� solution.cpp�� �ڵ�.
stack �޸�: 1MB
main.cpp�� ������ �� ����.
solution.cpp�� ��������, static ���� ���Ұ�
solution.cpp�� �����Ҵ� ��� ����
solution.cpp�� ���� �ڵ帮�並 ö���ϰ� ������ ���Դϴ�.
*/

#include<ctime>
#include<iostream>
#include<cstdlib>
using namespace std;
#define SIZE 1048576
#define MAX_COUNT 2048
//haha

extern void test(unsigned int data[SIZE]);
unsigned int mdata[SIZE];

int Score;
short buf[1024];

unsigned int bak_data[SIZE];
unsigned int num[MAX_COUNT];

void ssort(short data[1024], int len)
{
	if (len < 2)
		return;

	int mid = len / 2;

	ssort(data, mid);
	ssort(data + mid, len - mid);

	int i = 0, j = mid, count = 0;

	while (i < mid && j < len) {
		if (data[i] < data[j]) {
			buf[count++] = data[i++];
		}
		else {
			buf[count++] = data[j++];
		}
	}

	while (i < mid) {
		buf[count++] = data[i++];
	}

	while (j < len) {
		buf[count++] = data[j++];
	}

	for (int a = 0; a < len; ++a) {
		data[a] = buf[a];
	}
}

void test_sort(short data[1024])
{
	clock_t start = clock();
	ssort(data, 1024);
	Score -= clock() - start;
}
int TC = 1;

int main()
{
	srand(time(0));
	while (TC--) {
		cout << TC << endl;
		for (register int i = 0; i < MAX_COUNT; ++i) {
			num[i] = (rand() * 1007) % 65536;
		}

		for (register int i = 0; i < SIZE; ++i) {
			int idx1 = rand() % MAX_COUNT;
			int idx2 = rand() % MAX_COUNT;

			bak_data[i] = mdata[i] = (num[idx1] << 16) + num[idx2];
		}

		clock_t start = clock();
		test(mdata);
		Score += clock() - start;

		for (register int i = 0; i < SIZE - 1; ++i) {
			if (mdata[i] < mdata[i + 1]) {
				Score = 1000000000;
			}
		}

		for (register int i = 0; i < 10; ++i) {
			int idx = rand() % SIZE;

			bool check = false;
			for (register int j = 0; j < SIZE; ++j) {
				if (mdata[j] == bak_data[idx]) {
					check = true;
					break;
				}
			}
			if (!check) {
				Score = 1000000000;
			}
		}
	}
	std::cout << Score * 1000 / CLOCKS_PER_SEC << "\n";

	return 0;
}