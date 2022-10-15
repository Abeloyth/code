#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
ll inf = 100000005;
int n, m, Map[1005][1005], down[1005][1005], up[1005][1005], dp[1005][1005]; 

int main()
{
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> Map[i][j];
		}
	}
	
	for (int i = 1; i <= m; i++)
	{
		down[0][i] = up[n + 1][i] = -inf;
	}
	
	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = -inf;
	}
	
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			down[j][i] = max(down[j - 1][i], dp[j][i - 1]) + Map[j][i];
		}
		for (int j = n; j >= 1; j--)
		{
			up[j][i] = max(up[j + 1][i], dp[j][i - 1]) + Map[j][i];
		}
		for (int j = 1; j <= n; j++)
		{
			dp[j][i] = max(down[j][i], up[j][i]);
		}
	}
	
	cout << dp[n][m];
	
 	return 0;
}

