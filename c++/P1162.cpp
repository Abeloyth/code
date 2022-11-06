#include <bits/stdc++.h>

using namespace std;

int n, Map[35][35] = {}, b[35][35] = {}, dir[4][2] = {{+1, 0}, {-1, 0}, {0, +1}, {0, -1}};

struct node
{
	int x, y;
	node(){}
	node(int x_, int y_) :x(x_), y(y_) {}
};

void bfs()
{
	queue <node> q;
	for (int i = 1; i <= n; i++)
	{
		if (Map[1][i] == 1)
		{
			b[1][i] = 1;
			q.push(node(1, i));
		}
		if (Map[n][i] == 1)
		{
			b[n][i] = 1;
			q.push(node(n, i));
		}
	}
	for (int i = 2; i <= n - 1; i++)
	{
		if (Map[i][1] == 1)
		{
			b[i][1] = 1;
			q.push(node(i, 1));
		}
		if (Map[i][n] == 1)
		{
			b[i][n] = 1;
			q.push(node(i, n));
		}
	}
	
	while (! q.empty())
	{
		node now = q.front();
		q.pop();
		
		for (int i = 0; i < 4; i++)
		{
			node noww = node(now.x + dir[i][0], now.y + dir[i][1]);
			if (! (noww.x >= 0 && noww.x <= n && noww.y >= 0 && noww.y <= n))
				continue;
			if (Map[noww.x][noww.y] == 1 && b[noww.x][noww.y] == 0)
			{
				b[noww.x][noww.y] = 1;
				Map[noww.x][noww.y] = 1;
				q.push(noww);
			}
		}
	}
	
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (Map[i][j] == 1 && b[i][j] != 1)
				cout << 2 << " ";
			else
				cout << Map[i][j] - 1 << " "; 
		}
		cout << "\n";
	}
}

int main()
{
	cin >> n; 
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> Map[i][j];
			Map[i][j] += 1;
		} 
	}
	
	bfs();
	
	return 0;
}
