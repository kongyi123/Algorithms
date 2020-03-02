#include<vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
















// 1365. How Many Numbers Are Smaller Than the Current Number
/*
1. 원소끼리 크기비교
	- 위치 변경
	- 위치 고정
2. 배열에 그리기


*/





// 원소끼리 크기비교

// 위치 변경
class Solution { // my code. 정렬을 썼다.
public:
	int rank[110];
	int copy[501];

	vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
		vector<int> result(nums.size());
		for (int i = 0; i < 110; i++) rank[i] = -1;
		for (int i = 0; i < nums.size(); i++) copy[i] = nums[i];
		sort(copy, copy + nums.size());
		for (int i = 0; i < nums.size(); i++) {
			if (rank[copy[i]] == -1) rank[copy[i]] = i;
		}
		for (int i = 0; i < nums.size(); i++) result[i] = rank[nums[i]];


		return result;
	}
};



// 위치 고정
class Solution { // n^2 구현이 굉장히 쉽다. 고민이 필요없는 방법. n제한이 작기 때문에 이문제는 해회에서는 이게 제일 좋은 솔루션
public:
	vector<int> smallerNumbersThanCurrent(vector<int>& a) {
		int n = a.size();
		vector<int> ret;
		for (int i = 0; i < n; ++i)
		{
			int tmp = 0;
			for (int j = 0; j < n; ++j) if (i != j)
				tmp += a[j] < a[i];
			ret.push_back(tmp);
		}
		return ret;
	}
};




class Solution { // O(n) 솔루션인데, 원소의 범위까지 주어지기 때문에 가능 내가 정렬한것처럼 할 필요까지도 없다. 
	// - 배열에 그리는 방법 >> 해쉬맵까지 확장가능 (사실 배열에 그리는 방법 = 해쉬맵)
	// 근데 해쉬맵 stl을 안쓰면 음수는 불가. 쓰면 음수까지 가능하다는거.
public:
	vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
		vector<int> ans(nums.size());
		unordered_map<int, int> mp;

		for (int i = 0; i < nums.size(); i++)
			mp[nums[i]]++;

		for (int i = 0; i <= 100; i++) {
			mp[i] += mp[i - 1];
		}

		for (int i = 0; i < nums.size(); i++) {
			ans[i] = mp[nums[i] - 1];
		}
		return ans;
	}
};


class Solution { // 바로 위의 솔루션을 메모리 최적화 한 버전
public:
	vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
		vector<int> v1(101, 0);
		//step1
		for (int i : nums) v1[i]++;
		//step2
		for (int i = 1; i < 101; i++) v1[i] += v1[i - 1];
		//step3
		for (int i = 0; i < nums.size(); i++)
			if (nums[i] > 0)
				nums[i] = v1[nums[i] - 1];
		return nums;
	}
};


















// 1366. Rank Teams by Votes

// my code. stl 사용할 줄 몰라서 class를 사용한 mergesort 를 직접 구현함.
// 안좋은 방법인게, 얘는 통째로 다바꿔야 한다. 가중치를 다 바꿀 필요없이 가중치를 대표하는 주소(문자) 하나만 바꾸 면되는데..
// 두번재 방법과 비교해서 훨씬 안좋다.
class Node {
public:
	int arr[30] = { 0, };
	bool operator>(const Node t) {
		for (int i = 1; i < 30; i++) {
			if (arr[i] > t.arr[i]) return 1;
			else if (arr[i] < t.arr[i]) return 0;
		}
		return 1;
	}
};

Node buf[30];
void msort(Node rank[], int s, int e) {
	if (s < e) {
		int mid = (s + e) / 2;
		msort(rank, s, mid);
		msort(rank, mid + 1, e);

		int i = s, j = mid + 1, count = s;
		while (i <= mid && j <= e) {
			if (rank[i] > rank[j]) buf[count++] = rank[i++];
			else buf[count++] = rank[j++];
		}

		while (i <= mid) buf[count++] = rank[i++];
		while (j <= e) buf[count++] = rank[j++];

		for (int i = s; i <= e; i++) rank[i] = buf[i];
	}
	else return;
}

class Solution {
public:
	Node rank[30];
	string rankTeams(vector<string>& votes) {
		for (int i = 0; i < votes.size(); i++) {
			for (int j = 0; j < votes[i].size(); j++) {
				rank[votes[i][j] - 'A'].arr[0] = votes[i][j] - 'A' + 1;
				rank[votes[i][j] - 'A'].arr[j + 1] ++;
			}
		}
		msort(rank, 0, 27);

		string result;
		for (int i = 0; i < 30; i++) {
			if (rank[i].arr[0]) result += (rank[i].arr[0] + 'A' - 1);
		}

		cout << result;
		return result;
	}
};



class Solution { // map + stl
public:
	string rankTeams(vector<string>& votes) {
		int m = votes.size();
		string v = votes[0];
		map<char, map<int, int>> f;
		for (auto s : votes)
		{
			for (int i = 0; i < s.size(); ++i)
				f[s[i]][i] ++;
		}
		sort(v.begin(), v.end(), [&](char a, char b) -> bool				// v를 정렬하되, 그 정렬기준은 f[][]로 함.
			{
				for (int i = 0; i < v.size(); ++i)
				{
					if (f[a][i] > f[b][i]) return 1;
					if (f[a][i] < f[b][i]) return 0;
				}
				return a < b;
			});
		return v;
	}
};



// 1367. Linked List in Binary Tree

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /**
  * Definition for a binary tree node.
  * struct TreeNode {
  *     int val;
  *     TreeNode *left;
  *     TreeNode *right;
  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  * };
  */

  // ListNode
vector<int> to_vector(ListNode* head)
{
	vector<int> ret;
	for (auto it = head; it; it = it->next)
		ret.push_back(it->val);
	return ret;
}

class Solution {
public:
	vector<int> v;
	bool flag;

	void go(TreeNode* x, int k)
	{
		if (flag) return;
		if (k + 1 == v.size())
		{
			flag = 1;
			return;
		}
		if (x->left && x->left->val == v[k + 1])
			go(x->left, k + 1);
		if (x->right && x->right->val == v[k + 1])
			go(x->right, k + 1);
	}

	void dfs(TreeNode* x)
	{
		if (!x) return;
		if (flag) return;
		if (x->val == v[0])
		{
			go(x, 0);
		}
		dfs(x->left);
		dfs(x->right);
	}
	bool isSubPath(ListNode* head, TreeNode* root) {
		if (!head) return 1;
		v = to_vector(head);
		flag = 0;
		dfs(root);
		return flag;
	}
};




// 1368. Minimum Cost to Make at Least One Valid Path in a Grid

const int INF = 1000000000;

template<class weight_type>
struct weighted_directed_graph
{
	int n;
	vector<vector<pair<int, weight_type>>> v;

	weighted_directed_graph(int n = 0)
	{
		init(n);
	}
	void init(int n)
	{
		assert(n >= 0);
		this->n = n;
		v = vector<vector<pair<int, weight_type>>>(n + 1);
	}
	void addedge(int x, int y, weight_type z)
	{
		assert(1 <= x && x <= n);
		assert(1 <= y && y <= n);
		v[x].push_back({ y, z });
	}

	vector<weight_type> dis;
	weight_type shortest_path(int s, int t)
	{
		dis = vector<weight_type>(n + 1, INF);
		dis[s] = 0;
		priority_queue<pair<weight_type, int>, vector<pair<weight_type, int>>, greater<pair<weight_type, int>>> Q;
		Q.push({ 0, s });
		while (!Q.empty())
		{
			weight_type d;
			int x;
			tie(d, x) = Q.top();
			Q.pop();
			if (dis[x] != d) continue;
			for (auto e : v[x])
			{
				int y, z;
				tie(y, z) = e;
				if (dis[y] > d + z) Q.push({ dis[y] = d + z, y });
			}
		}
		return dis[t];
	}
};

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

class Solution {
public:
	int minCost(vector<vector<int>>& a) {
		int n = a.size(), m = a[0].size();
		int N = n * m;

		auto place = [&](int x, int y)
		{
			return x * m + y + 1;
		};

		weighted_directed_graph<int> G(N);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
			{
				for (int k = 0; k < 4; ++k)
				{
					int x = i + dx[k], y = j + dy[k];
					if (0 <= x && x < n && 0 <= y && y < m)
					{
						G.addedge(place(i, j), place(x, y), k + 1 != a[i][j]);
					}
				}
			}
		auto ret = G.shortest_path(place(0, 0), place(n - 1, m - 1));
		return ret;
	}
};

