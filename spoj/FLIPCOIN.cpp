#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define SIZE 100005

struct trees
{
	ll sum;
	int ones;
	int zeros;
};

int lazy[SIZE<<3];
trees tree[SIZE<<3];

trees merge(trees a, trees b)
{
	trees res;
	res.sum=a.sum+b.sum;
	res.ones=a.ones+b.ones;
	res.zeros=a.zeros+b.zeros;
	return res;
}

void build(int node,int start,int end)
{
	if(start==end)
	{
		tree[node].sum=0;
		tree[node].zeros=1;
		tree[node].ones=0;
		return;
	}

	int mid=start+end>>1;
	build(2*node,start,mid);
	build(2*node+1,mid+1,end);
	tree[node]=merge(tree[2*node],tree[2*node+1]);
}

void update(int node,int start,int end,int l,int r)
{
	if(lazy[node]%2==1)
	{
		tree[node].sum+=tree[node].zeros-tree[node].ones;

		int temp=tree[node].zeros;
		tree[node].zeros=tree[node].ones;
		tree[node].ones=temp;

		if(start<end)
		{
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}
		lazy[node]=0;
	}

	if(start>end || start>r || end<l)
		return;
	if(l<=start && end<=r)
	{
		tree[node].sum+=tree[node].zeros-tree[node].ones;

		int temp=tree[node].zeros;
		tree[node].zeros=tree[node].ones;
		tree[node].ones=temp;
		
		if(start<end)
		{
			lazy[2*node]+=1;
			lazy[2*node+1]+=1;
		}
		return;
	}
	int mid=(start+end)>>1;

	update(2*node,start,mid,l,r);
	update(2*node+1,mid+1,end,l,r);

	tree[node]=merge(tree[2*node],tree[2*node+1]);
}

ll query(int node,int start, int end, int l, int r)
{
	if(lazy[node]%2==1)
	{
		tree[node].sum+=tree[node].zeros-tree[node].ones;

		int temp=tree[node].zeros;
		tree[node].zeros=tree[node].ones;
		tree[node].ones=temp;

		if(start<end)
		{
			lazy[2*node]+=lazy[node];
			lazy[2*node+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	
	if(start>end || start>r || end<l)
		return 0;
	
	if(l<=start && end<=r)
	{
		return tree[node].sum;
	}
	int mid=start+end>>1;
	return query(2*node,start,mid,l,r)+query(2*node+1,mid+1,end,l,r);

}

int main()
{
	int n,q;
	scanf("%d %d",&n,&q);

	memset(tree ,0, sizeof(tree));
	memset(lazy ,0, sizeof(lazy));

	build(1,1,n);

	while(q--)
	{
		int c,x,y;
		// int val;
		scanf("%d",&c);
		if(c)
		{
			scanf("%d %d",&x,&y);
			printf("%lld\n", query(1,1,n,x+1,y+1));
		}
		else
		{
			scanf("%d %d",&x,&y);
			update(1,1,n,x+1,y+1);
		}
	}
	return 0;

}