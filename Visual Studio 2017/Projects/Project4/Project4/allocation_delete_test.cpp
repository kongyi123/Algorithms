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

	v = new node[100]; // ����� ���� �Ҹ��ڰ� �ִ� Ŭ������ �迭�� ���� �����ʹ� (���� �����ڰ� ����ִټ� ġ����) �ּ� delete�� ������ ����. 
	delete []v;			// �̷��� �ؾ� ������ ���� �ʴ´�. �迭�� ���� ������ ������ Ȯ���� ��������� �Ѵ�.


	return 0;
}