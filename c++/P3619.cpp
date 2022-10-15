#include <bits/stdc++.h>

using namespace std;

int t[100005], b[100005];

bool cmp(pair<int, int> x, pair<int, int> y)
{
	return x.first + x.second > y.first + y.second;
}

int solution(int T, int n, int* t, int* b)
{
	vector<pair<int, int>> plus, minus;
	
	for (int i = 1; i <= n; i++)
	{
		if (b[i] >= 0) 
			plus.push_back(make_pair(t[i], b[i]));
		else
			minus.push_back(make_pair(t[i], b[i]));
	}
	
	sort(plus.begin(), plus.end());
	
	long long cur = T;
	for (int i = 0; i < plus.size(); i++)
	{
		if (cur <= plus[i].first) 
			return -1;
		cur += plus[i].second;
	}
	
	sort(minus.begin(), minus.end(), cmp);
	
	for (int i = 0; i < minus.size(); i++)
	{
		if (cur <= minus[i].first) 
			return -1;
			
		cur += minus[i].second;
		
		if (cur <= 0) 
			return -1;
	}
	
	return 1;
}

int main()
{
    int z;
    cin >> z;
    for (int i = 1; i <= z; i++)
    {
    	memset(t, 0, sizeof(t));
    	memset(b, 0, sizeof(b));
    	
    	int n, T;
    	cin >> n >> T;
    	
    	for (int i = 1; i <= n; i++)
    		cin >> t[i] >> b[i];
    		
	    cout << ((solution(T, n, t, b) == 1) ? "+1s" : "-1s");
		cout << "\n";
	}
	
 	return 0;
}
