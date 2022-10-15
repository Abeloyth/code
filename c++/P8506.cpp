#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, sum = 0;
	string a;
	regex pattern(" *# +[a-z#].*");
	cin >> n, getline(cin, a);
	
	for (int i = 1; i <= n; i++)
	{
		getline(cin, a);
		 
		if (regex_match(a, pattern))
		{
			sum ++;
		}
	}
	
	cout << sum;
	
 	return 0;
}

