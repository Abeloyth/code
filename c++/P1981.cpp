#include <bits/stdc++.h>

using namespace std;

stack <int> math;

/*

	stack <����> ջ��;
	
	ջ��.push(����Ķ���);
	ջ��.top(); ջ���ĵ�һ��
	ջ��.pop(); ɾ��ջ���ĵ�һ��
	ջ��.size(); ջ���ĳ���
	ջ��.empty(); ջ���Ƿ�� 

*/

int main()
{
	int a, b; //a�൱�ڴ浵��b����������� 
	char c; //��Ϊ����ķ��� 
	
	cin >> a;
	
	// a c b c b c b c b    <- �������� 
	
	int m = 10000;
	a = a % m;
	math.push(a);
	
	while (cin >> c >> b) // ������Ҫ�ӵļ���ջ������ǳ˷����������ټ� 
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
