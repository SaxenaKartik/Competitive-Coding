#include <bits/stdc++.h>
using namespace std;
#define SIZE 100002

vector<pair<long long,long long> > adj[SIZE];
long long n;
vector<long long int> v;
queue<pair<long long,long long> > q;
bool vis[SIZE];
long long dist[SIZE];

void addedge(long long u,long long v,long long d)
{
	adj[u].push_back(make_pair(v,d));
	adj[v].push_back(make_pair(u,d));
}

long long BFS(long long src)
{
	q.push(make_pair(src,0));
	long long max=0;
	
	while(!q.empty())
	{
		pair<long long,long long> node=q.front();
		q.pop();

		int x=node.first;
		if(vis[x]) continue;

		vis[x]=true;

		for(int i=0;i<adj[x].size();i++)
		{
			int e=adj[x][i].first;
			int w=adj[x][i].second;

			if(!vis[e])
			{
				if(dist[e]<w+dist[x])
				{
					dist[e]=w+dist[x];
					q.push(make_pair(e,dist[e]));
				}
			}	
			if(max<dist[e])
			{
				max=dist[e];
			}
		}
	}
	//return max;
	cout<<max<<" ";
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		scanf("%lld",&n);

		for(long long int i=1;i<=n;i++)
		{
			adj[i].clear();
		}

		for(long long int i=0;i<n-1;i++)
		{
			long long u,v,d;
			scanf("%lld %lld %lld",&u,&v,&d);

			addedge(u,v,d);
		}
		/*v.clear();
		memset(vis,0,sizeof(vis));
		memset(dist,0,sizeof(dist));
		
		v[1]=BFS(1);
		// v.clear();
		memset(vis,0,sizeof(vis));
		memset(dist,0,sizeof(dist));

		v[2]=BFS(2);

		// v.clear();
		memset(vis,0,sizeof(vis));
		memset(dist,0,sizeof(dist));

		v[3]=BFS(3);
		
		// v.clear();
		memset(vis,0,sizeof(vis));
		memset(dist,0,sizeof(dist));

		v[4]=BFS(4);*/
		for(long long int i=1;i<=n;i++)
		{
			memset(vis,0,sizeof(vis));
			memset(dist,0,sizeof(dist));
			BFS(i);
		}

		/*for(long long int i=1;i<=n;i++)
		{
			cout<<v[i]<<" ";
		}*/
		cout<<endl;
	}	
}