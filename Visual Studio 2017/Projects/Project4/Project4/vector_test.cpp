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

	(v+3)->clear();			// clear 함수는 벡터 단일 변수만 초기화 되는 것을 의미함. 
	// v[3].clear();과 같은 의미.
	// 배열을 초기화 하기 위해서는 for문으로 순회해야함.
	

	queue<int> q[10];
	q[0].push(1);
	q[3].push(1);
	q[3].push(1);
	q[3].push(1);
	q[5].push(1);
	
	int b = q[3].front();
	while (!q[3].empty()) q[3].pop(); // 초기화 함수가 따로 없어서 다 pop하는 형태로 해야함
	// front가 앞 back이 뒤 이고
	// push시 back뒤에 원소가 삽입되고, pop시 front서 원소가 삭제된다.
	process();
	process();
	vector<int> *vv;
	vv = new vector<int>[100]; // 메모리 해제가 완료 되지 않으면 에러가 날 수 있다. (확실한건 아님... 참고)

	return 0; // 스택에 벡터 변수를 처음 선언할 때는 자동으로 초기화가 된 상태로 만들어진다.
}
