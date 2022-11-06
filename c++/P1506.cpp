#include <bits/stdc++.h>

using namespace std;

int x, y, Map[505][505] = {}, b[505][505] = {}, dir[4][2] = {{+1, 0}, {-1, 0}, {0, +1}, {0, -1}};

struct node
{
	int x, y;
	node(){}
	node(int x_, int y_) :x(x_), y(y_) {}
};

void bfs()
{
	queue <node> q;
	for (int i = 1; i <= y; i++)
	{
		if (Map[1][i] == 1)
		{
			b[1][i] = 1;
			Map[1][i] = 3;
			q.push(node(1, i));
		}
		if (Map[x][i] == 1)
		{
			b[x][i] = 1;
			Map[x][i] = 3;
			q.push(node(x, i));
		}
	}
	for (int i = 2; i <= x - 1; i++)
	{
		if (Map[i][1] == 1)
		{
			b[i][1] = 1;
			Map[i][1] = 3;
			q.push(node(i, 1));
		}
		if (Map[i][y] == 1)
		{
			b[i][y] = 1;
			Map[i][y] = 3;
			q.push(node(i, y));
		}
	}
	
	while (! q.empty())
	{
		node now = q.front();
		q.pop();
		
		for (int i = 0; i < 4; i++)
		{
			node noww = node(now.x + dir[i][0], now.y + dir[i][1]);
			if (! (noww.x >= 0 && noww.x <= x && noww.y >= 0 && noww.y <= y))
				continue;
			if (Map[noww.x][noww.y] == 1 && b[noww.x][noww.y] == 0)
			{
				b[noww.x][noww.y] = 1;
				Map[noww.x][noww.y] = 3;
				q.push(noww);
			}
		}
	}
	
	
	int ans = 0;
	for (int i = 1; i <= x; i++)
	{
		for (int j = 1; j <= y; j++)
		{
			if (Map[i][j] == 1)
				ans ++;
		}
	}
	
	cout << ans; 
}

int main()
{
	cin >> x >> y; 
	
	for (int i = 1; i <= x; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < y; j++)
		{
			if (str[j] == '0')
				Map[i][j + 1] = 1;
			if (str[j] == '*')
				Map[i][j + 1] = 2;
		} 
	}
	
	bfs();
	
	return 0;
}
