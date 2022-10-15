#include <bits/stdc++.h>

using namespace std;

long long cnt[200005][2], s, res, ans = 99999999999999;
int w[200005], v[200005], l[200005], r[200005], n, m, L, R;

int main()
{
	cin >> n >> m >> s;
	
	L = 0;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i] >> v[i];
		R = max(R, w[i]);
	}
	
	for (int i = 1; i <= m; i++)
	{
		cin >> l[i] >> r[i];
	}
	
	R += 1;
	while (L < R)
	{
		res = 0;
		int mid = (L + R) / 2;
		for (int i = 1; i <= n; i++)
		{
			if (w[i] >= mid)
			{
				cnt[i][0] = cnt[i - 1][0] + 1;
				cnt[i][1] = cnt[i - 1][1] + v[i];
			}
			else
			{
				cnt[i][0] = cnt[i - 1][0];
				cnt[i][1] = cnt[i - 1][1];
			}
		}
		for (int i = 1; i <= m; i++)
		{
			res += (cnt[r[i]][0] - cnt[l[i] - 1][0]) * (cnt[r[i]][1] - cnt[l[i] - 1][1]);
		}
		ans = min(ans, abs(res - s));
		
		if (res < s)
			R = mid;
		else
			L = mid + 1;
	}

	cout << ans;
	
 	return 0;
}

