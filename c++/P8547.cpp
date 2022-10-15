#include <bits/stdc++.h>

using namespace std;

int D, T, ans = 0;

int main()
{
	cin >> D;
	
	for (int i = 1; i <= D; i++)
	{
		int h = 12, m1 = 0, m2 = 0, ans = 0;
		
		cin >> T;
		
		for (int j = 1; j <= T; j++)
		{
			m2 ++;
			if (m2 == 10)
			{
				m2 = 0;
				m1 ++;
				
				if (m1 == 6)
				{
					m1 = 0;
					h ++;
					
					if (h == 13)
					{
						h = 1;
					}
				}
			}
			
			//cout << h << ":" << m1 << m2 << endl;
			if (h >= 10)
			{
				int h1 = h / 10, h2 = h % 10;
				int cha_1 = h1 - h2, cha_2 = h2 - m1, cha_3 = m1 - m2;
				if (cha_1 == cha_2 && cha_2 == cha_3) ans ++;
			}
			else
			{
				int cha_1 = h - m1, cha_2 = m1 - m2;
				if (cha_1 == cha_2) ans ++;
			}
		}
		cout << ans << endl;
	}
	
 	return 0;
}

