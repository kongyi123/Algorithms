// 1365. How Many Numbers Are Smaller Than the Current Number

class Solution {
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



// 1366. Rank Teams by Votes

class Solution {
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
		sort(v.begin(), v.end(), [&](char a, char b) -> bool
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

