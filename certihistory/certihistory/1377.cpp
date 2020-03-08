/*
codeingerman


class Solution {
public:
	double ans[105];
	int check[105];
	bool vis[105];
	bool notleaf[105];
	vector<int>adj[105];

	void dfs(int u, int par, int cnt){
		vis[u]=1;
		check[u]=cnt;
		int div = adj[u].size();
		if(par!=-1) div--;
		for(auto v : adj[u]){
			if(v!=par){
				notleaf[u]=1;
				ans[v]=ans[u]/div;
				dfs(v,u,cnt+1);
			}
		}
	}

	double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
		for(auto p : edges){
			adj[p[0]].push_back(p[1]);
			adj[p[1]].push_back(p[0]);
		}
		ans[1]=1;
		dfs(1,-1,0);

		if(check[target]==t || (!notleaf[target] && check[target]<=t))
			return ans[target];
		else
			return 0;

	}
};


Anarchy

class Solution {
public:
	vector < bool > vis;
	vector < double > prob;
	vector < int > dist, isleaf;
	vector<vector<int>> G;

	void dfs(int u, int d, double p, bool r) {
		int ch = G[u].size();
		if (!r) ch--;
		vis[u] = 1;
		prob[u] = p;
		dist[u] = d;
		if (ch == 0) isleaf[u] = 1;

//        cout<<u<<" "<<d<<" "<<p<<" "<<r<<endl;

		for (int v : G[u]) {
			if (vis[v] == 1) continue;
			dfs(v, d+1, p/(double)ch, 0);
		}
	}

	double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
		vis.resize(n+1);
		prob.resize(n+1);
		dist.resize(n+1);
		isleaf.resize(n+1);
		G.resize(n+1);
		for (auto e : edges) {
			G[e[0]].push_back(e[1]);
			G[e[1]].push_back(e[0]);
		}
		dfs(1, 0, 1, 1);

		if (t < dist[target]) return 0;
		if (t == dist[target]) return prob[target];
		if (t > dist[target] && isleaf[target]) return prob[target];
		return 0;
	}
};

Yulian_Yarema

class Solution {
public:

	vector<int> g[105];

	double prob[105];
	bool in[105];
	int p[105];

	double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {

		for(vector<int> p : edges)
		{
			g[p[0]].push_back(p[1]);
			g[p[1]].push_back(p[0]);
		}
		for(int i=0;i<105;i++)
		{
			p[i]=-1;
			prob[i]=0;
		}
		prob[1]=1;
		in[1]=1;

		while(t--)
		{
			int nin[105];
			double nprob[105];
			for(int i=1;i<=n;i++)
			{
				nin[i]=0;
				nprob[i]=0;
			}
			for(int i=1;i<=n;i++)
			{
				if(in[i])
				{
					double sz;
					if(p[i]==-1)
						sz=g[i].size();
					else
						sz=(int)g[i].size()-1;
					if(sz)
					{
						for(int j=0;j<g[i].size();j++)
						{
							if(g[i][j]==p[i]) continue;
							int to=g[i][j];
							p[to]=i;
							nin[to]=1;
							nprob[to]=prob[i]/sz;
						}
						nprob[i]=0;
					}
					else
					{
						nin[i]=1;
						nprob[i]=prob[i];
					}
				}
			}
			for(int i=1;i<=n;i++)
			{
				prob[i]=nprob[i];
				in[i]=nin[i];
			}
		}
		return prob[target];


	}
};

*/


// ¹Ì¿Ï¼º

class Solution {
public:
	void back(int cur, double* val, vector<vector<int>>& list, int* step) {
		double aa;
		vector<pair<int, int>> queue;
		int head = 0, tail = 1;
		val[cur] = 1;
		queue.push_back(pair<int, int>(cur, 0));
		while (head < tail) {
			cout << val[1] << ' ' << val[2] << '\n';
			cout << cur;

			int cur = queue[head].first;
			int curs = queue[head].second;
			int cnt = 0;
			for (int i = 0; i < list[cur].size(); i++) {
				int next = list[cur][i];
				if (step[next] == 0 || step[next] == curs + 1) {
					step[next] = curs + 1;
					cnt++;
				}
			}



			for (int i = 0; i < list[cur].size(); i++) {
				aa = 1 / (double)cnt;

				int next = list[cur][i];
				cout << "next = " << next << '\n';

				if (step[next] == 0) {
					step[next] = curs + 1;
					queue[tail++] = pair<int, int>(next, curs + 1);
					val[next] += (aa * val[cur]);
				}
				else if (step[next] == curs + 1) {
					val[next] += (aa * val[cur]);
					//qeueu[tail++] = pair<int, int>(next,curs+1);
				}
			}
			cout << "tail = " << tail << '\n';

			head++;
		}

	}
	double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
		int* step = new int[n + 1];
		double* val = new double[n + 1];
		for (int i = 1; i <= n; i++) {
			val[i] = 0; step[i] = 0;
		}
		vector<vector<int>> list;
		for (int i = 0; i <= n; i++) {
			vector<int> a;
			list.push_back(a);
		}

		for (int i = 0; i < edges.size(); i++) {
			int a = edges[i][0];
			int b = edges[i][1];
			list[a].push_back(b);
			list[b].push_back(a);
		}

		back(t, val, edges, step);
		return val[target];
	}
};