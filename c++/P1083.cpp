#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

long long f[1000005], r[1000005], d[1000005], s[1000005], t[1000005], n, m;

int check(int x) 
{
	memset(f, 0, sizeof(f));
	for (int i = 1; i <= x; i++)
	{
		f[s[i]] += d[i];
		f[t[i] + 1] -= d[i];
	}
	
	long long cur = 0;
	
	for (int i = 1; i <= n; i++)
	{
		cur += f[i];
		if (cur > r[i])
			return 0;
	}
	
	return 1;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> r[i];
	for (int i = 1; i <= m; i++)
		cin >> d[i] >> s[i] >> t[i];
	
		
	pair<int, int> ans;
	
	int var_l = 1, var_r = m, cur;
	
	if (check(m))
	{
		ans = make_pair(0, 0);
		cout << ans.first;
		return 0;
	}
	
	while (var_l <= var_r)
	{
		int mid = (var_l + var_r) / 2;
		
		if (check(mid))
		{
			var_l = mid + 1;
		}
		else
		{
			var_r = mid - 1;
			cur = mid;
		}
	}
	
	ans = make_pair(-1, cur);
	
	cout << ans.first << "\n" << ans.second;
	
 	return 0;
}

