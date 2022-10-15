#include<bits/stdc++.h>

using namespace std;

const int MAXN = 40 + 3;
const int MAXM = 3 + 3;

int A[MAXN], C[MAXM], n, m, ans, W[MAXN][MAXM];

void dfs(int s)
{
    if(s == n + 1)
	{
        int g = 0, t = 1;
        
        for (int i = 0; i <= m; i++)
			C[i] = 0;
		
		for (int i = 1; i <= n; i++)
		{
			C[A[i]] ++;
			t = 1ll * t * W[i][A[i]] % 998244353;
		}
		
		for (int i = 1; i <= m; i++)
			g = max(g, C[i]);
			
        int k = n - C[0];
        
        if(g <= k / 2 && k != 0)
            ans = (ans + t) % 998244353;
    }
	else
	{
        dfs(s + 1);
        for (int i = 1; i <= m; i++)
        {
			if(W[s][i] != 0)
			{
	            A[s] = i;
				dfs(s + 1);
				A[s] = 0;
	        }
		}
    }
}

void add_to(int &a, long long b)
{
    a = (b + a) % 998244353;
}

namespace Equal2
{
    int F[MAXN][MAXN][MAXN];
    
    void m_equal_2()
	{
        F[0][0][0] = 1, ans = 0;
        for (int i = 1; i <= n; i++)
	    {
	        for (int j = 0; j <= i; j++)
	        {
	        	for (int k = 0; k <= j; k++)
	        	{
			        F[i][j][k] = F[i - 1][j][k];
		            if (j > 0)
					{
		                if (k > 0)
		                	add_to(F[i][j][k], 1ll * F[i - 1][j - 1][k - 1] * W[i][1]);
		                	
		                add_to(F[i][j][k], 1ll * F[i - 1][j - 1][k] * W[i][2]);
		            }
				}
			}
		}
		for (int i = 1; i <= n; i++)
		{
        	if(i % 2 == 0)
            	add_to(ans, F[n][i][i / 2]);
		}
    }
}

namespace Equal3
{
    int F[MAXN][MAXN][MAXN][MAXN];
    void m_equal_3()
	{
        F[0][0][0][0] = 1, ans = 0;
        for (int i = 1; i <= n; i++)
        {
        	for (int j = 0; j <= i; j++)
        	{
        		for (int k = 0; k <= j; k++)
        		{
        			for (int l = 0; l <= j; l++)
        			{
        				F[i][j][k][l] = F[i - 1][j][k][l];
		            	if(j > 0)
						{
			                if(k > 0)
								add_to(F[i][j][k][l], 1ll * F[i - 1][j - 1][k - 1][l] * W[i][1]);
			                if(l > 0)
								add_to(F[i][j][k][l], 1ll * F[i - 1][j - 1][k][l - 1] * W[i][2]);
								
			                add_to(F[i][j][k][l], 1ll * F[i - 1][j - 1][k][l] * W[i][3]);
						}
					}
				}
			}
        }
        for (int i = 1; i <= n; i++)
        {
        	for (int j = 0; j <= i; j++)
        	{
        		for (int k = 0; k <= i; k++)
        		{
        			if (j <= i / 2 && k <= i / 2 && (i - j - k) <= i / 2)
        				add_to(ans, F[n][i][j][k]);
				}
			}
		}
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
		W[i][0] = 1;
    for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> W[i][j];
		}
	}
	
    if (m == 2)
		Equal2::m_equal_2();
	else if (m == 3)
		Equal3::m_equal_3();
	else
    	dfs(1);
    
    cout << ans;
    
    return 0;
}
