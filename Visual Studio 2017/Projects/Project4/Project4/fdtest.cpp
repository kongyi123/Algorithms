// ���� �Ǳ� ���� new�� �ȵȴ�.

#include <cstdio>

using namespace std;

struct DATE {
	int a, b;
	DATE() {}
};

template <typename T>
struct B;
struct A;

struct A {
	int k;
};


template <typename T>
struct B {
	A* a;
};




int main(void) {
	B<DATE*>* k1[100];
	for (int i = 0;i < 100;i++) {
		k1[i] = new B<DATE*>();
	}
	return 0;
}





