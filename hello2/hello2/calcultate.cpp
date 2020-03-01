#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int cnt[2049];

int main(void) {
	srand(time(0));
	for (int i = 0; i < 1048576; i++) {
		int val = rand() % 2048 + 1;
		cnt[val] ++;
	}
	
	sort(cnt, cnt + 2048);

	int sum = 0;
	for (int i = 0; i < 2048; i++) {
		sum += cnt[i];
		if (sum > 1048576-104) {
			printf("%d", cnt[i]);
			break;
		}
	}

	return 0;
}