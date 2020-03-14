#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n;

int main(void) {
	char str[20] = { 0, }, copy[20] = { 0, }, max[20] = { 0, };
	scanf("%d", &n);
	if (n == 1) {
		printf("a");
		return 0;
	}

	for (int i = 0; i < n; i++) {
		str[i] = 'a';
	}
	
	//for (int i = 1; i < n; i++) {
		while (1) {
			printf("%s\n", str);
			if (str[n - 1] == 'a' + n - 1) break;

			max[0] = str[0];
			for (int j = 1; j < n; j++) {
				if (max[j - 1] > str[j]) max[j] = max[j - 1];
				else max[j] = str[j];
			}

			str[n-1] ++;
			int t = n-1;
			for (int j = 0; j < n; j++)
				copy[j] = str[j];

			while (str[t] == max[t-1]+2) {
				str[t] = 'a';
				str[t - 1] ++;
				t = t - 1;
			}

/*			if (str[i - 1] == i + 'a') {
				for (int j = 0; j < n; j++)
					str[j] = copy[j];
				break;
			}
			
			*/
		} 
//	}


	return 0;
}