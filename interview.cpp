#include <bits/stdc++.h>
using namespace std;
#define SIZE 20005
#define ll long long 

ll a[SIZE];
ll b[SIZE];
ll c[SIZE][SIZE];

int main()
{
	int n;
	scanf("%d", &n);

	for(ll i=1;i<=n;i++)
	{
		scanf("%lld", &a[i]);
	}

	for(ll i=1;i<=n;i++)
	{
		scanf("%lld", &b[i]);
	}

	for(ll i=1;i<n;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			if((j-i)>=a[i]+b[j] && i<j)
			{
				c[i][j]=1;
			}
		}
	}


	for(ll i=1;i<n;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			printf("%lld %lld %lld\n",i,j,c[i][j]);
		}
	}

	ll count=0;
	for(ll i=1;i<n;i++)
	{
		for(ll j=i+1;j<=n;j++)
		{
			if(c[i][j] && i<j)
			{
				// printf("%lld %lld\n",i,j);
				count++;
			}
			/*else
			{
				for(ll k=i+1;k<=n;k++)
					if(c[i][k] && c[k][j])
						count++;
			}*/
		}
	}

	// printf("%lld\n",count);
}