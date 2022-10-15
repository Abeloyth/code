#include <bits/stdc++.h>

using namespace std;

struct item
{
	double v, c, f;
	item(double var_v = 0, double var_c = 0, double var_f = 0)
	{
		v = var_v;
		c = var_c;
		f = var_f;
	}
	
	bool operator< (const item& x) const
	{
		return f > x.f;
	}
};

int check(double x, int n, int m, item* a)
{
	for (int i = 1; i <= n; i++)
		a[i].f = a[i].v - a[i].c * x;
		
	sort(a + 1, a + n + 1);
	
	double cur = 0;
	
	for (int i = 1; i <= m; i++)
		cur += a[i].f;
		
	return cur >= 0;
}

int main()
{
	item t[200];
	int n, m;
	double T;
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> t[i].v;
	for (int i = 1; i <= n; i++)
		cin >> t[i].c;
		
	double l = 0, r = 1000.0;
	while (r - l > 1e-5)
	{
		double mid = (l + r) / 2;
		if (check(mid, n, m, t))
			l = mid;
		else
			r = mid;
	}
	cout << setiosflags(ios::fixed) << setprecision(3) << l << "\\\\\\\\\\\\";
			
 	return 0;
}

