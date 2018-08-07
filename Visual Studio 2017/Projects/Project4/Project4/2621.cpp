#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	char ch[10];
	int n[10];
	int ncnt[10] = { 0, }; // 같은 숫자 개수
	int ccnt[30] = { 0, }; // 같은 색의 개수
	int scnt[10] = { 0, }; // 연속된 숫자 확인용
	int max = 0;
	char buff;
	for (int i = 1;i <= 5;i++) {
		scanf("%c %d", &ch[i], &n[i]);
		scanf("%c", &buff);
		ccnt[ch[i]-'A'] ++;
		ncnt[n[i]] ++;
		if (max < n[i]) max = n[i];
	}

	int same5col;
	int suc5num;
	int same4num;
	int same3num, same2num;
	int num1, num2;
	
	same5col = suc5num = same4num = same3num = same2num = 0;
	for (int i = 1;i <= 29;i++) {
		if (ccnt[i] == 5) {
			same5col = 1;
			break;
		}
	}

	for (int i = 1;i <= 9;i++) {
		if (ncnt[i] != 0) {
			scnt[i] = scnt[i - 1] + 1;
			if (scnt[i] == 5) {
				suc5num = 1;
				num1 = i;
				break;
			}
		}
	}

	
	for (int i = 1;i <= 9;i++) {
		if (ncnt[i] == 4) {
			same4num = 1;
			num1 = i;
			break;
		}
	}

	for (int i = 1;i <= 9;i++) {
		if (ncnt[i] == 3) {
			same3num = 1;
			num1 = i;
			break;
		}
	}

	for (int i = 1;i <= 9;i++) {
		if (ncnt[i] == 2) {
			same2num++;
			if (same2num == 1) num2 = i;
			else num1 = i;
		}
	}

	int dap = 0;
	if (same5col && suc5num) {
		if (dap < max + 900) dap = max + 900;
	}
	
	else if (same4num) {
		if (dap < num1 + 800) dap = num1 + 800;
	}
	
	else if (same3num && same2num == 1) {
		if (dap < 10 * num1 + num2 + 700) dap = 10 * num1 + num2 + 700;
	}

	else if (same5col) {
		if (dap < max + 600) dap = max + 600;
	}

	else  if (suc5num) {
		if (dap < max + 500) dap = max + 500;
	}

	else if (same3num) {
		if (dap < num1 + 400) dap = num1 + 400;
	}

	else if (same2num == 2) {
		int t;
		if (num2 > num1) t = num2 * 10 + num1 + 300;
		else t = num1 * 10 + num2 + 300;
		if (dap < t) dap = t;
	}

	else if (same2num == 1) {
		if (dap < num2 + 200) dap = num2 + 200;
	}

	
	if (dap == 0) dap = max + 100;
	

	printf("%d", dap);


	return 0;
}