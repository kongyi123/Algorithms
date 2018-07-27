// 다이나믹도 좋지만 개수를 세는 것이라면 사람이 셈하기 쉬운 성질의 것부터 셈하고.
// 이미 셈한 것들을 아예 생각을 안해도 되는 상태의 단계별로 반복해서 진행할 수 있도록 한다.

// 즉, 1의자리 숫자를 셈하고,  1의 자리를 전부 삭제 한다고 가정
// 남은 자리 숫자에서의 1의자리를 셈하고, 또 상태에서의 1의 자리를 전부 삭제
// 반복
// 출력

// 가장 높은 자리수를 세는것이 더 안헷갈릴지. 가장 낮은 자리수를 세는 것이 더 안헷갈릴지
// 혹은 재귀적 처리가 가능한지 (동적계획법이 가능한지) 확인을 한다.

// => 규칙성이 보이는것은 아무래도 재귀적인 방법이나 동적 계획법이 가능한 것으로 보인다.


// * 특이사항 :	백준저지에 프로그램을 제출할 때는 나눗셈 수식을 최소한으로 하는게 좋다. 
//				t 에 10을 곱한 채로 수식에 /t, (t/10) 을 이용하여 계산하였더니 틀렸다고 나와서
//				t 에 10을 곱하지 않은 채로 수식에 /(t*10), t 를 이용하여 계산하였더니 맞았다고 나옴.

// (풀이) 전체 판이 한 눈에 보이도록 필요한 부분 남기면서 적절히 생략하여 남겨놓고...
// 규칙성을 시각적으로 찾아내어 수식화 하였음.

// (다른 풀이) 동적 계획법....... 짜볼것

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 12
#define INPUT stdin
#define OUTPUT stdout


//FILE *in = fopen("input.txt", "r");
//FILE *out = fopen("output.txt", "w");

int n, cnt[MAX], p[MAX];

int main(void) {
	fscanf(INPUT, "%d", &n);

	int head, tail;
	int t = 1;
	head = n;

	for (int i = 1;t <= n;i++) {
		tail = (head % 10);
		head = n / (t * 10);
		p[i] = tail;

		for (int k = 0;head > 0 && k <= 9;k++)		cnt[k] = cnt[k] + head*t;
		for (int k = 0;k <= (tail - 1);k++)			cnt[k] = cnt[k] + t;

		int t2 = 1;
		for (int j = 1;j <= (i - 1);j++) {
			cnt[tail] = cnt[tail] + (t2*p[j]);
			t2 = t2 * 10;
		}


		cnt[tail] ++;
		cnt[0] = cnt[0] - t;
		t = t * 10;
	}


	for (int i = 0;i <= 9;i++) {
		fprintf(OUTPUT, "%d ", cnt[i]);
	}

	return 0;
}