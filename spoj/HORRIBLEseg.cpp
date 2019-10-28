#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define SIZE 100005

struct trees
{
	ll sum;
};

ll lazy[SIZE<<3];
trees tree[SIZE<<3];

void build(int node,int start,int end)
{
	if(start>end)
		return;
	if(start==end)
	{
		tree[node].sum=0;
		return;
	}
	int mid=(start+end)>>1;

	build(2*node,start,mid);
	build(2*node+1,mid+1,end);

	tree[node].sum=tree[2*node].sum+tree[2*node+1].sum;
}

void update(int node,int start,int end,int l,int r,ll val)
{
	if(lazy[node])
	{
		tree[node].sum+=(end-start+1)*lazy[node];
		if(start<end)
		{
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(start>end || start>r || end<l)
	{
		return;
	}
	if(l<=start && end<=r)
	{
		tree[node].sum+=(end-start+1)*val;
		if(start<end)
		{
			lazy[2*node]+=val;
			lazy[2*node+1]+=val;
		}
		return;
	}
	int mid=start+end>>1;
	update(2*node,start,mid,l,r,val);
	update(2*node+1,mid+1,end,l,r,val);

	tree[node].sum=tree[2*node].sum+tree[2*node+1].sum;
}

ll query(int node,int start,int end,int l,int r)
{
	if(lazy[node])
	{
		tree[node].sum+=(end-start+1)*lazy[node];
		if(start<end)
		{
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(start>end || start>r || end<l)
	{
		return 0;
	}
	if(l<=start && end<=r)
	{
		return tree[node].sum;
	}
	int mid=start+end>>1;
	return query(2*node,start,mid,l,r)+query(2*node+1,mid+1,end,l,r);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(lazy,0,sizeof(lazy));
		memset(tree,0,sizeof(tree));
		int n,m;
		scanf("%d %d",&n,&m);

		build(1,1,n);

		while(m--)
		{
			int c,x,y;
			ll val;

			scanf("%d",&c);
			if(c)
			{
				scanf("%d %d", &x,&y);
				printf("%lld\n",query(1,1,n,x,y));
			}
			else
			{
				scanf("%d%d%lld",&x,&y,&val);
				update(1,1,n,x,y,val);
			}	
		}
	}
	return 0;
}