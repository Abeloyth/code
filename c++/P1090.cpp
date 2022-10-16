#include <bits/stdc++.h>
#include <queue>

using namespace std;

priority_queue <int, vector <int>, greater <int> > h;
int n, ans;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		h.push(a);
	}
	
	while (h.size() > 1)
	{
		int x = h.top();
		h.pop();
		int y = h.top();
		h.pop();
		h.push(x + y);
		ans += x + y;
	}
	
	cout << ans;
	
 	return 0;
}
