#include<bits/stdc++.h>

using namespace std;

int a[100005], b[100005];

int main()
{
	int n, m;
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= m; i++)
		cin >> b[i];
	
	sort(b + 1, b + 1 + m);
	
	for (int i = 1; i <= n; i++)
	{
		int idxs = 1, idxe = m;
		while (idxs <= idxe)
		{
			int tmp = (idxs + idxe) / 2;
			if (b[tmp] > a[i])
				idxe = tmp - 1;
			else if (b[tmp] == a[i])
			{
				cout << a[i] << " ";
				break;
			}
			else
				idxs = tmp + 1;
		}
	}
	
 	return 0;
}

