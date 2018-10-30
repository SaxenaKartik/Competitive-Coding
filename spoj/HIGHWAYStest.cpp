#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SIZE 100002
#define INF 1000000000
vector<pair<ll,ll> >adj[SIZE];
int n,m,src,dest;
ll dist[SIZE];

void addedge(ll u,ll v,ll d)
{
	adj[u].push_back(make_pair(v,d));
	adj[v].push_back(make_pair(u,d));
}

void dijsktra()
{
	for(int i=0;i<=n;i++)
	{
		dist[i]=INF;
	}
	dist[src]=0;
	priority_queue<pair<ll,ll> >q;
	q.push(make_pair(src,0));

	while(!q.empty())
	{	
		pair<ll,ll> p=q.top();
		q.pop();

		int x=p.first;

		for(int i=0;i<adj[x].size();i++)
		{
			int e=adj[x][i].first;
			int w=adj[x][i].second;

			if(dist[e]>dist[x]+w)
			{
				dist[e]=dist[x]+w;
				q.push(make_pair(e,dist[e]));
			}
		}
	}
	if(dist[dest]==INF)
	{
		printf("NONE\n");
	}
	else
	{
		printf("%lld\n", dist[dest]);
	}
}


int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		scanf("%d %d %d %d",&n,&m,&src,&dest);

		for(int i=0;i<=n;i++)
		{
			adj[i].clear();
		}

		for(ll i=0;i<m;i++)
		{
			int u,v,d;
			scanf("%d %d %d",&u,&v,&d);
			addedge(u,v,d);
		}

		dijsktra();
	}
	return 0;
}