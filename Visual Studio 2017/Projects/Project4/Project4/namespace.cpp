#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

namespace kong {
	void run() {
		printf("kong ");
	}
}

namespace namul {
	void run() {
		printf("namul ");
	}
}
/*
int main(void) {
	kong::run();		// kong�� run()�Լ� ȣ��
	namul::run();		// namul�� run()�Լ� ȣ��
	return 0;
}
*/

using namespace kong;



namespace std {
	using::printf;
	using::scanf;
}

int main(void) {
	run();
	namul::run();
	std::run();
	return 0;
}
