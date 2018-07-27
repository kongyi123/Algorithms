#include <string>
#include <conio.h>

using namespace std;

int ca[30][30];
int cb[30][30];

string makelower(string temp) {
	for (int j = 0;j < temp.size();j++) {
		if (temp.at(j) >= 'A' && temp.at(j) <= 'Z') {
			temp.at(j) += ('a' - 'A');
		}
	}
	return temp;
}

int min(int a, int b) {
	if (a > b) return b;
	return a;
}

int max(int a, int b) {
	if (a > b) return a;
	return b;
}

int solution(string str1, string str2) {
	int answer = 0;
	str1 = makelower(str1);
	str2 = makelower(str2);

	for (int i = 0;i < str1.size() - 1;i++) { 
		if (str1.at(i) >= 'a' && str1.at(i) <= 'z') {
			if (str1.at(i+1) >= 'a' && str1.at(i+1) <= 'z') {
				ca[str1.at(i) - 'a'][str1.at(i+1) - 'a'] ++;
			}
		}
	}

	for (int i = 0;i < str2.size() - 1;i++) {
		if (str2.at(i) >= 'a' && str2.at(i) <= 'z') {
			if (str2.at(i + 1) >= 'a' && str2.at(i + 1) <= 'z') {
				cb[str2.at(i) - 'a'][str2.at(i + 1) - 'a'] ++;
			}
		}
	}

	int bm, bj;
	bm = bj = 0;

	// 교집합을 찾는 경우
	for (int i = 0;i <= 29;i++) {
		for (int j = 0;j <= 29;j++) {
			bj += min(ca[i][j], cb[i][j]);
		}
	}

	// 합집합
	for (int i = 0;i <= 29;i++) {
		for (int j = 0;j <= 29;j++) {
			bm += max(ca[i][j], cb[i][j]);
		}
	}

	if (bm == 0) answer = 65536;
	else answer = (bj * 65536 / bm) ;

	return answer;
}

int main(void) {
	fprintf(stdout, "%d", solution("E=M*C^2", "e=m*c^2"));
	_getch();
}