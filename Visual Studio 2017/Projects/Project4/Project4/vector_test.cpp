#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int process() {
	vector<int> v[10];
	int a[1000];
	v[0].push_back(1);
	v[3].push_back(1);
	return 0;
}

int main(void) {
	vector<int> v[10];
	v[0].push_back(1);
	v[3].push_back(1);
	v[3].push_back(1);
	v[3].push_back(1);
	v[5].push_back(1);

	(v+3)->clear();			// clear �Լ��� ���� ���� ������ �ʱ�ȭ �Ǵ� ���� �ǹ���. 
	// v[3].clear();�� ���� �ǹ�.
	// �迭�� �ʱ�ȭ �ϱ� ���ؼ��� for������ ��ȸ�ؾ���.
	

	queue<int> q[10];
	q[0].push(1);
	q[3].push(1);
	q[3].push(1);
	q[3].push(1);
	q[5].push(1);
	
	int b = q[3].front();
	while (!q[3].empty()) q[3].pop(); // �ʱ�ȭ �Լ��� ���� ��� �� pop�ϴ� ���·� �ؾ���
	// front�� �� back�� �� �̰�
	// push�� back�ڿ� ���Ұ� ���Եǰ�, pop�� front�� ���Ұ� �����ȴ�.
	process();
	process();
	vector<int> *vv;
	vv = new vector<int>[100]; // �޸� ������ �Ϸ� ���� ������ ������ �� �� �ִ�. (Ȯ���Ѱ� �ƴ�... ����)

	return 0; // ���ÿ� ���� ������ ó�� ������ ���� �ڵ����� �ʱ�ȭ�� �� ���·� ���������.
}
