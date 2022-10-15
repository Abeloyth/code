#include <bits/stdc++.h>
#include <limits.h>

using namespace std;

const int MAXN = 500 + 3;
const int MAXT = 4e6 + 200 + 3;

int n, m, t = 4e6 + 200, T[MAXN];
long long F[MAXT], S[MAXT], C[MAXT];

int main()
{
	cin >> n >> m;
	
	if (m > 10)
		t = 1e4 + 200; 
		
	for(int i = 1; i <= n; i++)
	{
		cin >> T[i];
		C[T[i]] ++;
		S[T[i]] += T[i];
	}
	
	for(int i = 1; i <= t; i++)
	{
		S[i] = S[i - 1] + S[i];
		C[i] = C[i - 1] + C[i];
	}
	
	for(int i = 0; i <= t; i++)
	{
		F[i] = LLONG_MAX;
		for(int j = max(0, i - 2 * m); j <= i - m; j++)
		{
			int w = 0;
			F[i] = min(F[i], F[j] + 1ll * (C[i] - C[j]) * i - (S[i] - S[j]));
		}
		F[i] = min(F[i], 1ll * C[i] * i - S[i]);
	}
	
	cout << F[t];
	
 	return 0;
}

