// 15분
// 문자열 비교시 string 변수를 쓰는게 크게 메리트는 없는 것 같은데 이러한 방법이 있다는 것만 알아두면 될 것.

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;


//char data[21000][65];
/*
int compare(char *a, char *b) {
	int lena = strlen(a);
	int lenb = strlen(b);
	if (lena == lenb) {
		for (int i = 0;i < lena;i++) {
			if (a[i] > b[i]) return 1;
			else if(a[i] < b[i]) return -1;
		}

		return 0;
	}
	return lena - lenb;

}*/

int compare(string a, string b) {
	if (a.size() != b.size()) return a.size() - b.size();
	else if (a > b) return 1;
	else if (a < b) return -1;
	return 0;
}
/*
void swap(char* a, char* b) {
	char c[65] = { 0, };
	for (int i = 0;i < 65;i++) {
		c[i] = a[i];
		a[i] = b[i];
		b[i] = c[i];
	}
}
*/

void swap(string &a, string &b) {
	string t = a;
	a = b;
	b = t;
}

int main(void) {
	int n;
	char buf[10];
	string data[21000];

	fscanf(stdin, "%d", &n);
	for (int i = 1;i <= n;i++) {
		fgets(buf, 10, stdin);
	//	fscanf(stdin, "%s", &data[i]);
	//	getline(cin, data[i]);
		cin >> data[i];
		for (int j = i;j > 1;j = j / 2) {
			if (compare(data[j], data[j / 2]) > 0) swap(data[j], data[j / 2]);
		}
	}

	for (int i = 1;i <= n;i++) {
		swap(data[1], data[n - i + 1]);
		for (int j = 1;;) {
			int k = j * 2;
			if (k > n - i) break;
			if (k + 1 <= n - i && compare(data[k], data[k + 1]) < 0) k++;
			if (compare(data[j], data[k]) < 0) {
				swap(data[j], data[k]);
				j = k;
			}
			else break;
		}
	}

	for (int i = 1;i <= n;i++) {
		if (compare(data[i], data[i - 1]) == 0) continue;
		cout << data[i] << endl;
		//fprintf(stdout, "%s\n", data[i]);
	}

	return 0;
}