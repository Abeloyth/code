#include <bits/stdc++.h>

using namespace std;

struct block
{
	int head, tail, type;
};

long long n, cnt, t[200005];
bool is_use[200005];
list <block> que, que2;

//list.push_back() = que.push()
//list.pop_front() = que.pop()

int main()
{
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &t[i]);
	
	t[n + 1] = !t[n];
	
	int h = 1;
	for (int i = 2; i <= n + 1; i++)
	{
		if (t[i] != t[i - 1])
		{
			block b;
			b.head = h;
			b.tail = i - 1;
			b.type = t[i - 1];
			que.push_back(b);
			
			h = i;
		}
	}
	
	cnt = n;
	while (cnt)
	{
		while (que.size())
		{
			block b = que.front();
			que.pop_front();
			
			while (is_use[b.head] && b.head <= b.tail)
			{
				b.head ++;
			}
			if (b.head > b.tail)
				continue;
			
			printf("%d ", b.head);
			cnt--;
			
			is_use[b.head] = 1;
			
			if (b.head == b.tail)
				continue;
				
			b.head ++;
			
			que2.push_back(b);
		}
		
		printf("\n");
		
		while (que2.size())
		{
			block b, b2;
			
			b = que2.front();
			que2.pop_front();
			
			while (que2.size())
			{
				b2 = que2.front();
				
				if (b2.type == b.type)
				{
					b.tail = b2.tail;
					que2.pop_front();
				}
				else
					break;
			}
			
			que.push_back(b);
		}
	}
	
 	return 0;
}

