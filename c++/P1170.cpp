#include<bits/stdc++.h>

using namespace std;

long long gcd(long long x, long long y)
{
	if (y == 0)
		return x;
	return gcd(y, x % y);
}

int main()
{
	long long n, rabbit_x, rabbit_y, man_x, man_y;
	
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> man_x >> man_y;
		cin >> rabbit_x >> rabbit_y;
		if (gcd(abs(man_x - rabbit_x), abs(man_y - rabbit_y)) == 1)
			cout << "no" << endl;
		else
			cout << "yes" << endl;
	}
	
 	return 0;
}
