#include <bits/stdc++.h>

using namespace std;

int n, q, dad[1005];

int main()
{
	cin >> n >> q;
	for (int i = 1; i <= n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		
		dad[u] = v;
	}
	
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

