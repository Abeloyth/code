#include <bits/stdc++.h>

using namespace std;

struct ticket
{
	int traffic, price, t;
};

ticket tkt[100005];
int n, ans; 

int main()
{
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> tkt[i].traffic >> tkt[i].price >> tkt[i].t;
	}
	
	for (int i = 1; i <= n; i++)
	{
		if (tkt[i].traffic == 0)
		{
			ans += tkt[i].price;
		}
		else
		{
			/*
			int flag = 1;
			for (int j = 1; j < i; j++)
			{
				if (tkt[j].traffic == 0 && tkt[i].t - tkt[j].t <= 45 && tkt[j].price >= tkt[i].price)
				{
					flag = 0;
					tkt[j].traffic = -1;
					break;
				}
			}
			
			if (flag == 1)
			{
				ans += tkt[i].price;
			}
			*/
			int idx = -1;
			
			for (int j = i - 1; j >= 1 && tkt[i].t - tkt[j].t <= 45; j--)
			{
				if (tkt[j].traffic == 0 && tkt[j].price >= tkt[i].price)
				{
					idx = j;
				}
			}
			
			if (idx != -1)
			{
				tkt[idx].traffic = -1; 
			}
			else
			{
				ans += tkt[i].price;
			}
		}
	}
	
	cout << ans;
	
 	return 0;
}

