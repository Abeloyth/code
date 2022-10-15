#include <bits/stdc++.h>

using namespace std;

long long n, Q, RS[8005];

struct id
{
	int num, v;
	
	bool operator >(const id b) const
	{
		if (v != b.v)
			return v > b.v;
		else
			return num > b.num;
	}
	
	bool operator <(const id b) const
	{
		if (v != b.v)
			return v < b.v;
		else
			return num < b.num;
	}
}a[8005];

void get_num()
{
	for(int i = 1; i <= n; i++)
	{
        RS[a[i].num] = i;
    }
}

void numer_for_1(int x, int v)
{
	a[RS[x]].v = v;
	
    for(int i = RS[x]; i < n; i++)
	{
        if(a[i] > a[i + 1])
		{
            swap(a[i], a[i + 1]);
        }
    }
    
    for(int i = RS[x]; i > 1; i--)
	{
        if(a[i] < a[i - 1])
		{
            swap(a[i], a[i - 1]);
        }
    }
    get_num();
}

bool cmp(id x, id y)
{
	if (x.v == y.v)
		return x.num < y.num;
		
	return x.v < y.v;
}

int main()
{
	cin >> n >> Q;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].v;
		a[i].num = i;
	}
	
	sort(a + 1, a + n + 1, cmp);
	get_num();
	
	for (int i = 1; i <= Q; i++)
	{
		int op;
		
		cin >> op;
		
		if (op == 1)
		{
			int x, v;
			cin >> x >> v;
			
			numer_for_1(x, v);
		}
		else if (op == 2)
		{
			int x;
			cin >> x;
			
			cout << RS[x] << "\n";
		}
	}
	
 	return 0;
}

