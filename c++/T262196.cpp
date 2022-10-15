#include<bits/stdc++.h>

using namespace std;

int a[10005], b;

int main()
{
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	int x;
	cin >> x;
	
	b = x;
	
	int tmp = x, cnt = 0;
	
	for (int i = 1; i <= n; i++)
	{
		if ((cnt != 0 && a[tmp] == a[x]) || cnt != 0 && a[tmp] == b)
		{
			cout << a[tmp] << " ";
 			return 0;
		}
		tmp = a[tmp];
		cnt ++;
	}
}

