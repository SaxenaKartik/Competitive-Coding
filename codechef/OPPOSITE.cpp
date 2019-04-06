#include <bits/stdc++.H>
using namespace std;
#define SIZE 300005
#define ll long long 

int n;
ll d[SIZE];


int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		memset(adj,0,sizeof(adj));
		ll C=0,A=0,Ccount=0,Acount=0,diff=0,flag=0;
		scanf("%d", &n);
		if(n%2==1)
			printf("NO\n");
		else
		{
			for(int i=1;i<=n;i++)
			{
				scanf("%d",%d[i]);
			}

			for(int i=1;i<=n/2+1;i++)
			{
				if(d[i]>0 && d[n-i+1]==-1)
				{
					d[n-i+1]=d[i];
					C+=d[i];
					A+=d[i];
				}
				else if(d[n-i+1]>0 && d[i]==-1)
				{
					d[i]==-1;
					C+=d[i];
					A+=d[i];
				}
				else if(d[i]==-1 && d[n-i+1]==-1)
				{
					d[i]==1;
					d[n-i+1]==1;
					C+=d[i];
					A+=d[i];
				}
				else
				{
					if(C==A)
					{
						printf("YES\n");
						flag=1;
					}
					else
					{
						flag=0;
						printf("NO\n");
						break;
					}
				}
			}
			if(flag==1)
			{
				for(int i=1;i<=n;i++)
				{
					scanf("%d",%d[i]);
				}
			}	
		}
	}
	return 0;
}