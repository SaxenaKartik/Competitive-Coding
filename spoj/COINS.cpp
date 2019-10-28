#include <bits/stdc++.h>
using namespace std;
#define ll long long 

ll n;
map<int,ll>v;

ll maxdollars(ll n)
{
	if(n<12) return n;
	if(v[n]) return v[n];
	return v[n]=max(v[n],maxdollars(n/2)+maxdollars(n/3)+maxdollars(n/4));
}

int main()
{
	while(scanf("%lld", &n)!=EOF)
	{
		printf("%lld\n",maxdollars(n));	
	}
}