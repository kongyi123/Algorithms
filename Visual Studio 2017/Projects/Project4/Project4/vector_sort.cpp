#include <iostream>
//#include <functional> // �������� ������ ���� lib
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(vector<int> a, vector<int> b) { 
	return a.at(1) < b.at(1); 
}

int main(void) {
	int arr[5];
	arr[0] = 0;
	arr[1] = 4;
	arr[2] = 3;
	arr[3] = 1;
	arr[4] = 5;

//	sort(arr, arr + 5, greater<int>()); // , greater<int>() ���ڸ� �ϳ� �� ���̸� ��������.

	vector<vector<int>> container;
		
	for (int i = 0;i < 10;i++) {
		container.push_back(vector<int>());
		container[i].push_back(rand() % 10);
		container[i].push_back(rand() % 10);
	}

	for (int i = 0; i < 10; i++)
		cout << container[i][0] << ' ' << container[i][1] << endl;

	cout << endl << "sorting" << endl << endl;

	sort(container.begin(), container.end(), cmp);

	for (int i = 0; i < 10; i++)
		cout << container[i][0] << ' ' <<  container[i][1] << endl;

	
	vector<vector<int>>::iterator a, b;
	a = lower_bound(container.begin(), container.end(), vector<int>(1));
	b = container.begin();

	// cout << lower_bound(container.begin(), container.end(), vector<int>(1));    // <- �̰� �������� �ƿ� �ȵ�. iterator type���� ���ִ� ���¸� ������� ��.
	
	cout << a - b;
	cout << lower_bound(container.begin(), container.end(), vector<int>(1)) - b;
	cout << lower_bound(container.begin(), container.end(), vector<int>(1)) - container.begin(); 

	// ���� ���� ������ ���°� ������.
	return 0;
}
