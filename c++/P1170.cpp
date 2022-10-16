#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n, rabbit_x, rabbit_y, man_x, man_y;
	
	cin >> n;
	
	for (int i = 1; i<= n; i++)
	{
		cin >> man_x >> man_y;
		cin >> rabbit_x >> rabbit_y;
		if (((man_x == rabbit_x) && (man_y != rabbit_y - 1) && (man_y != rabbit_y + 1)) ||
			((man_y == rabbit_y) && (man_x != rabbit_x - 1) && (man_x != rabbit_x + 1)) ||
			((abs(man_x - rabbit_x) == abs(man_y - rabbit_y)) && (abs(man_x - rabbit_x) > 1) && (abs(man_y - rabbit_y) > 1)))
			cout << "no";
		else
			cout << "yes";
	}
	
 	return 0;
}

