//SWEA 5658 �������� ��й�ȣ
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
using namespace std;
int n, k;
vector<char> v;
vector<int> result;

void init() {
	v.clear();
	result.clear();
	n = 0; k = 0;
}
void shift() {
	vector<char> v2;
	for (int i = 1; i < n; i++) {
		v2.push_back(v.at(i));
	}
	char temp = v.at(0);//�� ��������
	v2.push_back(temp);
	v.clear();
	for (int i = 0; i < n; i++) {
		v.push_back(v2.at(i));
	}

}
void cal() {
	int cut = n / 4;//�Ѹ鿡 �ö󰡴� ���� ����
	int count = 0;
	double temp = 0;
	for (count = 0; count < (n / cut); count++) {//4��
		temp = 0;
		for (int k = 0; k < cut; k++) {//3���� * 4�� = 12��
			int mok = count;
			int namuji = k;
			int chartoint = 0;
			int index = cut * count + k;
			int val = v.at(index);
			if (v.at(index) >= 'A') {//���� �ƽ�Ű�ڵ�
				chartoint = val - 55;
			}
			else {//����
				chartoint = val - '0';
			}
			temp += pow(16, cut - 1 - namuji) * chartoint;
		}

		int flag = true;
		int rsize = result.size();
		for (int i = 0; i < rsize; i++) {
			if (temp == result.at(i)) flag = false;
		}
		if (flag) result.push_back(temp);
	}//4�� ���;� �Ѵ�
}

bool cmp(const int n1, const int n2) {//ū�� ����
	return n1 > n2 ? true : false;
}

int main() {
	int tt;
	cin >> tt;
	for (int tc = 1; tc <= tt; tc++) {
		init();
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			char c;
			cin >> c;
			v.push_back(c);
		}
		cal();//0ȸ��
		int cut = n / 4;//�� ��� � �����̳�
		for (int i = 1; i < cut; i++) {// 1 2 3ȸ��
			shift();
			cal();//1ȸ�� ~ n/4ȸ��
		}
		sort(result.begin(), result.end(), cmp);
		
		int cnt = 0, ans;
		for (int i = 0;i < result.size();i++) {
			if (i > 0 && result[i] == result[i - 1] ) continue;
			cnt++;
			if (cnt == k) ans = result[i];
		}
		//for (int i = 0; i < result.size(); i++) cout << result.at(i) << " ";
		//cout << endl;
		cout << "#" << tc << " " << result[k-1] << endl;
	}
	return 0;
}