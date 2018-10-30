#include <bits/stdc++.h>
using namespace std;
#define SIZE 110
vector<pair<long long, double> > adj[SIZE];
bool vis[SIZE];
double dist[SIZE];
long long n,m;
// vector<long long>path;

void addedge(long long x,long long y,double p)
{
	adj[x].push_back(make_pair(y,p));
	adj[y].push_back(make_pair(x,p));
}

double max_dijkstra()
{
	memset(dist,0,sizeof(dist));
	// memset(vis,false,sizeof(vis));
	//path.empty();
	dist[1]=1;
	//priority_queue <pair<long long, long long> >q;
	queue<long long>q;
	q.push(1);

	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		// int wei=p.second;

		// if(vis[x]) continue;

		// vis[x]=true;
		// path.push_back(x);
		// if(x==n) break;

		for(long long i=0;i<adj[x].size();i++)
		{
			long long e=adj[x][i].first;
			double w=adj[x][i].second;

			if(dist[e]<dist[x]*w)
			{
				q.push(e);
				dist[e]=dist[x]*w;
			}
		}
	}

	return dist[n]*100;

}

int main()
{
	while(true)
	{
		n=0;m=0;
		scanf("%lld",&n);
		if(n!=0)
		{
			scanf("%lld",&m);

			for(int i=1;i<=n;i++)
			{
				adj[i].clear();
			}

			for(int i=0;i<m;i++)
			{
				long long x=0,y=0;
				double p=0;
				scanf("%lld %lld %lf",&x,&y,&p);
				addedge(x,y,p/100);
			}

			/*for(long long i=1;i<=n;i++)
			{
				for(long long j=0;j<adj[i].size();j+=1)
				{
					cout<<i<<" "<<adj[i][j].first<<" "<<adj[i][j].second<<endl;
				}
			}*/
			double percent;

			percent = max_dijkstra();
			// percent/=pow(100,path.size()-1);

			printf("%.6lf percent\n", percent);

		}
		else
		{
			break;
		}
	}
	return 0;	
}