#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

short n, d, index = 0, min_ans = 32767, abil[20][20], st[10], lt[10];

void makeTeam(short before, short depth);

int main() {
	std::cin >> n;
	d = n / 2;
	for (short i = 0; i < n; i++)
		for (short j = 0; j < n; j++)	std::cin >> abil[i][j];
	st[index++] = 0;
	makeTeam(0, 0);
	std::cout << min_ans << std::endl;
}

void makeTeam(short before, short depth) {
	short indS = 0, indL = 0, sumS = 0, sumL = 0, ans;

	if (min_ans > 0) {
		if (depth == d - 1) {
			for (short i = 0; i < n; i++) {
				if (st[indS] == i) indS++;
				else { lt[indL] = i; indL++; }
			}
			for (short i = 0; i < d; i++) {
				for (short j = i + 1; j < n / 2; j++) {
					sumS += (abil[st[i]][st[j]] + abil[st[j]][st[i]]);
					sumL += (abil[lt[i]][lt[j]] + abil[lt[j]][lt[i]]);
				}
			}
			ans = abs(sumS - sumL);
			if (min_ans > ans) min_ans = ans;
		}
		else {
			for (short i = before + 1; i < d + 2 + depth; i++) {
				st[index++] = i;
				makeTeam(i, depth + 1);
				index--;
			}
		}
	}
}