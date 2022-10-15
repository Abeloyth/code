#include<bits/stdc++.h>

using namespace std;

int a[15];

int main()
{
	for (int i = 1; i <= 10; i++)
	{
		cin >> a[i];
	}
	
	int h, cnt = 0;
	cin >> h;
	
	for (int i = 1; i <= 10; i++)
	{
		if (h + 30 >= a[i])
		{
			cnt ++;
		}
	}
	
	cout << cnt;
	
 	return 0;
}

