#include<bits/stdc++.h>

using namespace std;

int d[500005];
int l, n, m;

int check(int num)
{
	int cnt = 0, end = 0;
	for (int i = 1; i <= n; i++)
	{
		if (d[i] - end < num)
			cnt ++;
		else
			end = d[i];
	}
	if (l - end < num)
		cnt ++;
	
	return cnt;
}

int main()
{
	cin >> l >> n >> m;
	
	for (int i = 1; i <= n; i++)
		cin >> d[i];
	
	sort(d + 1, d + n + 1);
	
	int left = 0, right = l, mid;
	
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (check(mid) > m)
			right = mid - 1;

		else
			left = mid + 1;
	}
	
	cout << right;
	
	return 0;
}
