#include <bits/stdc++.h>
using namespace std;
#define SIZE 100005
#define ll long long 

struct trees
{
	ll max,maxsum;
};

trees tree[SIZE<<3];

trees merge(trees a,trees b)
{
	trees res;
	res.max=max(a.max,b.max);
	res.maxsum=max(max(a.maxsum,b.maxsum),(a.max+b.max));
	return res;
}

void build(int node,int start,int end)
{
	if(start==end)
	{
		int x;
		scanf("%d",&x);
		tree[node].max=tree[node].maxsum=x;
		return;
	}

	int mid=(start+end)>>1;
	build(2*node,start,mid);
	build(2*node+1,mid+1,end);

	tree[node]=merge(tree[2*node],tree[2*node+1]);
}

void update(int node,int start, int end, int x, int val)
{
	if(start==end)
	{
		tree[node].max=tree[node].maxsum=val;
	}
	else
	{
		int mid=(start+end)>>1;

		if(start<=x && x<=mid)
		{
			update(2*node,start,mid,x,val);
		}
		else
		{
			update(2*node+1,mid+1,end,x,val);
		}
		tree[node]=merge(tree[2*node],tree[2*node+1]);
	}
}

trees query(int node,int start,int end, int l,int r)
{
	if(start==l && end==r)
	{
		return tree[node];
	}
	int mid=(start+end)>>1;
	int p1=node<<1;
	int p2=node<<1|1;

	if(r<=mid) return query(p1,start,mid,l,r);
	else if(l>mid) return query(p2,mid+1,end,l,r);
	else return (merge(query(p1,start,mid,l,mid),query(p2,mid+1,end,mid+1,r)));
}

int main()
{
	int n;
	if(scanf("%d",&n))
	{
		build(1,1,n);
	}

	int q;
	scanf("%d",&q);
	while(q--)
	{
		char c;
		int x,y;
		cin>>c;
		scanf("%d%d",&x,&y);
		if(c=='U')
		{
			update(1,1,n,x,y);
		}
		else if(c=='Q')
		{
			printf("%lld\n", query(1,1,n,x,y).maxsum);
		}
	}

}