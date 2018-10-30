#include <bits/stdc++.h>
using namespace std;
#define SIZE 100100
vector<pair<int,long long> >graph[SIZE];
long long int dp[SIZE]={0};
long long int l[SIZE]={0};
long long int r[SIZE]={0};

void rootat(int u, int prev)
{
	for(int i=0;i<graph[u].size();i++)
	{
		int v=graph[u][i].first;
		if(v==prev)
			graph[u].erase(graph[u].begin()+i);
	}
	for(int i=0;i<graph[u].size();i++)
	{
		rootat(graph[u][i].first,u);
	}
}

void dfs1(int u,int prev)
{
	long long int maximum=0;
	for(int i=0;i<graph[u].size();i++)
	{
		int v=graph[u][i].first;
		long long int w=graph[u][i].second;
		if(v!=prev)
		{
			dfs1(v,u);
			maximum=max(maximum,dp[v]+w);
		}
	}
	dp[u]=maximum;
}

void dfs2(int u,int prev,long long int up)
{
	dp[u]=max(dp[u],up);
	int k=graph[u].size();
	for(int i=0;i<k;i++)
	{
		int v=graph[u][i].first;
		long long int w=graph[u][i].second;
		if(i==0)
			l[v]=dp[v]+w;
		else
		{
			int pr=graph[u][i-1].first;
			l[v]=max(l[pr],dp[v]+w);
		}
	}

	for(int i=k-1;i>=0;i--)
	{
		int v=graph[u][i].first;
		long long int w=graph[u][i].second;
		if(i==k-1)
			r[v]=dp[v]+w;
		else
		{
			int nxt=graph[u][i+1].first;
			r[v]=max(r[nxt],dp[v]+w);
		}
	}

	for(int i=0;i<k;i++)
	{
		int v=graph[u][i].first;
		long long int w=graph[u][i].second;
		long long int best=up;

		if(i!=0)
		{
			int pr=graph[u][i-1].first;
			best=max(best, l[pr]);
		}

		if(i!=k-1)
		{
			int nxt=graph[u][i+1].first;
			best=max(best, r[nxt]);
		}

		dfs2(v,u,best+w);
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			dp[i]=l[i]=r[i]=0;
			graph[i].clear();
		}

		for (int i = 1; i < n; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            graph[u].push_back(make_pair(v, w));
            graph[v].push_back(make_pair(u, w));
        }

        rootat(1,-1);
        dfs1(1,-1);
		dfs2(1,-1,0);

		for (int i = 1; i <= n; i++)
            printf("%lld ", dp[i]);
        printf("\n");

	}
	return 0;
}