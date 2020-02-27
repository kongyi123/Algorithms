#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <ctime>

using namespace std;

FILE* in = fopen("typing.txt", "r");

int n;
vector<char*> list;

int main(void) {
	srand(time(0));
	fscanf(in, "%d ", &n);
	char str[1000];
	for (int i = 1; i <= n; i++) {
		fgets(str, 1000, in);
		char* mem = new char[strlen(str)];
		strcpy(mem, str);
		list.push_back(mem);
	}

	while (1) {
		int target = rand() % n;
		time_t t1 = clock();
		printf("%s", list[target]);
		
		char input[1000];
		fgets(input, 1000, stdin);
		if (strcmp(input, "exit\n") == 0) break;
		if (strcmp(input, "clear\n") == 0) system("cls");
		time_t t2 = clock();
		printf("time diff per letter = %lld\n", (t2 - t1)/strlen(input));
	}

	
	return 0;
}