#include <bits/stdc++.h>

using namespace std;

int n, m;
bool xl[100000], b[100000];

int main()
{
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> xl[i];
	}
	
	for (int i = 1; i <= m; i++)
	{
		int set, l, r;
		cin >> set >> l >> r;
		
		if (set == 0)
		{
			for (int j = l + 1; j <= r + 1; j++)
				xl[j] = 0;
		}
		else if (set == 1)
		{
			for (int j = l + 1; j <= r + 1; j++)
				xl[j] = 1;
		}
		else if (set == 2)
		{
			for (int j = l + 1; j <= r + 1; j++)
				xl[j] = !xl[j];
		}
		else if (set == 3)
		{
			int cnt = 0;
			for (int j = l + 1; j <= r + 1; j++)
				cnt += (xl[j] == 1) ? 1 : 0;
			cout << cnt << "\n";
		}
		else if (set == 4)
		{
			int cnt = -1, cnt_ = 0;
			for (int j = l + 1; j <= r + 1; j++)
			{
				if (xl[j])
					cnt_ ++;
				else
					cnt = max(cnt_, cnt), cnt_ = 0;
			}
			cnt = max(cnt, cnt_);
			cout << cnt << "\n";
		}
	}
	
 	return 0;
}

