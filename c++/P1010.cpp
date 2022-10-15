#include <bits/stdc++.h>

using namespace std;

void power(int n)
{
	for (int i = 15; i >= 0; i--)
	{
		int x = pow(2, i);
		if (x <= n)
		{
			if (i == 1)
			{
				cout << "2";
			}
			else if (i == 0)
			{
				cout << "2(0)";
			}
			else
			{
				cout << "2(";
				power(i);
				cout << ")";
			}
			
			n -= pow(2, i);
			if (n != 0)
				cout << "+";
		}
	}
} 

int main()
{
	int n;
	cin >> n;
	
	power(n);

 	return 0;
}
