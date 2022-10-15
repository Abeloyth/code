#include <bits/stdc++.h>

using namespace std;

int price[105][105], dp[105][10005];

int main()
{
	int t, n, m;
	cin >> t >> n >> m;
	
	for (int i = 1; i <= t; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> price[i][j];
		}
	}
	
	// 25pts
	/*
	if (t == 1)
	{
		cout << m;
	}
	else if (t == 2)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				dp[i][j] = dp[i - 1][j];
				if (j >= price[1][i])
				{
					dp[i][j] = max(dp[i][j], dp[i][j - price[1][i]] + price[2][i] - price[1][i]);
				}
			}
		}
		
		cout << m + dp[n][m];
	}
	*/
	
	for (int i = 1; i < t; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= m; k++)
			{
				dp[j][k] = dp[j - 1][k];
				
				if (k >= price[i][j])
				{
					dp[j][k] = max(dp[j][k], dp[j][k - price[i][j]] + price[i + 1][j] - price[i][j]);
				}
			}
		}
		m += dp[n][m];
	}
	
	cout << m;
	
 	return 0;
}

