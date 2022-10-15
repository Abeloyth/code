#include <bits/stdc++.h>

using namespace std;

struct coord
{
	int x, y, time;
};

queue <coord> que;

int n, m, a, b, P[505][505], dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
coord infect[505];
int ans[505][505];

void bfs()
{	
	while (! que.empty())
	{
		coord now;
		
		for (int i = 0; i < 4; i++)
		{
			now = que.front();
			int tx = now.x + dir[i][0], ty = now.y + dir[i][1];
			
			if (tx > n || ty > m || tx < 1 || ty < 1)
				continue;
			
			if (P[tx][ty] == 0)
			{
				P[tx][ty] = 1;
				
				coord nnow;
				nnow.x = tx; nnow.y = ty, nnow.time = now.time + 1;
				que.push(nnow);
			}
		}
		
		ans[now.x][now.y] = now.time;
		que.pop();
	}
}

int main()
{
	//freopen("血色先锋队.in", "r", stdin);
	//freopen("血色先锋队.out", "w", stdout);
	
	cin >> n >> m >> a >> b;
	
	for (int i = 1; i <= a; i++)
	{
		cin >> infect[i].x >> infect[i].y;
		infect[i].time = 0;
		
		coord new_;
		new_.time = 0;
		new_.x = infect[i].x, new_.y = infect[i].y;
		que.push(new_);
		P[new_.x][new_.y] = 1;
	}
		
	bfs();
	
	for (int i = 1; i <= b; i++)
	{
		int x, y;
		cin >> x >> y;
		cout << ans[x][y] << "\n";
	}

 	return 0;
}
