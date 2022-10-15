#include <bits/stdc++.h>
#include <limits.h>

using namespace std;

struct flower
{
	int cost, fr, be;
}fwr[505];

int n, q, c, f, ans[505];

int main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
		cin >> fwr[i].cost >> fwr[i].fr >> fwr[i].be;
	
	for (int _ = 1; _ <= q; _++)
	{
		cin >> c >> f;
	    for (int i = 1; i <= c; i++)
	    	for (int j = f; j >= fwr[i].cost; j--)
	        	ans[j] = max(ans[j], ans[j - fwr[i].cost] + fwr[i].be);
	    	cout << ans[f];
	}
    
    return 0;
}

