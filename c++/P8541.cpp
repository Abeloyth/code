#include <bits/stdc++.h>

using namespace std;

int T;
map <long long, int> p;

int get_val(long long x)
{
	if (p.find(x) != p.end())
		return p[x];
	
	cout << "? " << x << "\n";
	fflush(stdout); 
	
	int v;
	
	cin >> v;
	
	p[x] = v;
	
	if (v == -1)
		exit(0);
		
	return v;
}

long long get(long long x, long long k)
{
	long long st = get_val(x);
	
	if (get_val(x + 1) != st)
		return x;
	long long begin = 0;
	
	while (1ll << (begin + 1) <= k)
		begin ++;
	
	while (1)
	{
		if (get_val(x + k + (1ll << begin)) != st)
			break;
		k += 1ll << begin;
		begin ++;
	}
	for (int i = begin - 1; i >= 0; i--)
	{
		if (get_val(x + k + (1ll << i)) == st)
			k += (1ll << i);
	}
	
	return x + k;
}

int main()
{
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		p.clear();
		long long int1, int2, L;
		int1 = get(0, 1);
		int2 = get(int1 + 1, max(int1 - 1, 1ll));
		L = int2 - int1;
		
		if (get_val(0) == 0)
		{
			cout << "! " << (L - 1) * (L - 1) - 1 - int1 << "\n";
			fflush(stdout);
		}
		else
		{
			cout << "! " << L * L + L - int1 << "\n";
			fflush(stdout);
		}
	} 
	
 	return 0;
}

