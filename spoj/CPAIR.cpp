//still TLE

#include <bits/stdc++.h>
using namespace std;
#define SIZE 100005
int n,qu;

struct num
{
	int val,index;
}a[SIZE];

bool cmp(num a,num b)
{
	return a.val>b.val;
}

struct cpair
{
	int v,a,b,pos;
}q[SIZE];

bool cmp1(cpair a,cpair b)
{
	if(a.v==b.v)
	{
		a.b>b.b;
	}
	return a.v>b.v;
}

struct trees
{
	int sum,size,flag;
};

trees tree[SIZE<<3];

trees merge(trees a, trees b)
{
	trees res;
	res.sum=a.sum+b.sum;
	res.size=a.size+b.size;
	if(a.flag>0 &&b.flag>0)
		res.flag=1;
	else
		res.flag=0;
	// res.flag=a.flag & b.flag;
	return res;
}

void build(int node, int start, int end)
{
	if(start==end)
	{
		tree[node].sum=0;
		tree[node].size=1;
		tree[node].flag=0;
		return;
	}
	int mid=start+end>>1;
	build(2*node,start,mid);
	build(2*node+1,mid+1,end);
	tree[node]=merge(tree[2*node],tree[2*node+1]);
}

void update(int node,int start,int end,int x)
{
	if(start==x && end==x)
	{
		tree[node].sum=1;
		tree[node].flag=1;
		return;
	}
	if(start>end || start>x || end<x)
		return;
	int mid=start+end>>1;
	update(2*node,start,mid,x);
	update(2*node+1,mid+1,end,x);
	tree[node]=merge(tree[2*node],tree[2*node+1]);
}

int query(int node,int a,int b)
{
	int s=0;
	if(tree[node].flag==1)
	{
		/*for(int i=a;i<=b;i++)
		{
			if(tree[node].sum-(i-1)>0)
			{
				s+=tree[node].sum-(i-1);
			}
		}*/

		if(tree[node].size<b) //using sum of AP
		{
			int start=1;
			int end=tree[node].sum-(a-1);
			s+=(end-start+1)*(start+end);	
			s/=2;
		}
		else
		{
			int start=tree[node].sum-(b-1);
			int end=tree[node].sum-(a-1);
			s+=(end-start+1)*(start+end);
			s/=2;	
		}
		return s;
	}
	else if(tree[node].size>1)
	{
		return query(2*node,a,b)+query(2*node+1,a,b);
	}
	else
	{
		return 0;
	}
}

int main()
{
	scanf("%d %d",&n,&qu);

	int result[qu+5];

	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].val);
		a[i].index=i;
	}

	sort(a+1, a+1+n, cmp);

	for(int i=1;i<=qu;i++)
	{
		scanf("%d%d%d",&q[i].v,&q[i].a,&q[i].b);
		q[i].pos=i;
	}

	sort(q+1, q+1+qu, cmp1);

	build(1,1,n);

	int j=1;
	for(int i=1;i<=qu;i++)
	{
		while(j<=n && a[j].val>=q[i].v) //using the concept of kquery
		{

			update(1,1,n,a[j].index);
			j++;
		}

		/*printf("%d\n", query(1,q[i].a,q[i].b));*/
		result[q[i].pos]=query(1,q[i].a,q[i].b);
		/*printf("\n");
		for (int k = 1; k <= 2*n-1 ; k++)
		{
			printf("%d %d %d\n", tree[k].sum, tree[k].size, tree[k].flag);
		}
		printf("\n");*/
	}

	for(int i=1;i<=qu;i++)
	{
		printf("%d\n", result[i]);
	}
	return 0;
}