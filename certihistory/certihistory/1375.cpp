

/*
codeingerman

class Solution {
public:
	string generateTheString(int n) {
		if( n %2 == 0){
			string s = "";
			for(int i = 1; i<= n-1; i++)
				s +='f';
			s+='u';
			return s;
		}
		if( n %2 == 1){
			string s = "";
			for(int i = 1; i<= n-2; i++)
				s +='f';
			s+='u';
			if( n == 1)
				return s;
			s += 'k';
			return s;
		}
		return "";
	}
};	


Anarchy

class Solution {
public:
	int numTimesAllBlue(vector<int>& light) {
		int maxx = 0, cnt = 0;
		for (int i = 0; i < light.size(); i++) {
			maxx = max(maxx, light[i]);
			if (maxx == i+1) cnt++;
		}
		return cnt;
	}
};




Yulian_Yarema

class Solution {
public:
	int numTimesAllBlue(vector<int>& light) {
		int t[100005];
		memset(t,0,sizeof(t));
		t[0]=1;
		int pos=0;
		int cnt=0;
		int ans=0;
		for(int i=0;i<light.size();i++)
		{
			int x=light[i];
			if(t[x]==1) continue;
			t[x]=2;
			cnt++;
			while(t[pos+1]==2)
			{
				cnt--;
				t[pos+1]=1;
				pos++;
			}
			if(cnt==0)
				ans++;
		}
		return ans;
	}
};




*/

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:

	int numTimesAllBlue(vector<int>& light) {
		int cnt = 0;
		int max = 0;
		for (int i = 0; i < light.size(); i++) {
			int val = light[i];
			if (max < val) max = val;
			if (max == i + 1) cnt++;
		}

		return cnt;
	}
};

int main(void) {
	Solution sol;
	vector<int> str;
	str.push_back(1);
	str.push_back(2);
	str.push_back(3);
	str.push_back(4);
	str.push_back(5);
	str.push_back(6);

	int cnt = sol.numTimesAllBlue(str);
	printf("%d\n", cnt);

	return 0;
}