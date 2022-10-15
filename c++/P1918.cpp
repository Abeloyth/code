#include<bits/stdc++.h>

using namespace std;

struct ball
{
	int g, w;
}a[1000005];

bool cmp(ball x, ball y)
{
	return x.g < y.g;
}

int main()
{
	int n, m;
	
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].g;
		a[i].w = i;
	}
	
	cin >> m;
	
	sort(a + 1, a + n + 1, cmp);
	
	for (int i = 1; i <= m; i++)
	{
		int gs;
		cin >> gs;
		
		int idxs = 1, idxe = n;
		bool flag = false;
		
		while (idxs <= idxe)
		{
			int tmp = (idxs + idxe) / 2;
			if (a[tmp].g > gs)
				idxe = tmp - 1;
			else if (a[tmp].g == gs)
			{
				cout << a[tmp].w << endl;
				flag = true;
				break;
			}
			else
				idxs = tmp + 1;
		}
		if (! flag)
			cout << 0 << endl;
	}
	
 	return 0;
}
