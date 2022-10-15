#include <bits/stdc++.h>

using namespace std;

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
	}
	
	for (int i = 1; i <= n; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= n; j++)
			if (w[i][j] == 1) cnt++;
		cout << cnt << "\n";
	}
	
 	return 0;
}

