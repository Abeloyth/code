#include <bits/stdc++.h>

using namespace std;

vector <int> edge[1005];
int n, q, dad[1005];

void dfs(int x)
{
	static int vis[1005];
	vis[x] = 1;
	
	for (int p : edge[x])
	{
		if (!vis[p])
		{
			dad[p] = x;
			dfs(p);
		}
	}
}

int main()
{
	cin >> n >> q;
	for (int i = 1; i <= n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	
	dfs(1);
	while (q--)
	{
		int x, y, ans = 0;
		cin >> x >> y;
		
		while (y)
		{
			if (x == dad[y])
			{
				ans = 1;
				break;
			}
			y = dad[y];
		}
		cout << (ans ? "Yes\n" : "No\n");
	}
	
 	return 0;
}

