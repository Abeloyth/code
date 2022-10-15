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
		bin[x] = ans(bin[x]);
		return bin[x];
	}
	
	void uni(int x, int y)
	{
		bin[ans(x)] = ans(y);
	}
	
	void ask(int x, int y)
	{
		if (ans(x) == ans(y)) cout << "Y" << endl;
		else cout << "N" << endl;
	}
	
}u;

int main()
{
	int n, m, a, y, z;

	cin >> n >> m;

	while (m --)
	{
		cin >> z >> a >> y;
		if (z == 1)
			u.uni(a, y);
		else
			u.ask(a, y);
	}
	
 	return 0;
}
