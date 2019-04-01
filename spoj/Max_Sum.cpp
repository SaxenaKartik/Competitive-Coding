#include <bits/stdc++.h>
using namespace std;
#define ll long long 


ll sieve[100000005];


void sievefunc()
{
	for(ll i=2;i<=100000000;i++)
	{
		if(sieve[i]==0)
		{
			// sieve[i]=i;
			for(ll j=i;j*j<=100000000;j+=i)
			{
				if(sieve[j]==0)
					sieve[j]=i;
			}
		}	
	}
}

vector<ll> primefactors(int n)
{
	vector<ll> v;
	ll k=sieve[n];

	v.push_back(k);

	while(n!=k)
	{
		n/=k;
		k=sieve[n];
		v.push_back(k);
	}
	return v;
}

int main()
{
	sievefunc();
	int t;
	scanf("%d", &t);

	while(t--)
	{
		ll x;
		ll k;
		ll sum=0;

		scanf("%lld %lld",&x,&k);

		if(k==1)
		{
			printf("%lld\n", x);
		}
		else if(sieve[x]==x && k>1)
		{
			printf("-1\n");
		}
		else if(k>x)
		{
			printf("-1\n");
		}
		else
		{
			vector<ll> v=primefactors(x);

			/*for(int i=0;i<v.size();i++)
			{
				printf("%d\n", v[i]);
			}*/
			if(k>v.size())
				printf("-1\n");
			else
			{
				
				for(int i=0;i<(k-1);i++)
				{
					sum+=v[i];
					x/=v[i];
				}
				if(x!=1)
					sum+=x;
				printf("%lld\n", sum);
			}
		}
	}
	return 0;
}