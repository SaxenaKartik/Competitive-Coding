#include <bits/stdc++.h>
using namespace std;
#define SIZE 100005
#define ll long long 
#define INF 1000000000

vector <pair<int, ll> > adj[SIZE];
int n,m,src,dest,tim;
ll dist[SIZE];

void addedge(int x,int y, int d)
{
	adj[x].push_back(make_pair(y,d));
	adj[y].push_back(make_pair(x,d));
}

ll djisktras()
{
	for(int i=0;i<=n;i++)
	{
		dist[i]=INF;
	}
	dist[src]=0;
	priority_queue<pair<int, ll> > q;
	q.push(make_pair(src,0));

	while(!q.empty())
	{
		pair<int, ll> p=q.top();
		q.pop();

		int x=p.first;

		for(int i=0;i<adj[x].size();i++)
		{
			int e=adj[x][i].first;
			ll w=adj[x][i].second;

			if(dist[e]>dist[x]+w)
			{
				dist[e]=dist[x]+w;
				q.push(make_pair(e,dist[e]));
			}
		}
	}
	if(dist[dest]==INF)
	{
		return -1; //if one cannot reach the destination from the source 
	}
	else
	{
		return dist[dest];
	}
}

int main()
{
	ofstream of;
	of.open("AMANPNT output file #2");
	
	int t;
	scanf("%d",&t);

	while(t--)
	{
		scanf("%d%d%d%d%d",&n,&m,&src,&dest,&tim);



		for(int i=0;i<=n;i++)
		{
			adj[i].clear();
		}

		for(int i=1;i<=m;i++)
		{
			int u,v;
			scanf("%d %d", &u,&v);
			addedge(u,v,1);
		}

		if(src==dest) 
		{
			if(tim>=2) //if source and destination is at the same location it will only take 2 time units to complete the painting 
			{
				// printf("YES\n");
				of<<"YES\n";
			}
			continue;
		}

		ll shortest_time = djisktras();

		

		if(shortest_time == -1)
		{
			// printf("NOT POSSIBLE\n");
			of<<"NOT POSSIBLE\n";
		}
		else if(2*shortest_time+2<=tim)
		{
			// printf("YES\n");
			of<<"YES\n";

		}
		else
		{
			// printf("NO\n");
			of<<"NO\n";
		}
	}
}