#include <bits/stdc++.h>

using namespace std;

int n, m, a; 

int main()
{
	cin >> n >> m >> a;
	
	long long ans = ceil(n / (double) a) * ceil(m / (double) a);
	
	cout << ans;
	
 	return 0;
}

