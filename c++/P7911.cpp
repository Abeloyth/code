#include <bits/stdc++.h>

using namespace std;

int n;

bool Check(string s)
{
	int a, b, c, d, port;
	if (sscanf(s.c_str(), "%d.%d.%d.%d:%d", &a, &b, &c, &d, &port) != 5)  return false;
	if (a < 0 || a > 255 || b < 0 || b > 255 || c < 0 || c > 255 || d < 0 || d > 255 || port < 0 || port > 65535)  return false;
	stringstream ss;
	ss << a << '.' << b << '.' << c << '.' << d << ':' << port;
	return (ss.str() == s);
}

map <string, int> mp;

string op, ad;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> op >> ad;
		if (!Check(ad))
		{
			cout << "ERR\n";
			continue;
		}
		if (op[0] == 'S')
		{
			if (mp[ad])
				cout << "FAIL\n";
			else
			{
				mp[ad] = i;
				cout << "OK\n";
			}
		}
		else
		{
			if (!mp.count(ad))
				cout << "FAIL\n";
			else
				cout << mp[ad] << '\n';
		}
	}
	
	return 0;
}
