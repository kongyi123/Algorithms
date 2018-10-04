//SWEA 5658 보물상자 비밀번호
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
	char temp = v.at(0);//젤 마지막놈
	v2.push_back(temp);
	v.clear();
	for (int i = 0; i < n; i++) {
		v.push_back(v2.at(i));
	}

}
void cal() {
	int cut = n / 4;//한면에 올라가는 수의 개수
	int count = 0;
	double temp = 0;
	for (count = 0; count < (n / cut); count++) {//4번
		temp = 0;
		for (int k = 0; k < cut; k++) {//3개씩 * 4번 = 12개
			int mok = count;
			int namuji = k;
			int chartoint = 0;
			int index = cut * count + k;
			int val = v.at(index);
			if (v.at(index) >= 'A') {//문자 아스키코드
				chartoint = val - 55;
			}
			else {//숫자
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
	}//4개 나와야 한다
}

bool cmp(const int n1, const int n2) {//큰순 정렬
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
		cal();//0회전
		int cut = n / 4;//각 면당 몇개 원소이냐
		for (int i = 1; i < cut; i++) {// 1 2 3회전
			shift();
			cal();//1회전 ~ n/4회전
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