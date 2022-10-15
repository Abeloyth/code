#include <bits/stdc++.h>

using namespace std;

char H[100005], S1[100005];
int f[10000005];

int main()
{
    int n, o;
    long long int Q;
    
    cin >> n >> o;
    
    for (int i = 1; i <= n; i++)
    {
        cin >> H;
        int v;
        for (int j = 0; j < strlen(H); j++)
        {
        	v = (int) H[j];
            S1[j] = (((char) (v + o)) > 'Z' ? (char) (v + o - 'Z' + 'A' - 1) : (char) (v + o));
            cout << S1[j];
        }
        cout << "\n";
        
        for (int j = 0; j < strlen(S1); j++)
        {
        	int x = 0;
		    for (int i = 1; i <= f[0]; i++)
			{
		        f[i] = f[i] * (int) S1[j] + x;
		        x = f[i] / 10;
		        f[i] = f[i] % 10;	
		    }
		    while (x > 0)
			{
		        f[0]++;
		        f[f[0]] = x % 10;
		        x = x / 10;
		    }
		}
		for (int j = f[0]; j >= 1; j--)
		{
			cout << f[j];
		}
		cout << "\n";
    }
    
    return 0;
}
