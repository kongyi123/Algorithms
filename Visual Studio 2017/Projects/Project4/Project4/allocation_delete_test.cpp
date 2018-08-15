#define _CRT_SECURE_NO_WARINGS
#include <vector>

using namespace std;

struct node2 {
	int aaaa;
	node2() {

	}

	~node2() {}
};

struct node {
	int aa, b;

	node() {
		node2 * cc;
		cc = new node2();
		delete cc;
	}
	~node() {}

	void hey() {

	}
};



int process() {
	node *ptr = new node();
	delete ptr;

//	v[5].push_back(1);

	return 0;
}

int main(void) {
	node* v2;
	v2 = new node();
	delete v2;

	node* v;

	v = new node[100]; // 사용자 정의 소멸자가 있는 클래스를 배열로 갖는 포인터는 (설사 생성자가 비어있다손 치더라도) 주소 delete시 에러가 난다. 
	delete []v;			// 이렇게 해야 에러가 나지 않는다. 배열과 단일 변수의 삭제는 확실히 구분해줘야 한다.


	return 0;
}