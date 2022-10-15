#include <bits/stdc++.h>

using namespace std;

struct Edge
{
	int to_, cost;
};

vector <Edge> edge[100005];
int n, m;

int main()
{
	cin >> n >> m;
	
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		
		edge[u].push_back((Edge) {v, 1});
		edge[v].push_back((Edge) {u, 1});
	}
	
	for (int i = 1; i <= n; i++)
	{
		cout << edge[i].size() << "\n";
	}
	
 	return 0;
}

