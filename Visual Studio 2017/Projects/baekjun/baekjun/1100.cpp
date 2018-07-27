#include <stdio.h>
#include <string>
#include <cstdio>
#include <cstring>

//vector<int> ds;
//	ds.push_back(i);
// for (int d : ds)

using namespace std;

int main(void) {
	int cnt = 0;
	for (int i = 1;i <= 8;i++) {
		char buf[10];
		fgets(buf, 10, stdin);
		for (int j = 0;j < 8;j++) {
			if ((i + j + 1) % 2 == 0) {
				if (buf[j] == 'F') cnt++;
			}
		}
	}

	fprintf(stdout, "%d", cnt);

	return 0;
}