#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

#include<bits/stdc++.h>

using namespace std;

struct plane
{
	int a, b;
}m[2][100005];

bool cmp(plane a, plane b)
{
	return a.a < b.a;
}

bool cmp_sum(int a, int b)
{
	return a > b;
}

int n, m1, m2;

int main()
{
	cin >> n >> m1 >> m2;
	
	for (int i = 1; i <= m1; i++)
	{
		cin >> m[0][i].a >> m[0][i].b;
	}
	
	for (int i = 1; i <= m2; i++)
	{
		cin >> m[1][i].a >> m[1][i].b;
	}
	
	sort(m[0] + 1, m[0] + m1 + 1, cmp);
	sort(m[1] + 1, m[1] + m2 + 1, cmp);
	
	int up[100005], sum_[100005];
	
	for (int i = 1; i <= 100005; i++)
	{
		up[i] = 1000000;
	}
	
	for (int i = 1; i <= n + 1; i++)
	{
		int gn = i - 1, gj = n - (i - 1), sum = 0;
		
		for (int j = 1; j <= m1; j++)
		{
			for (int k = 1; k <= m1; k++)
			{
				if (m[0][j].a >= up[k])
				{
					up[k] = 1000000;
					gn ++;
				}
			}
			
			if (gn != 0)
			{
				sum ++;
				gn --;
				up[j] = m[0][j].b;
			}
		}
		
		for (int j = 1; j <= m2; j++)
		{
			for (int k = 1; k <= m2; k++)
			{
				if (m[1][j].a >= up[k])
				{
					up[k] = 1000000;
					gj ++;
				}
			}
			
			if (gj != 0)
			{
				sum ++;
				gj --;
				up[j] = m[1][j].b;
			}
		}
		
		sum_[i] = sum;
	}
	
	sort(sum_ + 1, sum_ + n + 1, cmp_sum);
	
	cout << sum_[1];
	
 	return 0;
}

