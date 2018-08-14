#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <map>
#define MAX 2000000
#define M 1073741824

using namespace std;


int L;
char S[MAX+10];
map <long long, int> hashtable;

int eval(int length) {

	long long sum = 0;
	char tstr[MAX] = { 0, };
	long long t = 1;
	int k;
	for (int j = 1;j <= length;j++) {
		k = ((S[j] - 'a'+1) * t) % M;
		sum = (sum + k) % M;
		if (j == length) break;
		t = (t * 26) % M;
	}
	strncpy(tstr, &S[1], length);
	hashtable[sum] = 1;
	for (int i = length+1;i <= L;i++) {
		sum = sum - ((S[i - length] - 'a'+1));
		sum = sum / 26;


		sum = (sum + ((S[i] - 'a'+1) * t)) % M;
		

		if (hashtable[sum] != 0) {
			return 1;
		}
		else {
			hashtable[sum] = 1;
		}
	}

	return 0;
}

int process() {
	int max = 0;
	int s = 1, e = L;
	int flag = 0;
	while (s < e) {
		int mid = (s + e + 1) / 2;
		if (eval(mid) == 1) {
			s = mid;
			flag = 1;
		}
		else e = mid - 1;
	}
	
	if (flag == 0) return 0;
	return s;
}


int main(void) {
	int T;
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1;tc <= T;tc++) {
		scanf("%d", &L);
		scanf("%s", &S[1]);
		printf("#%d %d\n", tc, process());
	}
	return 0;
}