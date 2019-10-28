//using segment and offline query : individual property of elements in the query

#include <bits/stdc++.h>
using namespace std;
#define SIZE 30005

int BIT[SIZE];
int n,qu;

struct trees 
{
	int sum;
};

trees tree[SIZE<<3];

struct kquery
{
	int l;
	int r;
	int k;
	int num;
}q[200005];

struct num
{
	int index;
	int val; 
}a[SIZE];

trees merge(trees a, trees b)
{
	trees res;
	res.sum=a.sum+b.sum;
	return res;
}

bool cmp(num a, num b)
{
	return a.val>b.val;
}

bool cmp1(kquery a,kquery b)
{
	if(a.k==b.k)
	{
		return a.r>b.r;
	}
	return a.k>b.k;
}

/*void build(int node,int start,int end)
{
	if(start==end)
	{
		tree[node].sum=0;
		return;
	}
	int mid=start+end>>1;
	build(2*node,start,mid);
	build(2*node+1,mid+1,end);
	tree[node]=merge(tree[2*node],tree[2*node+1]);
}
*/
void update(int node,int start,int end,int x)
{
	if(start==x && end==x)
	{
		tree[node].sum+=1;
		return;
	}
	if(start>end || start>x || end<x)
		return;
	int mid=start+end>>1;
	update(2*node,start,mid,x);
	update(2*node+1,mid+1,end,x);
	tree[node]=merge(tree[2*node],tree[2*node+1]);
}

trees query(int node,int start,int end, int l, int r)
{
	if(start>end || start>r || l>end)
		return (trees){0};
	if(l<=start && end<=r)
		return tree[node];
	int mid=start+end>>1;
	return merge(query(2*node,start,mid,l,r),query(2*node+1,mid+1,end,l,r));
}

int main()
{
	scanf("%d",&n);

	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].val);
		a[i].index=i;
		//BIT[i]=0;
	}
	sort(a+1,a+1+n,cmp);

	scanf("%d",&qu);

	int result[qu+5];

	for(int i=1;i<=qu;i++)
	{
		scanf("%d %d %d",&q[i].l,&q[i].r,&q[i].k);
		q[i].num=i;
	}

	sort(q+1,q+1+qu,cmp1);

	int j=1;
	for(int i=1;i<=qu;i++)
	{
		while(j<=n && a[j].val>q[i].k)
		{
			update(1,1,n,a[j].index);
			j++;
		}
		result[q[i].num]=query(1,1,n,q[i].l,q[i].r).sum;
	}

	for(int i=1;i<=qu;i++)
	{
		printf("%d\n", result[i]);
	}
	
	return 0;
}