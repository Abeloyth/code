/*
#include<bits/stdc++.h>

using namespace std;

int a[100005];
int n, m;

int check()
{
	int cnt = n, end = 0, max_ = 0, tmp, ttmp;
	for (int i = 1; i <= m; i++)
	{
		ttmp = 0;
		int temp = (cnt / m) + ((cnt % m != 0) ? 1 : 0);
		tmp += temp;
		cnt -= temp;
		for (int i = 1; i <= temp; i++)
		{
			ttmp += a[tmp - i + 1];
		}
		max_ = max(max_, ttmp);
	}
	
	return max_;
}

int main()
{
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	int min_ = 999999;
	
	for (int i = 1; i <= n; i++)
	{
		min_ = min(min_, check());
	}
	cout << min_;
	
	
	return 0;
}
*/

#include<bits/stdc++.h>

using namespace std;

int a[100005];
int n, m;

int check(int num)
{
	int cnt = 0, sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += a[i];
		if (sum > num)
		{
			cnt ++;
			sum = a[i];
		}
	}
	
	return cnt;
}

int main()
{
	cin >> n >> m;
	
	int min_ = 0, max_ = 0;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		min_ = max(min_, a[i]);
		max_ += a[i];
	}
	
	int l = min_, r = max_, mid;
	
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (check(mid) <= m)
			r = mid - 1;
		else
			l = mid + 1;
	}
	
	cout << l;
	
	return 0;
}
