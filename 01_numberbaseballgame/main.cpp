#include <stdio.h>
#include <stdlib.h>
#include <time.h>
unsigned char KEY[200];
int m = 0;
extern void test(unsigned char key[200]);
int check(unsigned char key[200]) {
	int pos = 0;
	int equal = 0;
	m++;
	for (register int c = 0; c < 200; ++c)
		if (key[c] == KEY[c]) pos++;

	for (register int i = 0; i < 200; ++i)
		for (register int j = 0; j < 200; ++j)
			if (key[i] == KEY[j]) equal++;
	return pos * 256 + equal;
}
int main() {
	int i;
	int seed = 3;
	int RESULT = 0;
	int T = 50;
	clock_t start;
	srand(seed);
	start = clock();
	for (int c = 0; c < T; ++c) {
		unsigned char pool[255] = { 0, };
		for (int k = 0; k < 200; k++) {
			i = rand() % 255;
			while (pool[i] == 1) i = rand() % 255;
			KEY[k] = i + 1;
			pool[i] = 1;
		}

		unsigned char key[200] = { 0, };
		test(key);
		for (int k = 0; k < 200; k++) {
			if (KEY[k] != key[k]) RESULT += 10000;
		}
	}
	RESULT += ((int)clock() - start) / 1000;
	printf("m = %d\n", m / T);
	printf("RESULT = %d", RESULT);
		
	return 0;

}