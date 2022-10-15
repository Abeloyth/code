#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n, k;
	
	cin >> k;
	
	for (double Sn = 0; Sn <= k; n++, Sn += 1.0 / n);
	
	cout << n;
	
 	return 0;
}

