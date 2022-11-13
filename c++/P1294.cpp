#include <bits/stdc++.h>

using namespace std;

int n, m, Map[55][55], b[55], ans = -1, anss = -1, sum = 0;


int dfs(int now, int sum, int node)
{
	ans = max(ans, sum);
	
	for (int i = 1; i <= n; i++)
	{
		if (Map[now][i] != 0 && b[i] == 0)
		{
			//cout << "Map:" << Map[i][j] << " Now:" << now << " ";
			b[i] = 1;
			dfs(i, sum + Map[now][i], node + 1);
			b[i] = 0;
		}
	}	
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int s, e, w;
		cin >> s >> e >> w;
		Map[s][e] = w;
		Map[e][s] = w;
	}
	
	for (int i = 1; i <= n; i++)
	{
		b[i] = 1;
		dfs(i, 0, 1);
		anss = max(ans, anss);
		b[i] = 0;
	}
	
	cout << anss;
}
