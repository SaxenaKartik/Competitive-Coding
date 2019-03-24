#include <bits/stdc++.h>
using namespace std;
// #define MAX 100005
int m,n; //matrix of m by n
char a[105][105];
int vis[105][105];
int dist[105][105];

struct coordinate
{
	int row;
	int column;
};

coordinate start;
coordinate dest;

int X[]={1,0,0,-1};
int Y[]={0,1,-1,0};

bool safe(int x, int y)
{
    if (x > m || y> n || x<1 || y<1)
       return false;
    if (a[x][y] == '*')
       return false;
    return true;
}

int bfs()
{
	queue<coordinate>q;
	q.push(start);

	dist[start.row][start.column]=0;
	vis[start.row][start.column]=1;

	while(!q.empty())
	{
		coordinate k=q.front();
		q.pop();
		// vis[k.row][k.column]=1;	

		for(int i=0;i<4;i++)
		{
			int x=k.row+X[i];
			int y=k.column+Y[i];

			if(safe(x,y))
			{
				if(vis[x][y])
					continue;

				// printf("%d %d\n",x,y);

				vis[x][y]=1;
				dist[x][y]=dist[k.row][k.column]+1;
				q.push((coordinate){x,y});
			}
		}
	}

	if(dist[dest.row][dest.column]!=0)
		return dist[dest.row][dest.column];
	else
		return -1;
	// return dist[end.row][end.column];
}

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		memset(vis,0,sizeof(vis));
		memset(a,0,sizeof(a));
		memset(dist,0,sizeof(dist));
		scanf("%d %d",&m,&n);
		for(int i=1;i<=m;i++)
		{
			for (int j=1;j<=n;j++)
			{
				/* code */
				cin>>a[i][j];
				if(a[i][j]=='$')
				{
					start.row=i;
					start.column=j;
				}
				if(a[i][j]=='#')
				{
					dest.row=i;
					dest.column=j;
				}
			}
		}

		int count = bfs();
		printf("%d\n", count);
	}
}