#include<bits/stdc++.h>

using namespace std;

int a[1000000];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	
	for (int i = 1; i <= m; i++)
	{
		int q;
		scanf("%d", &q);
		
		int l = 1, r = n, mid, flag = 0;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (a[mid] >= q)
				r = mid - 1;
			else
			{
				l = mid + 1;
			}
		}
		if (a[l] == q)
			cout << l << " ";
		else
			cout << -1 << " ";
	}
	
 	return 0;
}

