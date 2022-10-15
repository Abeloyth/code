#include <bits/stdc++.h>

using namespace std;

int a[500005], b[500005], n, ans1 = 0, ans2 = 1;

int main()
{
	cin >> n;
	
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	for (int i = 1; i <= n; i++)
		cin >> b[i];
		
	for (int i = 1; i <= n; i++)
	{
		if (a[i] != b[i])
			ans1 ++;
	}
	
	for (int i = n; i >= 1; i--)
	{
		if (a[n - i + 1] != b[i])
			ans2 ++;
	}
	
	cout << min(ans1, ans2);

 	return 0;
}

