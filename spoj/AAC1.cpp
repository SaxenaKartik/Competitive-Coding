#include <bits/stdc++.h>
using namespace std;	
long long int a[10000][10000];
bool vis[10000];



int main()
{
	long long int t;
	cin>>t;
	while(t--)
	{
		long long int n,m,x,y;
		cin>>n>>m;

		memset(a,2,sizeof(a));		
		memset(vis,false,sizeof(vis));

		for(long long int i=0;i<m;i++)
		{
			cin>>x>>y;
			a[x-1][y-1]=1;
			a[y-1][x-1]=1;
		}

		// stack<int> p;
		long long int dist[n];
		memset(dist,2,sizeof(dist));
		
		long long int min_index=0;
		dist[0]=0;

		while(min_index!=n-1)
		{
			long long int index=min_index;
			vis[index]=true;

			for(long long int i=0;i<n;i++)
			{
				if(!vis[i])
				{
					dist[i]=(dist[index]+a[index][i])>dist[i]?dist[i]:(dist[index]+a[index][i]);
					// cout<<dist[i]<<endl;
				}
			}

			/*for(int i=0;i<n;i++)
			{
				cout<<dist[i]<<" ";
			}
			break;*/

			long long int min=INT_MAX;
			for(long long int i=0;i<n;i++)
			{
				if(!vis[i])
				{
					if(dist[i]<min)
					{
						min=dist[i];
						min_index=i;
					}
				}
			}
			/*cout<<min_index<<endl;
			break;*/
		}
		
		cout<<dist[n-1]<<endl;	
	}
}