#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <ctime>
#include <cstdlib>

using namespace std;

FILE *out = fopen("output.txt", "w");

int main() {
	srand((unsigned int)time(NULL));
	int N = 5;
	fprintf(out, "1\n%d\n", N);
	for (int i = 1;i <= N;i ++) {
		for (int j = 1;j <= N-i;j++) {
			fprintf(out, "%d", rand() % 2);
		}
		fprintf(out, "\n");
	}
	return 0;
}