#include <bits/stdc++.h>
using namespace std;
#define SIZE 1000002

vector <pair<long long int,long long int> > adj[SIZE];
// long long bit[SIZE];
queue<long long int> q;
bool vis[SIZE];

void addedge(int u,int v, int weight)
{
	adj[u].push_back(make_pair(v,weight));
	adj[v].push_back(make_pair(u,weight));
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long n,r,m;
		int flag=0;
		scanf("%lld %lld %lld",&n,&r,&m);

		for(int i=0;i<r;i++)
		{
			adj[i].clear();
		}

		for(int i=0;i<r;i++)
		{
			long long x,y;
			scanf("%lld %lld",&x,&y);			
			addedge(x,y,1);
		}

		long long sum=0;
		// memset(bit,1,sizeof(bit));
		memset(vis,false,sizeof(vis));

		for(int i=0;i<m;i++)
		{
			long long b;
			long long s;

			scanf("%lld %lld",&b,&s);
			
			//bit[b]|(1<<b);
			while(!q.empty())
				q.pop();

			if(vis[b])
			{
				flag=1;
				cout<<"No\n";
				break;
			}

			q.push(b);
			vis[b]=true;
			int level=0;
			q.push(0);
			while(s)
			{
				long long p=q.front();
				q.pop();
				if(p==0){
					s--;
					q.push(0);
				}
				else
				{
					for(int i=0;i<adj[p].size();i++)
					{
						int k=adj[p][i].first;
						if(!vis[k])
						{
							vis[k]=true;
							//bit[p]|(1<<k);
							q.push(k);
						}
					}
				}
			}

		}
		for(int i=1;i<=n;i++)
			{
				sum+=vis[i];
			}

		// cout<<sum<<endl;
		if(flag==0){
			if(sum==n)
			{
				cout<<"Yes\n";
			}
			else
			{
				cout<<"No\n";
			}
		}
	}
}