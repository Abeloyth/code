#include<bits/stdc++.h>

using namespace std;

int n, k, ans;

void dfs(int idx, int num, int sum)
{
	if (idx == k + 1)
	{
		if (sum == n)
			ans ++;
		return;
	}
	for (int i = num; i <= n; i++)
	{
		if (n >= i)
		{
			dfs(idx + 1, i, sum + 1);
		}
	}
}

int main()
{	
	cin >> n >> k;
	
	dfs(1, 1, 0);
	
	cout << ans;
	
	return 0;
}
