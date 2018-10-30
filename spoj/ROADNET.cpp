#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 210 
ll a[205][205];
ll b[205][205];
ll mask[205][205];
int main()
{
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		ll n;
		scanf("%lld",&n);
		
		memset(a,INF,sizeof(a));
		memset(mask,0,sizeof(mask));
		for(ll i=1;i<=n;i++)
		{
			for(ll j=1;j<=n;j++)
			{
				ll k;
				scanf("%lld",&k);
				b[i][j]=a[i][j]=k;
			}
		}
			
		for(ll k=1;k<=n;k++)
		{
			for(ll i=1;i<=n;i++)
			{
				for(ll j=1;j<=n;j++)
				{
					if(a[i][j]==a[i][k]+a[k][j] && k!=i && k!=j)
						mask[i][j]=1;

					if(a[i][j]>a[i][k]+a[k][j])
					{
						a[i][j]=a[i][k]+a[k][j];
					}
				}
			}
		}

		//how to print??

		for(ll i=1;i<=n;i++)
		{
			for(ll j=1;j<=n;j++)
			{
				if(a[i][j]<b[i][j])
				{
					continue;
				}
				else if(a[i][j]==b[i][j] && !mask[i][j] && i!=j)
				{
					if(i<j)
						printf("%lld %lld\n",i,j);
					mask[j][i]=1;
				}
				//printf("%lld ", mask[i][j]);
			}
		}
	}
}