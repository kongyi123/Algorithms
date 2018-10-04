// 문자열 기수 정렬

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>

using namespace std;

int N;

int main(void) {
	char dat[100][21];
	char* arr[100];		// 문자열의 본체 말고 포인터로 갖다가 비교하고 정렬함
	queue<char*> radix[30]; // 자리수에 대한 큐 배열


	scanf("%d", &N);
	for (int i = 0;i < N;i++) {
		scanf("%s", &dat[i]);
		arr[i] = &dat[i][0];
	}

	int d = 20; 
	// 아랫자리부터
	for (int j = d;j >= 0;j --) {
		for (int i = 0; i < N; i++) {
			if (arr[i][j] < 'a' || arr[i][j] > 'z') radix[0].push(arr[i]);
			else radix[arr[i][j]-'a'+1].push(arr[i]);
			// 특정 자리의 숫자를 빼내서 그에 해당하는 위치에 데이터를 push
		}

		// 큐에 들어간 값들을 자리수 크기 순으로 다시 배열에 집어넣는다.
		int k = 0;
		for (int i = 0;i < 27;i++) {	
			while (radix[i].size() > 0) {
				arr[k++] = radix[i].front();
				radix[i].pop();
			}
		}
	}

	printf("\n");
	for (int i = 0; i < N; i++) printf("%s\n", arr[i]);

	return 0;
}