#include <bits/stdc++.h>
using namespace std;
#define ll long long 

ll dp[2005][2005];
ll weight[2005];
ll value[2005];

int main()
{
	ll S,N,x,y;
	cin>>S>>N;
	for(ll i=1;i<=N;i++)
	{
		scanf("%lld %lld", &weight[i], &value[i]);
	}

	dp[0][0]=0;

	for(ll i=1;i<=N;i++)
	{
		for(ll w=1;w<=S;w++)
		{
			if(weight[i]<=w)
				dp[i][w]=max(dp[i-1][w-weight[i]]+value[i], dp[i-1][w]);
			else
				dp[i][w]=dp[i-1][w];
		}
	}

	printf("%lld\n",dp[N][S]);
}	