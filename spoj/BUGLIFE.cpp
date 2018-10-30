#include <bits/stdc++.h>
using namespace std;
#define SIZE 1000002
vector<long long> adj[2002];
queue<long long> q;
long long coloured[2002];


void addedge(long long x,long long y)
{
	adj[x].push_back(y);
	adj[y].push_back(x);
}

int bfs(long long src)
{
	coloured[src]=1;

	while(!q.empty())
	{
		q.pop();
	}

	q.push(src);

	while(!q.empty())
	{
		long long u=q.front();
		q.pop();

		for(int i=0;i<adj[u].size();i++)
		{
			long long v=adj[u][i];
			if(coloured[v]==-1)
			{
				coloured[v]=1-coloured[u];
				q.push(v);
			}
			else if(coloured[v]==coloured[u])
			{
				return 0;
			}
		}
	}

	return 1;
}

int main()
{
	long long t,count=0;
	cin>>t;
	while(t--)
	{
		long long n,c;
		int flag=0;
		scanf("%lld %lld",&n,&c);
		int res;
		memset(coloured,-1,sizeof(coloured));

		for(long long i=1;i<=n;i++)
		{
			adj[i].clear();
		}

		for(long long i=0;i<c;i++)
		{
			long long x,y;
			scanf("%lld %lld",&x,&y);
			addedge(x,y);
		}

		/*for(long long i=1;i<=n;i++)
		{
			for(long long j=0;j<adj[i].size();j+=1)
			{
				cout<<i<<" "<<adj[i][j]<<endl;
			}
		}*/

		for(long long i=1;i<=n;i++)
		{
			if(coloured[i]==-1)
			{
				res=bfs(i);
				if(res==0)
				{
					flag=1;
					break;
				}
			}
		}	
		count++;
		printf("Scenario #%lld:\n", count);
		if(flag==0)
		{
			printf("No suspicious bugs found!\n");
		}
		else
		{
			printf("Suspicious bugs found!\n");
		}
	}
}