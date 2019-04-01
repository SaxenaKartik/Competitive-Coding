//solving ACC1 using min priority queue
#include <bits/stdc++.h>
using namespace std;
#define SIZE 100002

vector <pair <int,int> > adj[SIZE];
int dist[SIZE];
bool vis[SIZE];

void addedge(int u,int v, int weight)
{
	adj[u].push_back(make_pair(v,weight));
	adj[v].push_back(make_pair(u,weight));
}

void dijkstra()
{
	memset(vis,false,sizeof(vis));
	dist[1]=0;
	multiset<pair <int, int> > s;

	s.insert(make_pair(0,1));

	while(!s.empty())
	{
		pair<int, int > p = *s.begin();
		s.erase(s.begin());

		int x=p.second;
		int wei=p.first;

		if(vis[x]) continue;

		vis[x]=true;

		for(int i=0;i<adj[x].size();i++)
		{
			int e=adj[x][i].first;
			int w=adj[x][i].second;

			if(dist[x]+w<dist[e])
			{
				dist[e]=dist[x]+w;
				s.insert(make_pair(dist[e],e));
			}
		}
	}
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		 int n,m;
		 cin>>n>>m;

		for(int i=0;i<n;i++)
		{
			adj[i].clear();	
		}
		memset(dist,1000000,sizeof(dist));	
		 for(int i=0;i<m;i++)
		 {
		 	int x,y;
		 	cin>>x>>y;
		 	addedge(x,y,1);
		 }

		 /*for(int i=0;i<n;i++)
		 {
		 	for(int j=0;j<adj[i].size();j++)
		 	{
		 		cout<<i<<" "<<adj[i][j].first<<" "<<adj[i][j].second<<endl	;
		 	}
		 	cout<<endl;
		 }*/

		 dijkstra();
		 /*for(int i=0;i<n;i++)
		 {
		 	cout<<dist[i+1]<<" ";
		 }*/

		 cout<<dist[n]<<endl;
	}
}