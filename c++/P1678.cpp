#include<bits/stdc++.h>

using namespace std;

int a[100005];
int n, q;

int search(int x)
{
	int l = 1, r = n;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (a[mid] < x)
		{
			l = mid + 1;
		}
		else if (a[mid] >= x)
		{
			r = mid - 1;
		}
	}
	if (a[l] == x)
		return x;
	return a[l - 1];
}

int main()
{
	cin >> n >> q;
	
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	sort(a + 1, a + n + 1);
	
	for (int i = 1; i <= q; i++)
	{
		int x, q = 0;
		cin >> x;
		
	    cout << search(x) << endl;
	}
	
 	return 0;
}
