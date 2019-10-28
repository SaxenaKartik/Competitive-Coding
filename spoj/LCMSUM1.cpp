//precomputing the answer

#include <bits/stdc++.h>
using namespace std;

long long int res[1000010];
long long int phi[1000010];

void precal(int n)
{
	for(long long i=1;i<=n;i++)
	{
		phi[i]=i;
	}
	for(long long i=2;i<=n;i++)
	{
		if(phi[i]==i)
		{		
			for(int j=i;j<=n;j+=i)
			{
				phi[j]/=i;
				phi[j]*=i-1;

				// cout<<"i = "<<i<<"phi[i] = "<<phi[i]<<"\n";
			}
		}
	}

	for(long long int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j+=i)
		{
			res[j]+=(phi[i]*i);
			// cout<<"j = "<<j<<"res[j] = "<<res[j]<<"\n";
		}
	}
}





int main()
{
	precal(1000000);
	long long int t;
	scanf("%lld",&t);
	while(t--)
	{
		long long int n;
		scanf("%lld",&n);

		long long int ans=res[n]+1;
		ans*=n;
		ans/=2;

		printf("%lld\n",ans);
	}

	return 0;
}
