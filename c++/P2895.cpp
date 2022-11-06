#include <bits/stdc++.h>

using namespace std;

int M, Map[305][305] = {}, b[305][305] = {}, dir[4][2] = {{+1, 0}, {-1, 0}, {0, +1}, {0, -1}};

struct node
{
	int x, y, time_;
	node(){}
	node(int x_, int y_, int time__) :x(x_), y(y_), time_(time__) {}
};

void bfs(int sx, int sy)
{
	queue <node> q;
	q.push(node(sx, sy, 0));
	
	while (! q.empty())
	{
		node now = q.front();
		q.pop();
		
		for (int i = 0; i < 4; i++)
		{
			node noww = node(now.x + dir[i][0], now.y + dir[i][1], now.time_ + 1);
			
			if (noww.x >= 0 && noww.y >= 0 && b[noww.x][noww.y] == 0)
			{
				if (Map[noww.x][noww.y] == -1)
				{
					cout << noww.time_;
					return;
				}
				
				if (noww.time_ < Map[noww.x][noww.y])
				{
					b[noww.x][noww.y] = 1;
					q.push(noww);
				}
			}
			
		}
	}
	cout << -1;
	return;
}

int main()
{
	cin >> M;
	
	for (int i = 0; i < 305; i++)
	{
		for (int j = 0; j < 305; j++)
		{
			Map[i][j] = -1;
		}
	}
	
	for (int i = 1; i <= M; i++)
	{
		int X, Y, T;
		cin >> X >> Y >> T;
		if (Map[X][Y] == -1 || Map[X][Y] > T)
		{
			Map[X][Y] = T;
		}
		
		for (int j = 0; j < 4; j++)
		{
			if (X + dir[j][0] >= 0 && Y + dir[j][1] >= 0)
			{
				if (Map[X + dir[j][0]][Y + dir[j][1]] == -1 || Map[X + dir[j][0]][Y + dir[j][1]] > T)
				{
					Map[X + dir[j][0]][Y + dir[j][1]] = T;
				}
			}
		}
	}
	
	b[0][0] = 1;
	bfs(0, 0);
	
	return 0;
} 
