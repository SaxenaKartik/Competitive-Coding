#include <bits/stdc++.h>
using namespace std;
#define SIZE 30005
struct trees
{
	int k,s;
};

trees tree[SIZE<<3];

string s;

trees merge(trees a,trees b)
{
	trees res;
	int n=min(a.k,b.s);
	res.k=a.k+b.k-n;
	res.s=a.s+b.s-n;

	return res;
}

void build(int node, int start, int end)
{
	if(start==end)
	{
		if(s[start-1]=='(')
		{
			tree[node].k=1;
			tree[node].s=0;
		}
		else
		{
			tree[node].s=1;
			tree[node].k=0;
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

void update(int node,int start, int end, int x)
{
	if(start==end)
	{
		if(s[x-1]=='(')
		{
			s[x-1]=')';
			tree[node].k=0;
			tree[node].s=1;
		}
		else if(s[x-1]==')')
		{
			s[x-1]='(';
			tree[node].k=1;
			tree[node].s=0;
		}
	}
	else
	{
		int mid=(start+end)>>1;
		int p1=node<<1;
		int p2=node<<1|1;
		
		if(start<=x && x<=mid)
		{
			update(p1,start,mid,x);
		}
		else
		{
			update(p2,mid+1,end,x);
		}
		tree[node]=merge(tree[p1],tree[p2]);
	}
}

trees query(int node,int start,int end,int l,int r)
{
	if(start==l && end==r)
	{
		return tree[node];
	}
	int mid=(start+end)>>1;

	int p1=node<<1;
	int p2=node<<1|1;

	if(r<=mid)
	{
		return query(p1,start,mid,l,r);
	}
	else if(l>mid)
	{
		return query(p2,mid+1,end,l,r);
	}
	else return (merge(query(p1,start,mid,l,mid),query(p2,mid+1,end,mid+1,r)));
}

int main()
{
	int u=10;
	while(u--)
	{
		printf("Test %d:\n",10-u);
		int n;
		scanf("%d",&n);

		cin>>s;

		build(1,1,n);

		int m;
		scanf("%d",&m);
		while(m--)
		{
			int k;
			scanf("%d",&k);

			if(k)
			{
				update(1,1,n,k);
			}
			else
			{
				trees p=query(1,1,n,1,n);
				if(p.k==0 && p.s==0)
					printf("YES\n");
				else
					printf("NO\n");
			}
		}
	}
	return 0;
}