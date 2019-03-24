#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define SIZE 100002
vector<pair<int,int> > adj[SIZE];
int n,m,src,dest;

// int flag;

void addedge(ll u, ll v, ll d)
{
	adj[u].push_back(make_pair(v,d));
	adj[v].push_back(make_pair(u,d));
}

void dijkstra()
{
	vector<bool> vis(n,false);
	vector<ll> dist(n,1e9);

	dist[src]=0;

	priority_queue<pair<int, int>, vector<pair<int, int> >,greater<pair<int, int> > >  s;
	s.push(make_pair(0,src));

	while(!s.empty())
	{
		pair<ll,ll> p=s.top();
		s.pop();

		ll x=p.second;

		if(vis[x]) continue;
		vis[x]=true;

		//if(x==dest) break;

		for(int i=0;i<adj[x].size();i++)
		{
			int e=adj[x][i].first;
			//if(e==dest) flag=1;
			int w=adj[x][i].second;

			if(dist[x]+w<dist[e])
			{
				dist[e]=dist[x]+w;
				s.push(make_pair(dist[e],e));
			}
		}
	}
	if(dist[dest]<1e9)
	{
		printf("%lld\n", dist[dest]);
	}
	else
	{
		printf("NONE\n");
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d %d",&n,&m,&src,&dest);

		for(int i=1;i<=n;i++)
		{
			adj[i].clear();
		}

		for(int i=0;i<m;i++)
		{
			int u,v,d;
			scanf("%d %d %d",&u,&v,&d);
			addedge(u,v,d);
		}

		dijkstra();
	}

	return 0;
}