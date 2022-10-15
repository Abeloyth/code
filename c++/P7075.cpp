#include<bits/stdc++.h>

using namespace std;

const int X[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool feb(int y)
{
    if (y < 0)
		return y % 4 == -1;
    if (y <= 1582)
		return y % 4 == 0;
    if(y > 1582)
		return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
		
    return false;
}

void next_date(int &y, int &m, int &d)
{
    if(y == 1582 && m == 10 && d == 4)
        y = 1582, m = 10, d = 15;
        
	else if(d < X[m] + (m == 2 && feb(y)))
        d++;
	else
	{
        d = 1;
        if(m < 12)
			m++;
		else
		{
            m = 1;
            if (y == -1)
				y = 1;
			else y++;
        }
    }
}

const int MAXN = 1e7 + 3;
int Y[MAXN], M[MAXN], D[MAXN], t = 1e7;

int main()
{
    int y = -4713, m = 1, d = 1;
    
    for(int i = 0; i <= t; i++)
	{
        Y[i] = y;
		M[i] = m;
		D[i] = d;
        next_date(y, m, d);
    }
    
    int q;
	cin >> q;
    
    for (int i = 1; i <= q; i++)
	{
        int x;
		cin >> x;
		
        int y = Y[x], m = M[x], d = D[x];
        
        if(y < 0)
        	cout << d << " " << m << " " << -y << " BC" << "\n";
        if(y > 0)
			cout << d << " " << m << " " << y << "\n";
    }
    
    return 0;
}
