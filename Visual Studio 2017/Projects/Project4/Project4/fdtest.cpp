#include <cstdio>

using namespace std;
template <typename T>
struct B;

template <typename T>
struct A {
	B *b;
	int k;
};

template <typename T>
struct B {
	A* a;
};

int main(void) {
	
	return 0;
}

