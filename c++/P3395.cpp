#include <bits/stdc++.h>

using namespace std;

struct coord
{
	int x, y, time;
};

int n, T, Map[1005][1005], x[2005], y[2005], dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool b[1005][1005], flag;
queue <coord> que;

void bfs()
{
	coord now;
	now.x = 1, now.y = 1, now.time = 0;
	que.push(now);
	
	while (! que.empty())
	{
		now = que.front();
		que.pop();
		
		int x_ = now.x, y_ = now.y, time_ = now.time;
		
		if (x_ == n && y_ == n)
		{
			flag = 1;
			break;
		}
		
		Map[x[now.time - 1]][y[now.time - 1]] = 1;
		
		for (int i = 0; i < 4; i++)
		{
			int tx, ty;
			tx = now.x + dir[i][0], ty = now.y + dir[i][1];
			
			if (tx > n || ty > n || tx < 1 || ty < 1 || Map[tx][ty] != 0)
			{
				continue;
			}
			
			if (b[tx][ty] == 0)
			{
				b[tx][ty] = 1;
				
				coord noww;
				noww.x = tx, noww.y = ty, noww.time = time_ + 1;
				que.push(noww);
			}
		}
	}
}

int main()
{
	cin >> T;
	
	for (int i = 1; i <= T; i++)
	{
		memset(Map, 0, sizeof(Map));
		memset(b, 0, sizeof(b));
		flag = 0;
		
		cin >> n;
		
		for (int i = 1; i <= n * 2 - 2; i++)
		{
			cin >> x[i] >> y[i];
		}
		b[1][1] = 1;
		bfs();
		if (flag == 1)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	
 	return 0;
}

