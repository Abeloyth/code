#include <bits/stdc++.h>

using namespace std;

int k, n, a[7000005];

int main()
{
	cin >> n >> k;
	
	double cur = 0;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		cur += a[i];
	}
		
	cur /= n;
	double S = 0;
	
	for (int i = 1; i <= n; ++i)
		S += 1.0 * (cur - a[i]) * (cur - a[i]);
		
	S /= n;
	
	if (abs(S) <= 1e-10)
	{
		cout << "No answer!\n";
		exit(0);
	}
	
	long long x = floor(sqrt(k / S)), y = ceil(sqrt(k / S));
	
	if (!x)
	{
		cout << y << "\n";
		exit(0);
	}
	
	if (abs(S * x * x - k) <= abs(S * y * y - k))
		cout << x << "\n";
		
	else
		cout << y << "\n";
	
 	return 0;
}

