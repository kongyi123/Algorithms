#include <iostream> 
using namespace std; 

class dynamic { 

public: 
	int *arr; 
	dynamic(int size); // ������ 
	~dynamic(); // �Ҹ��� 
}; 

dynamic::dynamic(int size) { 
	arr=new int [size]; //�޸� ���� �Ҵ� 
} 

dynamic::~dynamic() { 
	delete[] arr; // arr ���� �Ҵ� �޸� ���� arr=NULL; 
				  // ���� ���� ���� NULL ���� 

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
	// dynamic q=p; <-- �䷸�� �ϸ� ������ �����. 
	// ������ : delete[] arr�� �ι� ȣ���ϸ鼭 �̹� ������ 
	// arr�� �ٽ� �ѹ� �����ϸ鼭 ����� ������. 
	// �ذ��� : �Ʒ��� ���� �ҽ��ڵ带 ���� 
	return 0; 
}
