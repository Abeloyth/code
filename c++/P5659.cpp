#include<bits/stdc++.h>
#define up(l,r,i) for(int i=l,END##i=r;i<=END##i;++i)
#define dn(r,l,i) for(int i=r,END##i=l;i>=END##i;--i)
using namespace std;
typedef long long i64;
const int INF =2147483647;
const int MAXN= 2e3 + 3;
const int MAXM= 4e3 + 3;
int n, U[MAXN], V[MAXN], C[MAXN], W[MAXN];

namespace Small{
    int A[MAXN], B[MAXN]; bool X[MAXN];
    void dfs(int s){
        if(s == n){
            up(1, n, i) B[W[i]] = i;
            up(1, n, i) if(A[i] != B[i]){
                if(B[i] < A[i]){
                    up(1, n, j) A[j] = B[j];
                    return;
                } else if(B[i] > A[i]) return;
            }
        } else {
            up(1, n - 1, i) if(!X[i]){
                X[i] = true , swap(W[U[i]], W[V[i]]);
                dfs(s + 1);
                X[i] = false, swap(W[U[i]], W[V[i]]);
            }
        }
    }
    void mian(){
        A[1] = INF, dfs(1);
        up(1, n, i) printf("%d%c", A[i], " \n"[i == n]);
    }
}
namespace Flower{
    int M[MAXN], F[MAXN], B[MAXN], r; bool T[MAXN], A[MAXN];
    int G[MAXN];
    int getfa(int x){
        return x == G[x] ? x : G[x] = getfa(G[x]);
    }
    void link(int a, int b){
        G[getfa(a)] = getfa(b);
    }
    void mian(){
        up(1, n, i) if(C[i] == n - 1) r = i;
        up(1, n, i) M[W[i]] = i, T[i] = false, G[i] = i;
        up(1, n, i){
            int x = M[i];
            up(1, n, j) if(j != x && !T[j] && getfa(x) != getfa(j)){
                T[j] = true, B[i] = j, link(x, j); break;
            }
        }
        up(1, n, i) A[i] = false;
        up(1, n - 1, i) A[B[i]] = true;
        up(1, n, i) if(!A[i]) B[n] = i;
        up(1, n, i) printf("%d%c", B[i], " \n"[i == n]);
    }
}
namespace Gra{
    const int SIZ = 4e3 + 3;
    int HH[SIZ], VV[SIZ], NN[SIZ], t;
    void add(int u, int v){
        VV[++ t] = v, NN[t] = HH[u], HH[u] = t;
    }
    void clear(){
        memset(HH, 0, sizeof(HH));
        memset(VV, 0, sizeof(VV));
        memset(NN, 0, sizeof(NN)), t = 0;
    }
}
namespace Line{
    int t, A[MAXN], B[MAXN], M[MAXN], L[MAXN], R[MAXN], O[MAXN];
    int T[MAXN]; bool X[MAXN];
    void dfs(int u, int f){
        using namespace Gra; 
        A[++ t] = u, B[u] = t;
        for(int i = HH[u], v;i;i = NN[i]) if((v = VV[i]) != f){
            dfs(v, u);
        }
    }
    void mian(){
        Gra :: clear(), t = 0;
        up(1, n - 1, i){
            Gra::add(U[i], V[i]);
            Gra::add(V[i], U[i]);
        }
        int r = 0; up(1, n, i) if(C[i] == 1) r = i; dfs(r, 0);
        up(1, n, i){
            int x = A[i];
            T[x] = true;
            L[x] = i == 1 ? 0 : A[i - 1];
            R[x] = i == n ? 0 : A[i + 1];
        }
        T[n] = false;
        for (int i = 1; i <= n; i++) M[W[i]] = i, T[i] = 0; 
        for (int i = 1; i <= n; i++)
		{
            int x = M[i], p = B[x];
			T[A[1]] = T[A[n]] = 0;
			
            for (int j = 1; i <= n; j++)
            {
				if(j != x)
				{
	                int y, z;
	                
	                if(p <= B[j])
					{
	                    y = R[x];
						z = R[x];
	                    
	                    if(T[x] && T[x] != -1)
							goto nxt;
							
	                    if(T[j] && T[j] != -1)
							goto nxt;
	                    
	                    while(y != j)
						{
	                        if(T[y] && T[y] != 1)
								goto nxt;
							y = R[y];
	                    }
	                    
	                    O[i] = j;
						T[x] = -1;
						T[j] = -1;
						
	                    while(z != j)
							T[z] = 1, z = R[z];
							
	                    break;
	                }
					else
					{
	                    y = L[x];
						z = L[x];
	                    
	                    if(T[x] && T[x] != 1)
							goto nxt;
							
	                    if(T[j] && T[j] != 1)
							goto nxt;
	                    
	                    while(y != j)
						{
	                        if(T[y] && T[y] != -1)
								goto nxt;
							y = L[y];
	                    }
	                    
	                    O[i] = j;
						T[x] = 1;
						T[j] = 1;
	                    
	                    while(z != j)
							T[z] = -1, z = L[z];
							
	                    break;
	                }
	                
	                nxt://(goto)
						;
	            }
        	}
		}
        
        for (int i = 1; i <= n; i++)
			cout << O[i] << (i == n) ? "\n" : " ";
    }
}

int main()
{  
    int T;
	cin >> T;
    for (int i = 1; i <= T; i++)
	{
        int c1 = 0, c2 = 0, cn = 0;
        
        memset(C, 0, sizeof(C));
        
        cin >> n;
        for (int i = 1; i <= n; i++)
		{
            int x;
			cin >> x;
			W[x] = i;
        }
        
        for (int i = 1; i <= n - 1; i++)
		{
            cin >> U[i] >> V[i]; 
            C[U[i]]++;
            C[V[i]]++;
        }
        
        for (int i = 1; i <= n; i++)
		{
            if(C[i] == 1)
				c1++;
            if(C[i] == 2)
				c2++;
            if(C[i] == n - 1)
				cn++;
        }
        
        if(n <= 10)
			Small :: mian();
		else if(c1 == 2 && c2 == n - 2)
            Line::mian();
		else if(cn == 1)
            Flower::mian();
    }
    return 0;
}
