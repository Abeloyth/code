#include <bits/stdc++.h>

using namespace std;

double arr_d[15], arr_p[15], d1, c, d2, p;
int n;

double solution()
{
	arr_p[0] = p;
	arr_d[n + 1] = d1;
	
	double max_dist = c * d2, ans = 0, cur_c = 0;
	int cur_position = 0;
	
	while (cur_position <= n)
	{
		int to = 0, alter_to = 0, alter_val = 114514.0;
		
		for (int i = cur_position + 1; i <= n + 1 && arr_d[i] - arr_d[cur_position] <= max_dist; i++)
		{
			if (arr_p[i] < arr_p[cur_position])
			{
				to = i;
				break;
			}
			else if (arr_p[i] < alter_val)
			{
				alter_to = i;
				alter_val = arr_p[i];
			}
		}
		if (to)
		{
			double dis = arr_d[to] - arr_d[cur_position];
			
			if (cur_c > (dis / d2))
			{
				cur_c -= dis / d2;
			}
			else
			{
				ans += arr_p[cur_position] * ((dis / d2) - cur_c);
				cur_c = 0;
			}
			
			cur_position = to;
		}
		else if (alter_to)
		{
			double dis = arr_d[alter_to] - arr_d[cur_position];
			
			ans += arr_p[cur_position] * (c - cur_c);
			cur_position = alter_to;
			cur_c = c - (dis / d2);			
		}
		else
		{
			return -1;
		}
	}
	return ans;
}


int main()
{
	cin >> d1 >> c >> d2 >> p >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr_d[i] >> arr_p[i];
	}
	
	double a = solution();
	if (a == -1)
		cout << "No Solution\n";
	else
		cout << setiosflags(ios::fixed) << setprecision(2) << a << "\n";
		
 	return 0;
}
