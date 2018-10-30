#include <bits/stdc++.h>
using namespace std;
#define ll long long 

vector<ll> v;

int main()
{
	// sievefunc();
	ll a[36];
	ll mul = 1;
	for(int i=0;i<36;i++)
	{
		a[i] = mul;
		mul *= 2;
	}
	for(int i=0;i<=35;i++)
	{
		for(int j=0;j<=35;j++)
		{
			if(i!=j)
			v.push_back(a[i]+a[j]);
		}
	}
	sort( v.begin(), v.end() );
	v.erase( unique( v.begin(), v.end() ), v.end() );


	int t;
	scanf("%d", &t);

	while(t--)
	{
		ll n;
		ll count;
		scanf("%lld", &n);
		long i = 0, temp = 0;
		while(1)
		{
			if(v[i] < n)
			{
				temp = i;
				i++;
				continue;
			}
			break;
		}
		// cout<<v[k-1]<<"\n";
		// if(n==v[k])
		// {
		// 	printf("0\n");
		// }
		// else if(n-v[k-1]<v[k]-n && (n-v[k-1])>=0)
		// {
		// 	printf("%lld\n", n-v[k-1]);
		// }
		// else if(n-v[k-1]>v[k]-n && (v[k]-n)>=0)
		// {
		// 	printf("%lld\n", v[k]-n);
		// }
		ll lb = v[temp];
		ll ub = v[temp+1];
		ll ans = min(abs(n - lb), abs(ub - n));
		cout<<ans<<"\n";
	}	
	return 0;
}