#include <bits/stdc++.h>

using namespace std;

/*
struct Edge
{
	int to_, cost;
};
*/

//vector <Edge> edge[100005];
vector < pair<int, int> > edge[100005];
int n, m;

int main()
{
	cin >> n >> m;
	
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		
		edge[u].push_back(make_pair(v, w));
		edge[v].push_back(make_pair(u, w));
	}
	
	for (int i = 1; i <= n; i++)
	{
		int ans = 0;
		for (auto &w : edge[i])
			ans += w.second;
		
		cout << ans << "\n";
	}
	
 	return 0;
}

