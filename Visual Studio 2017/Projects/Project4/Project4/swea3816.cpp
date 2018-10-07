// 23
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char s1[100001];
char s2[100001];

int s1_count[26];
int s2_count[26];

int process() {
	int er;
	int cnt = 0;
	int len_s1 = strlen(s1);
	int len_s2 = strlen(s2);
	if (len_s2 < len_s1) return 0;

	for (int i = 0;i < len_s1;i++) 
		s1_count[s1[i] - 'a'] ++;
	
	for (int i = 0;i < len_s2;i++) {
		if (i < len_s1) {
			s2_count[s2[i] - 'a'] ++;
		}
		else {
			s2_count[s2[i] - 'a'] ++;
			s2_count[s2[i - len_s1] - 'a'] --;
		}

		er = 0;
		for (int j = 0;j < 26;j++) {
			if (s1_count[j] != s2_count[j]) {
				er = 1;
				break;
			}
		}

		if (er == 0) cnt++;
	}

	return cnt;
}

void init() {
	for (int i = 0;i < 26;i++)
		s1_count[i] = s2_count[i] = 0;
}

int main(void) {
	int T;
	scanf("%d", &T);
	for (int tc = 1;tc <= T;tc++) {
		init();
		scanf("%s %s", s1, s2);
		printf("#%d %d\n", tc, process());
	}
	return 0;
}