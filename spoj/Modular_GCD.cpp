#include <bits/stdc++.h>  
using namespace std;
#define ll long long 
const int M = 1e9+7;
ll A,B,N,d,x,y;

ll prod(ll a,ll b,ll m) //returns (a*b)%m
{
	ll res=0;
	while(b)
	{
		if(b&1)
			res=(res+a)%m;
		a=(a+a)%m;
		b>>=1;
	}
	return res;
}

ll funcpow(ll a, ll b, ll mod=M) // returns (a^b)
{
	ll res=1;
	while(b)
	{
		if(b&1)
			res=prod(res, a, mod);
		a=prod(a, a, mod);
		b>>=1;
	}
	return res;
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%lld %lld %lld", &A, &B, &N);
		if(A==B)
		{
			cout<<(funcpow(A,N)+funcpow(B,N))%M<<endl;
		}
		else 
		{
			ll d=(funcpow(A,N,A-B)+funcpow(B,N,A-B))%(A-B);
			cout<<__gcd(d,A-B)<<endl;
		}
	}
}