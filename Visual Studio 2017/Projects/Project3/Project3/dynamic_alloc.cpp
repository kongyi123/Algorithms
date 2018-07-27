#include <iostream> 
using namespace std; 

class dynamic { 

public: 
	int *arr; 
	dynamic(int size); // 생성자 
	~dynamic(); // 소멸자 
}; 

dynamic::dynamic(int size) { 
	arr=new int [size]; //메모리 동적 할당 
} 

dynamic::~dynamic() { 
	delete[] arr; // arr 동적 할당 메모리 해제 arr=NULL; 
				  // 에러 방지 위해 NULL 삽입 

} 

int main() { 
	int usize; 
	cin >> usize; 
	dynamic arr1(usize); 
	for(int i=0; i<usize; i++) { 
		arr1.arr[i]=i+1; 
	} 
	
	for(int i=0; i<usize; i++) 
		cout << arr1.arr[i] << endl; 
	// dynamic q=p; <-- 요렇게 하면 에러가 생긴다. 
	// 문제점 : delete[] arr을 두번 호출하면서 이미 해제된 
	// arr을 다시 한번 해제하면서 생기는 에러다. 
	// 해결점 : 아래와 같이 소스코드를 수정 
	return 0; 
}
