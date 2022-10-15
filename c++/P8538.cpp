#include <bits/stdc++.h>
#define sum_ sum += (a[i] == 1) ? 1 : 0;
#define ans_ ans = max(ans, sum);

using namespace std;

int n, a[100005], l = 0, r = 0;

int main()
{
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == 2)
		{
			l = i;
			break;
		}
	}
	
	for (int i = n; i >= 1; i--)
	{
		if (a[i] == 3)
		{
			r = i;
			break; 
		}
	}
	
	int ans = 0;
	
	if (l != 0)
	{
		int sum = 1;
		for (int i = l + 1; i <= n; i++)
		{
			sum_
		}
		ans_
	}
	
	if (r != 0)
	{
		int sum = 1;
		for (int i = 1; i <= r - 1; i++)
		{
			sum_
		}
		ans_
	}
	
	if (r != 0 && l != 0 && r > l)
	{
		int sum = 2;
		for (int i = l + 1; i <= r - 1; i++)
		{
			sum_
		}
		ans_
	}
	
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum_
	}
	ans_
	
	cout << ans;

 	return 0;
}

