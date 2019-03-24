#include <bits/stdc++.h>
using namespace std;
#define SIZE 100002
#define ll long long 

int n;
ll BIT1[SIZE];
ll BIT2[SIZE];

void update1(int x,ll val)
{
	for(;x<=100001;x+=x&-x)
	{
		BIT1[x]+=val;
	}
}

void update2(int x,ll val)
{
	for(;x<=100001;x+=x&-x)
	{
		BIT2[x]+=val;
	}
}

ll query1(int x)
{
	ll sum=0;
	for(;x>0;x-=x&-x)
	{
		sum+=BIT1[x];
	}
	return sum;
}

ll query2(int x)
{
	ll sum=0;
	for(;x>0;x-=x&-x)
	{
		sum+=BIT2[x];
	}
	return sum;
}



int main()
{
	ll t;
	scanf("%lld",&t);
	
	while(t--)
	{
		int type;
		int c,p,q;
		ll v;
		memset(BIT1,0,sizeof(BIT1));
		memset(BIT2,0,sizeof(BIT2));
		
		scanf("%d %d",&n,&c);
		while(c--)
		{
			scanf("%d %d %d",&type,&p,&q);
			if(type==0)
			{
				scanf("%lld",&v);
				
				update1(p,v);
				update1(q+1,-v);
				update2(p,(long long)v*(p-1));
				update2(q+1,-(long long)v*q);
			}
			else
			{
				ll ans = (query1(q)*q-query2(q)) - (query1(p-1)*(p-1)-query2(p-1));
				printf("%lld\n", ans);
			}
		}

	}

	return 0;
}