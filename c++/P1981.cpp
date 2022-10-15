#include <bits/stdc++.h>

using namespace std;

stack <int> math;

/*

	stack <类型> 栈名;
	
	栈名.push(加入的东西);
	栈名.top(); 栈名的第一项
	栈名.pop(); 删除栈名的第一项
	栈名.size(); 栈名的长度
	栈名.empty(); 栈名是否空 

*/

int main()
{
	int a, b; //a相当于存档，b是输入的数字 
	char c; //此为输入的符号 
	
	cin >> a;
	
	// a c b c b c b c b    <- 这样输入 
	
	int m = 10000;
	a = a % m;
	math.push(a);
	
	while (cin >> c >> b) // 将所有要加的加入栈，如果是乘法，乘完了再加 
	{
		if (c == '*') //  *
		{
			a = math.top();
			math.pop();
			math.push(a * b % m); 
		}
		else //  +
			math.push(b);
	}
	
	int sum = 0;
	
	while (math.size())
	{
		sum += math.top();
		sum %= m;
		math.pop();
	}
	
	cout << sum;
	
	return 0;
}
