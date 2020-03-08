

/*
codeingerman
class Solution {
public:
	int numOfMinutes(int n, int head, vector<int>& manager, vector<int>& informTime) {
		vector < vector< int > > adj(n+1);
		for( int i = 0; i< n; i++){
			int u = manager[i];
			if( u != -1){
				adj[u].push_back(i);
				adj[i].push_back(u);
			}
		}

		queue < int > stk;
		stk.push(head);
		vector< bool > vis( n+1, false);
		vector< int > time(n+1, 0);
		time[head] = 0;
		while(!stk.empty()){
			int x = stk.front();
			stk.pop();
			vis[x] = true;
			for( auto y: adj[x]){
				if(vis[y] == false){
					stk.push(y);
					time[y] = time[x] + informTime[x];
				}
			}
		}
		return *max_element(time.begin(), time.end());
	}
};





Anarchy

class Solution {
public:
	vector < bool > vis;
	vector < int > dist, tm;
	vector<vector<int>> G;

	void dfs(int u, int passed) {
		vis[u] = 1;
		dist[u] = passed;
		for (int v : G[u]) {
			if (vis[v] == 1) continue;
			dfs(v, passed + tm[u]);
		}
	}

	int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
		vis.resize(n);
		dist.resize(n);
		G.resize(n);
		tm = informTime;
		for (int i = 0; i < manager.size(); i++) {
			if (manager[i] != -1) G[manager[i]].push_back(i);
		}
		dfs(headID, 0);
		int maxx = 0;
		for (int i = 0; i < n; i++) maxx = max(maxx, dist[i]);
		return maxx;
	}
};


Yulian_Yarema

class Solution {
public:

	int ans;
	vector<int> g[100005];
	vector<int> val;

	void dfs(int u,int s=0,int p=-1)
	{
		ans=max(ans,s);
		for(int i=0;i<g[u].size();i++)
			if(g[u][i]!=p)
			{
				dfs(g[u][i],s+val[u],u);
			}
	}

	int numOfMinutes(int n, int headID, vector<int>& p, vector<int>& informTime) {
		int s=1;
		ans=0;
		val=informTime;
		for(int i=0;i<n;i++)
		{
			if(p[i]==-1)
			{
				s=i;
			}
			else
			{
				g[p[i]].push_back(i);
				g[i].push_back(p[i]);
			}
		}
		dfs(s);
		return ans;
	}
};

*/

#include <vector>

using namespace std;

class Solution {
public:
	int  sum = 0;
	vector<vector<int>> list;

	void back(int cur, const vector<int>& informTime) {
		for (int i = 0; i < list.size(); i++) {
			sum += informTime[cur];
			back(list[cur][i], informTime);
		}
	}

	int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
		for (int i = 1; i <= n; i++) {
			vector<int> a;
			list.push_back(a);
		}
		
		for (int i = 0; i < n; i++) {
			if (manager[i] == -1) continue;
			list[manager[i]].push_back(i);
		}

		back(headID, informTime);
		return sum;
	}
};

int main(void) {
	return 0;
}