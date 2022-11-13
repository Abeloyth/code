#include <bits/stdc++.h>

using namespace std;

struct edge
{
	int x, y;
	edge(){}
	edge(int x_, int y_): x(x_), y(y_) {}
};

int n, idx = 1, Map[1005][1005], b[1005][1005], Map_[1005][1005], sum[1000005], dir[4][2] = {{+1, 0}, {-1, 0}, {0, +1}, {0, -1}};
long long m;

int bfs(int x, int y)
{
	if (sum[Map_[x][y]] != 0)
		return sum[Map_[x][y]];
	
	queue <edge> q;
	
	int ans = 0;
	
	b[x][y] = 1;
	q.push(edge(x, y));
	//Map_[x][y] = idx;
	
	while (! q.empty())
	{
		edge now = q.front();
		q.pop();
		ans ++;
		Map_[now.x][now.y] = idx;
		
		for (int i = 0; i < 4; i++)
		{
			int nx, ny;
			nx = now.x + dir[i][0], ny = now.y + dir[i][1];
			
			if (! (nx > 0 && ny > 0 && nx <= n && ny <= n))
				continue;
				
			if (Map[nx][ny] != Map[now.x][now.y] && b[nx][ny] == 0)
			{
				b[nx][ny] = 1;
			
				q.push(edge(nx, ny));				
			}
		}
	}
	
	sum[idx] = ans;
	idx ++;
	return ans;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < n; j++)
		{
			Map[i][j + 1] = str[j] - '0';
		}
	}
	
	/*
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << Map[i][j] << " ";
		}
		cout << "\n";
	}
	*/
	
	for (int i = 1; i <= m; i++)
	{
		int x, y; 
		cin >> x >> y;
		
		cout << bfs(x, y) << "\n"; 
	}
	
	return 0;
}
