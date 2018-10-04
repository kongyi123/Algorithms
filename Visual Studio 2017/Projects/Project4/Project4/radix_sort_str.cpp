// ���ڿ� ��� ����

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>

using namespace std;

int N;

int main(void) {
	char dat[100][21];
	char* arr[100];		// ���ڿ��� ��ü ���� �����ͷ� ���ٰ� ���ϰ� ������
	queue<char*> radix[30]; // �ڸ����� ���� ť �迭


	scanf("%d", &N);
	for (int i = 0;i < N;i++) {
		scanf("%s", &dat[i]);
		arr[i] = &dat[i][0];
	}

	int d = 20; 
	// �Ʒ��ڸ�����
	for (int j = d;j >= 0;j --) {
		for (int i = 0; i < N; i++) {
			if (arr[i][j] < 'a' || arr[i][j] > 'z') radix[0].push(arr[i]);
			else radix[arr[i][j]-'a'+1].push(arr[i]);
			// Ư�� �ڸ��� ���ڸ� ������ �׿� �ش��ϴ� ��ġ�� �����͸� push
		}

		// ť�� �� ������ �ڸ��� ũ�� ������ �ٽ� �迭�� ����ִ´�.
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