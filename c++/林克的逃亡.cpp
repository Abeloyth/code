#include <bits/stdc++.h>

using namespace std;

int s, k, b[200050];
struct node
{
	int n, s;
};
queue <node> que;

void bfs()
{
	node v;
	v.s = 0, v.n = s;
	b[s] = 1;
	que.push(v);
	
	while (! que.empty())
	{
		v = que.front();
		
		if (v.n == k)
		{
			cout << v.s;
			exit(0);
		}
		
		que.pop();
		
		node u[4];
		u[1].n = v.n + 1;
		u[2].n = v.n - 1;
		u[3].n = v.n * 2;
		
		for (int i = 1; i <= 3; i++)
		{
			u[i].s = v.s + 1;
			if (u[i].n >= 0 && u[i].n < 200050 && b[u[i].n] == 0)
			{
			    b[u[i].n] = 1;
				que.push(u[i]);
			}
		}
	}
}

int main()
{
	cin >> s >> k;
	
	bfs();
	
	return 0;
}
