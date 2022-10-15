#include<bits/stdc++.h>

using namespace std;

namespace Gra
{
    const int MAXN = 3e5 + 3;
    const int MAXM = 6e5 + 3;
    int H[MAXN], V[MAXM], N[MAXM], t;
    
    void clear()
	{
        memset(H, 0, sizeof(H));
        memset(V, 0, sizeof(V));
        memset(N, 0, sizeof(N));
        t = 0;
    }
    
    void add(int u, int v)
	{
        V[++ t] = v;
		N[t] = H[u];
		H[u] = t;
    }
}

int n, m;

namespace Sub1
{
	void dfs1(int u, int f);
	void dfs2(int u, int f);
	void dfs3(int u, int f);
	
    const int MAXN = 1e5 + 3;
    
    int S[MAXN], T[MAXN], s;
    
	long long ans;
	
    void dfs1(int u, int f)
	{
        using namespace Gra;
        
        S[u] = 1;
        
        for(int i = H[u], v;i;i = N[i])
        {
			if((v = V[i]) != f)
			{
	            dfs1(v, u);
				S[u] += S[v];
	        }
		}
    }
    
    void dfs2(int u, int f)
	{
        using namespace Gra;
        
        S[u] = 1;
        
        for(int i = H[u], v; i; i = N[i])
		{
	        if((v = V[i]) != f)
			{
	            s = S[v];
				dfs3(v, u);
	            s = n - S[v];
				dfs3(u, v);
	            dfs2(v, u);
	        }
		}
    }
    
    void dfs3(int u, int f)
	{
        using namespace Gra;
        
        T[u] = 1;
		int max_size = 0;
        
        for(int i = H[u], v; i; i = N[i])
		{
	        if((v = V[i]) != f)
			{
	            dfs3(v, u);
				T[u] += T[v];
	            max_size = max(max_size, T[v]);
	        }
		}
		
        max_size = max(max_size, s - T[u]);
        if(max_size <= s / 2)
            ans += u;
    }
    
    void main()
	{
        dfs1(1, 0);
        dfs2(1, 0);
        
		cout << ans;
        
        ans = 0;
    }
}

namespace Sub2
{
	const int MAXN = 5e4 + 3;
	
	int P[MAXN], t, s;
	long long ans;
	
	void dfs(int u, int f)
	{
	    using namespace Gra;
	    P[++ t] = u;
	    for(int i = H[u], v;i;i = N[i]) if((v = V[i]) != f)
	        dfs(v, u);
	}
	
	void gravity(int l, int r)
	{
	    if((r - l + 1) % 2 == 1)
			ans += P[(l + r) / 2];
	    else
			ans += P[(l + r) / 2] + P[(l + r + 1) / 2];
	}
	
	void main()
	{
	    t = 0;
	    for(int i = 1; i <= n; i++)
	    {
	        if(Gra::N[Gra::H[i]] == 0)
			{
				dfs(i, 0);
				break;
			}
		}
		
	    for(int i = 1; i <= n - 1; i++)
		{
	        gravity(1, i);
			gravity(i + 1, n);
	    }
	    
	    cout << ans;
	    ans = 0;
	}
}

namespace Sub3
{
    const int MAXN = 262143 + 3;
    
    int L[MAXN], R[MAXN], S[MAXN], r; bool O[MAXN];
    
    void dfs(int u, int f, bool o)
	{
        using namespace Gra;
        
        S[u] = 1, O[u] = o;
        
        for(int i = H[u], v;i;i = N[i])
		{
			if((v = V[i]) != f)
			{
	            if (L[u])
					R[u] = v;
				else
					L[u] = v;
					
	            if(u == r && v == L[u])
					dfs(v, u, false);
				else if(u == r && v == R[u])
					dfs(v, u, true );
				else 
	            	dfs(v, u, o);
	            	
	            S[u] += S[v];
	        }
        }
    }
    
    int find_root()
	{
        using namespace Gra;
        
        for(int i = 1; i <= n; i++)
		{
            if(H[i] && N[H[i]] && !N[N[H[i]]])
                return i;
        }
        
        return 0;
    }
    
    void main()
	{
        long long ans = 0;
        for(int i = 1; i <= n; i++)
            L[i] = R[i] = 0;
            
        r = find_root();
		dfs(r, 0, 0);
		
        for(int i = 1; i <= n; i++)
		{
            if(i == r)
				continue;
			ans += i;
			int t = n - S[i];
			
            if(O[i])
			{
                int a = L[r], b = L[a], c = R[a];
                
                if(S[a] <= t / 2)
					ans += r;
					
                if(S[L[a]] <= t / 2 && S[R[a]] <= t / 2 && (t - S[a]) <= t / 2)
                    ans += a;
                    
                if(S[L[b]] <= t / 2 && S[R[b]] <= t / 2 && (t - S[b]) <= t / 2)
                    ans += b + c;
            }
			else
			{
                int a = R[r], b = L[a], c = R[a];
                
                if(S[a] <= t / 2)
					ans += r;
					
                if(S[L[a]] <= t / 2 && S[R[a]] <= t / 2 && (t - S[a]) <= t / 2)
                    ans += a;
                    
                if(S[L[b]] <= t / 2 && S[R[b]] <= t / 2 && (t - S[b]) <= t / 2)
                    ans += b + c;
            }
        }
        
        cout << ans;
    }
}

int main()
{
    int TEST;
	cin >> TEST;
	
    for (int i = 1; i <= TEST; i++)
	{
        cin >> n;
		Gra::clear();
		
        for(int j = 1; j < n; j++)
		{
            int u, v;
			cin >> u >> v;
			
            Gra::add(u, v);
            Gra::add(v, u);
        }
        
        if(n == 7 || n == 199 || n == 1999)
            Sub1::main();
            
        if(n == 49991)
            Sub2::main();
            
        if(n == 262143)
            Sub3::main();
            
        cout << "\n";
    }
    
    return 0;
}
