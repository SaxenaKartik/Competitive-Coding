#include <bits/stdc++.h>
using namespace std;
#define SIZE 100100
#define ll long long 

ll BIT[SIZE];
ll a[SIZE];
bool flag[SIZE];
int n;
int root[SIZE];

void update(int x,ll val)
{
	for(;x<=n;x+=x&-x)
	{
		BIT[x]+=val;
	}
}

ll query(int x)
{
	ll sum=0;
	for(;x>0;x-=x&-x)
	{
		sum+=BIT[x];
	}
	return sum;
}

int find(int i)
{
	if(root[i]!=i)
	{
		root[i]=find(root[i]);
	}
	return root[i];
}

void modify(int x,int y)
{
	/* Basic Idea :

	iterate from x to y and update each element a to sqrt(a)
	i be the index between x and y
	update(i,-a[i])
	a[i]=floor(sqrt(a[i]))
	update(i,a[i])
	if(a[i]==1) set a flag for ith index*/

	/* 

	simply using a flag for the ith index is giving TLE 

	for(int i=x;i<=y;i++)
	{
		if(!flag[i])
		{
			update(i,-a[i]);
			a[i]=floor(sqrt(a[i]));
			update(i,a[i]);
			if(a[i]==1) flag[i]=true;
		}
	}*/

	/*
	Modified Idea : 
		
	recursively find the next index which does not have it's square root as one using an array root
	it stores values at index i = i if square root of the ith index is not 1 
	else it stores value at index i = i+1;

	*/

	int k=find(x);

	ll s,sq;

	while(k<=y)
	{
		s=query(k)-query(k-1);
		if(s!=1)
		{
			update(k,-s);
			sq=sqrt(s);
			update(k,sq);

			if(sq==1)
			{
				root[k]=k+1;
			}
		}
		k=find(k+1);
	}
}

int main()
{
	int count=1;
	while(scanf("%d",&n)!=EOF)
	{
		printf("Case #%d:\n", count);

		memset(BIT,0,sizeof(BIT));
		memset(flag,false,sizeof(flag));

		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			update(i,a[i]);
			root[i]=i;
		}

		root[n+1]=n+1;

		int q;
		scanf("%d",&q);

		while(q--)
		{
			int c,x,y;
			scanf("%d%d%d",&c,&x,&y);

			if(x>y)
			{
				int temp=x;
				x=y;
				y=temp;
			}

			if(c)
			{
				// printf("%lld\n", query(1,1,n,x,y));
				printf("%lld\n",query(y)-query(x-1));
			}
			else
			{
				// update(1,1,n,x,y);
				modify(x,y);
			}
		}
		count++;
		printf("\n");
	}
}