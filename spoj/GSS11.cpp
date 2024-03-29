#include <bits/stdc++.h>
using namespace std;
#define SIZE 50007
struct trees
{
	int maxsum;
	int sum;
	int prefixsum;
	int suffixsum;
};

trees tree[SIZE<<3];

trees merge(trees a,trees b)
{
	trees res;
	
	res.sum=a.sum+b.sum;
	res.prefixsum=max(a.prefixsum,a.sum+b.prefixsum);
	res.suffixsum=max(b.suffixsum,b.sum+a.suffixsum);
	res.maxsum=max(max(a.maxsum,b.maxsum),(a.suffixsum+b.prefixsum));
	

	return res;
}

void build(int node,int start,int end)
{
	if(start==end)
	{
		int x;
		scanf("%d",&x);
		tree[node].sum=tree[node].prefixsum=tree[node].suffixsum=tree[node].maxsum=x;
		return ;
	}

	int p1=node<<1;
	int p2=node<<1|1;

	int mid=(start+end)>>1;

	build(p1,start,mid);
	build(p2,mid+1,end);

	tree[node]=merge(tree[p1],tree[p2]);
}

trees query(int node,int start,int end, int l, int r)
{
	if(start==l && end==r) return tree[node];

	int p1=node<<1;
	int p2=node<<1|1;

	int mid=(start+end)>>1;

	if(r<=mid) return query(p1,start,mid,l,r);
	else if(l>mid) return query(p2,mid+1,end,l,r);
	else
	{
		return merge(query(p1,start,mid,l,mid),query(p2,mid+1,end,mid+1,r));
	}
}

int main()
{
	int n;
	if(scanf("%d",&n)==1)
	{
		build(1,1,n);
	}
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n", query(1,1,n,x,y).maxsum);
	}
}