#include <bits/stdc++.h>
using namespace std;
#define SIZE 10005
#define ll long long 
#define INF 1000000

int n,m;
ll dist[SIZE][SIZE];

void clear()
{
	for(int i=0;i<SIZE;i++)for(int j=0;j<SIZE;j++)dist[i][j]=INF;
	for(int i=0;i<SIZE;i++)dist[i][i]=0;

}

void floyd_warshall()
{
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(dist[i][k]+dist[k][j]<dist[i][j])
					dist[i][j]=dist[i][k]+dist[k][j];
}

int main()
{
	ofstream of;
	of.open("KAUSANDNIHA output file #1");

	int t;
	scanf("%d",&t);

	while(t--)
	{
		scanf("%d %d",&n,&m);

		clear();
		
		for(int i=0;i<m;i++)
		{
			int x,y;
			ll t;
			scanf("%d %d %lld", &x,&y,&t);
			dist[x-1][y-1]=dist[y-1][x-1]=t;
		}		

		floyd_warshall();

		int q;

		/*for(int i=0;i<n;i++)
		{	
			for(int j=0;j<n;j++)
			{
				printf("%lld\n", dist[i][j]);
			}
		}*/

		scanf("%d",&q);

		while(q--)
		{
			int u,v;
			scanf("%d %d", &u,&v);
			if(dist[u-1][v-1]<INF)
				// printf("%lld\n", dist[u-1][v-1]);
				of<<dist[u-1][v-1]<<"\n";
			else
				// printf("-1\n");
				of<<-1<<"\n";
		}

	}
}