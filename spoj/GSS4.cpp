//not using lazy but tackling the nodes which are 1 for optimisation

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SIZE 100100
int n;

struct trees
{
	ll sum;
	bool flag;
};

trees tree[SIZE<<3];
ll a[SIZE];

trees merge(trees a, trees b)
{
	trees res;
	res.sum=a.sum+b.sum;
	res.flag=(a.flag && b.flag)?true:false;
	return res;
}

void build(int node,int start,int end)
{
	if(start==end)
	{
		tree[node].sum=a[start];
		if(a[start]==1)
		{
			tree[node].flag=true;
		}
		else
		{
			tree[node].flag=false;
		}
		return;
	}
	int mid=(start+end)>>1;

	int p1=node<<1;
	int p2=node<<1|1;

	build(p1,start,mid);
	build(p2,mid+1,end);

	tree[node]=merge(tree[p1],tree[p2]);
}

ll query(int node,int start,int end,int l,int r)
{
	/*if(l>end || r<start)
		return 0;
	if(l<=start && end<=r)
	{
		return tree[node].sum;
	}
	int mid=(start+end)>>1;
	int p1=node<<1;
	int p2=node<<1|1;

	return query(p1,start,mid,l,r)+query(p2,mid+1,end,l,r);*/

	if(start==l && end==r)
	{
		return tree[node].sum;
	}
	int mid=(start+end)>>1;

	int p1=node<<1;
	int p2=node<<1|1;

	if(r<=mid) return query(p1,start,mid,l,r);
	else if(l>mid) return query(p2,mid+1,end,l,r);
	else
	{
		return query(p1,start,mid,l,mid)+query(p2,mid+1,end,mid+1,r);
	}
}

void update(int node,int start,int end,int l,int r)
{
	if(l>end || r<start)
		return;
	if(tree[node].flag)
		return;

	if(start==end)
	{
		a[start]=(sqrt(a[start]));
		tree[node].sum=a[start];
		if(a[start]==1)
		{
			tree[node].flag=true;
		}
		return;
	}
	int mid=(start+end)>>1;

	int p1=node<<1;
	int p2=node<<1|1;

	if(r<=mid)
	{
		update(p1,start,mid,l,r);
	}
	else if(l>mid)
	{
		update(p2,mid+1,end,l,r);
	}
	else	
	{
		update(p1,start,mid,l,r);
		update(p2,mid+1,end,l,r);
	}
	tree[node]=merge(tree[p1],tree[p2]);
}

int main()
{
	int count=1;
	while(scanf("%d",&n)!=EOF)
	{
		printf("Case #%d:\n",count);
		// ll a[n];
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		build(1,1,n);

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
				printf("%lld\n", query(1,1,n,x,y));
			}
			else
			{
				update(1,1,n,x,y);
			}
		}
		count++;
		printf("\n");
	}
	return 0;
}