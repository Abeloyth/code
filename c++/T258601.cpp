#include <bits/stdc++.h>

using namespace std;

struct Edge
{
	int to, cost;
	Edge (int _to, int _cost) : to(_to), cost(_cost) {}
};

vector <Edge> edge[100005];
int n, m;

int main()
{
	cin >> n >> m;
	
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		
		edge[u].push_back(Edge(v, w));
	}
	
	for (int i = 1; i <= n; i++)
	{
		int cnt = 0;
		for (auto &w : edge[i])
			cnt += w.cost;
		cout << cnt << "\n"; 
	}
	
 	return 0;
}
