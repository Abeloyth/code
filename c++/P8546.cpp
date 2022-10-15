#include <bits/stdc++.h>

using namespace std;

int n, Map[101][101], ans = 0;

bool check(int m, int x, int y)
{
	int y1 = y, y2 = y;
	
	for (int i = x; i <= x + m - 1; i++)
	{
		if (Map[i][y1] == 0) return 0;
		y1++;
	}
	
	for (int i = x + m - 1; i >= x; i--)
	{
		if (Map[i][y2] == 0) return 0;
		y2++;
	}
	return 1;
}

int main()
{
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		string a;
		cin >> a; 
		for (int j = 1; j <= n; j++)
		{
			Map[i][j] = a[j - 1] - '0';
		}
	}
	
	for (int i = 2; i <= n; i++)
	{
		for (int x = 1; x <= n - i + 1; x++)
		{
			for (int y = 1; y <= n - i + 1; y++)
			{
				if (check(i, x, y)) ans++;
			}
		}
	}
	
	cout << ans;
	
 	return 0;
}

