#include <bits/stdc++.h>

using namespace std;

long long n, q, a[5000]; 

int main()
{
	cin >> n >> q;
	
	for (long long i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	for (long long i = 1; i <= q; i++)
	{
		long long op, x, y;
		cin >> op >> x >> y;
		
		if (op == 1)
			a[x] = y;
			
		if (op == 2)
		{				
			long long sum = 1, ans = -1;
			
			for (long long j = x; j <= y; j++)
			{
				if (a[j] < 0)
				{
					ans = max(sum, ans);
					sum = 1;
					continue;
				}
				sum *= a[j];
			}
			ans = max(sum, ans);
			
			if (sum > pow(2, 30))
				cout << "Too large\n";
			else
				cout << sum << "\n";
		}
	}
	
 	return 0;
}

