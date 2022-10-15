#include <bits/stdc++.h>

using namespace std;

int n, m, vis[103][103], p;
int dx[5] = {0, -1, 1, 0, 0}, dy[5] = {0, 0, 0, -1, 1};
char mp[103][103];

struct node
{
    int x, y;
}tmp;

queue <node> q;

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			cin >> mp[i][j];
			if(mp[i][j] == '#')
			    vis[i][j]=1;
		}
	tmp.x = 1,tmp.y = 1;
	q.push(tmp);
	vis[1][1] = 1;
	
	while(!q.empty())
	{
		tmp = q.front();
		q.pop();
		
		for(int i = 1; i <= 4; i++)
		{
			int px = tmp.x + dx[i], py = tmp.y + dy[i];
			if(px > n || px < 1 || py > m || py < 1 || vis[px][py])
			    continue;
			    
			node now = {px, py};
			
			vis[px][py] = 1;
			q.push(now);
		}
	}
	
    if (vis[n][m])
        cout << "Yes\n";
	else
	    cout << "No\n";
	
	return 0;
} 
