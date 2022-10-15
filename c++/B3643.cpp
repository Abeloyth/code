#include <bits/stdc++.h>

using namespace std;

vector <int> edge[1005];
int w[1005][1005], n, m;

int main()
{
	cin >> n >> m;
	
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		
		w[u][v] = 1;
		w[v][u] = 1;
		
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << w[i][j] << " ";
		}
		cout << endl;
	}
	
	for (int i = 1; i <= n; i++)
	{
		sort(edge[i].begin(), edge[i].end());
		
		cout << edge[i].size() << " ";
		
		for (int &w_ : edge[i])
			cout << w_ << " ";
		
		cout << "\n";
	}
	
 	return 0;
}

