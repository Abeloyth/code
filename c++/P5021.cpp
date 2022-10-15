#include<bits/stdc++.h>

using namespace std;

const int MAXN = 5e4 + 3;
const int MAXM = 1e5 + 3;
int mn = MAXN;

namespace Gra
{
    int H[MAXN], V[MAXM], N[MAXM], W[MAXM], t;
    
    void add(int u, int v, int w)
	{
        V[++ t] = v;
		N[t] = H[u];
		W[t] = w;
		H[u] = t;
    }
}

int n, m;

namespace SubA
{
    int M[MAXN], N[MAXN], ans;
    
    void dfs(int u, int f)
	{
        for (int i = Gra::H[u]; i; i = Gra::N[i])
		{
            int v = Gra::V[i];
				if (v == f)
					continue;
					
            dfs(v, u);
            
            int w = Gra::W[i], d = w + M[v];
            
            if (d >= M[u])
            {
            	N[u] = M[u];
				M[u] = d;
			}
			else if (d >= N[u])
				N[u] = d;
				
            ans = max(ans, M[u] + N[u]);
        }
    }
    void main()
	{
        dfs(1, 0);
        cout << ans << "\n";
    }
}
namespace SubB
{
    int M[MAXN], W[MAXN], ans;
    
    bool check(int w)
	{
        int c = 0;
        
        for(int i = 1; i <= n - 1; i++)
            M[i] = W[i];
            
        for(int i = 1; i <= n - 1; i++)
		{
            if(M[i] >= w)
			{
				c++;
				M[i] = 0;
			}
        }
        
        int p = 1;
        
        for(int i = n - 1; i >= 1;-- i)
        {
			if(M[i] != 0)
			{
	            while(p < i && M[i] + M[p] < w) p++;
	            if(p < i && M[i] + M[p] >= w)
				{
					c++;
					M[i] = M[p] = 0;
				}
	            
				else
					break;
	        }
	        return c >= m;
		}
    }
    
    void main()
	{
        int ans = 0, t = 0;
        for(int i = Gra::H[1];i;i = Gra::N[i])
		{
            int w = Gra::W[i];
			W[++ t] = w;
        }
        
        sort(W + 1, W + 1 + n - 1);
        
        for(int i = 30; i >= 0; i--)
		{
            if (check(ans | (1 << i)))
                ans |= 1 << i;
        }
        
        cout << ans << "\n";
    }
}

namespace SubC
{
    int M[MAXN], ans, t;
    
    void dfs(int u, int f)
	{
        for(int i = Gra::H[u]; i; i = Gra::N[i])
		{
            int v = Gra::V[i];
			if(v == f)
				continue;
            M[t++] = Gra::W[i];
			dfs(v, u);
        }
    }
    
    bool check(int w)
	{
        int c = 0, x = 0;
        for(int i = 1; i <= n - 1; i++)
		{
            if(x + M[i] >= w)
			{
				c++;
				x = 0;
			}
			else
				x += M[i];
        }
        return c >= m;
    }
    
    void main()
	{
        dfs(1, 0);
        int ans = 0, t = 0;
        for (int i = 30; i >= 0; i--)
		{
            if (check(ans | (1 << i)))
                ans |= 1 << i;
        }
        cout << ans << "\n";
    }
}

int main()
{ 
    bool flag1 = true, flag2 = true;
    cin >> n >> m;
    
    for(int i = 1; i <= n - 1; i++)
	{
        int u, v, w;
		cin >> u >> v >> w;
        
        if(u != 1)
			flag1 = false;
        if(v != u + 1)
			flag2 = false;
			
        Gra::add(u, v, w);
        Gra::add(v, u, w);
        mn = min(w, mn);
    }
    
    if (m == 1)
		SubA::main();
	else if (flag1)
		SubB::main();
    else if (flag2)
		SubC::main();
	else if (m == n - 1)
		cout << mn;
		
    return 0;
}
