#include<bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#define debug(x) cout << "debug: " << #x " = " << x << endl
#define ll long long

int n,t;
int a[51];
// int vis[51];
int32_t main()
{
	// fast_io();
	
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		// memset(vis,0,sizeof(vis));
		// memset(a,0,sizeof(a));
		for (int i = 1; i <= n; i++)
		{
			scanf("%d",&a[i]);
		}

		if(n==1)
		{
			// cout<<0<<endl;
			printf("0\n");
			// cout<<a[1]<<endl;
			printf("%d\n",a[1]);
			continue;
		}	
				
		int connected=1;
		int flag=0;
		// int sum=0;
		for(int i=1;i<=n;i++)
		{
			flag=0;
			for(int j=1;j<=n;j++)
			{
				if(__gcd(a[i],a[j])==1)
				{
					flag=1;
					break;
				}	
			}
			if(flag==1)
			{
				continue;
			}	
			else
			{
				connected=0;
				break;
			}
		}

		/*for(int i=2;i<=50;i++)
		{
			if(vis[i]) sum+=1;
		}
	*/
		if(connected)
		{
			printf("0\n");
			for(int i=1;i<=n;i++)
			{
				// cout<<a[i]<<" ";
				printf("%d ",a[i]);	
			}
			// cout<<endl;
			printf("\n");
		}
		else
		{
			// cout<<1<<endl;
			printf("1\n");
			if(a[1]==47)
			{
				a[1]=43;
			}
			else
			{
				a[1]=47;
			}
			for(int i=1;i<=n;i++)
			{
				printf("%d ",a[i]);	
			}
			// cout<<endl;
			printf("\n");
		}
	}
	return 0;
}	
