#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[1005][1005];
int row[1005];
int column[1005];
int res[1005][1005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(row,0,sizeof(a));
		memset(column,0,sizeof(a));
		memset(res,0,sizeof(a));


		scanf("%d %d",&n,&m);

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				scanf("%1d", &a[i][j]);
				if(a[i][j]==1)
				{
					row[i]=1;
					column[j]=1;
					res[i][j]=5;
				}
			}
		}

		for(int i=0;i<n;i++)
		{
			if(row[i]==1)
			{
				for(int j=0;j<m;j++)
				{
					if(res[i][j]==0)
						res[i][j]=1;
				}
			}
		}

		for(int i=0;i<m;i++)
		{
			if(column[i]==1)
			{
				for(int j=0;j<n;j++)
				{
					if(res[j][i]==0)
					res[j][i]=1;
				}
			}
		}

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(res[i][j]==0)
					res[i][j]=2;
			}
		}

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(res[i][j]==5)
					res[i][j]=0;
			}
		}

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				printf("%d ",res[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}