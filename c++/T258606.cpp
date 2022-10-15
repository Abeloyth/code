#include <bits/stdc++.h>

using namespace std;

vector <int> edge[100005];
int n, m, b[100005];

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u ,v;
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	
	queue <int> q;
    q.push(1);

    while(!q.empty())
	{
        int now = q.front();
        q.pop();

        if(b[now]) continue;
        b[now] = 1;

        for(auto p: edge[now])
            if(!b[p])
                q.push(p);
    }
    
    cout << (b[n] ? "Yes" : "No");
	
 	return 0;
}

