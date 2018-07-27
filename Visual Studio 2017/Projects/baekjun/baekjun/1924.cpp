#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int cnt[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };


int main(void) {
	int n, m;
	int t = 0;
	fscanf(stdin, "%d%d", &n, &m);

	for (int i = 1;i < n;i++) {
		t += cnt[i];
	}
	t += m;

	char str[5];
	if (t % 7 == 0) strcpy(str, "SUN");
	if (t % 7 == 1) strcpy(str, "MON");
	if (t % 7 == 2) strcpy(str, "TUE");
	if (t % 7 == 3) strcpy(str, "WED");
	if (t % 7 == 4) strcpy(str, "THU");
	if (t % 7 == 5) strcpy(str, "FRI");
	if (t % 7 == 6) strcpy(str, "SAT");
	fprintf(stdout, "%s", str);
	return 0;
}