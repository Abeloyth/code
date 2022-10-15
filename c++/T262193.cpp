#include<bits/stdc++.h>

using namespace std;

int tj[10];

int main()
{
	int m, n;
	cin >> m >> n;
	
	for (int i = m; i <= n; i++)
	{
		int num = i;
		while (num > 0)
		{
			tj[num % 10] ++;
			num /= 10;
		}
	}
	
	for (int i = 0; i <= 9; i++)
		cout << tj[i] << " ";
	
 	return 0;
}

