#include<bits/stdc++.h>

using namespace std;

struct unionFind
{
	int bin[100005];
	
	unionFind()
	{
		for (int i = 1; i <= 100002; i++)
			bin[i] = i;
	}
	
	int ans(int x)
	{
		if (bin[x] == x) return x;
		return ans(bin[x]);
	}
	
	void uni(int x, int y)
	{
		bin[ans(x)] = ans(y);
	}
	
	void ask(int x, int y)
	{
		if (ans(x) == ans(y)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	
}u;

int main()
{
	int n, m, p, x, y;

	cin >> n >> m >> p;

	while (m --)
	{
		cin >> x >> y;
		u.uni(x, y);
	}
	
	while (p --)
	{
		cin >> x >> y;
		u.ask(x, y);
	}
	
 	return 0;
}
