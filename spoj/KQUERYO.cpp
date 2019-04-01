//using merge sort tree 

#include <bits/stdc++.h>
using namespace std;
#define SIZE 30005
#define ll long long 
int n,qu;

int a[SIZE];

struct kqueryo
{	
	int l,r;
	ll k;
}q[200005];

struct trees
{
	vector<int> v;
	// int count;
};

trees tree[300005<<3];

/*trees merges(trees a,trees b)
{
	trees res;
	merge(a.v.begin(), a.v.end(),b.v.begin(), b.v.end(),res.v.begin());
	// res.count=a.count+b.count;
	return res;
}*/

void build(int node,int start,int end)
{
	if(start==end)
	{
		tree[node].v.push_back(a[start]);
		// tree[node].count=0;
		return ;
	}
	int mid=start+end>>1;
	build(2*node,start,mid);
	build(2*node+1,mid+1,end);
	tree[node].v.resize(tree[2*node].v.size()+tree[2*node+1].v.size());
	merge(tree[2*node].v.begin(),tree[2*node].v.end(),tree[2*node+1].v.begin(),tree[2*node+1].v.end(),tree[node].v.begin());
}

/*

without sorting the elements in the vectors

void update(int node, int start, int end, int l, int r, int k)
{
	if(start>end || start>r || l>end)
		return;	
	if(start==end)
	{
		if(tree[node].v[0]>k)
			tree[node].count=1;
		else 
			tree[node].count=0;
		return;
	}
	int mid=start+end>>1;
	if(r<=mid) update(2*node,start,mid,l,r,k);
	else if(l>mid) update(2*node+1,mid+1,end,l,r,k);
	else
	{
		update(2*node,start,mid,l,r,k);
		update(2*node+1,mid+1,end,l,r,k);
	}
	tree[node]=merge(tree[2*node],tree[2*node+1]);
}*/

int query(int node,int start, int end, int l, int r,int k)
{
	if(start>end || r<start || end<l)
		return 0;
	if(l<=start && end<=r)
	{	
		return tree[node].v.end()-upper_bound(tree[node].v.begin(),tree[node].v.end(),k);
		// return tree[node].count;
	}
	int mid=start+end>>1;
	return query(2*node,start,mid,l,r,k)+query(2*node+1,mid+1,end,l,r,k);
}

int main()
{
	int s=0;
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}

	build(1,1,n);

	scanf("%d",&qu);
	for(int i=1;i<=qu;i++)
	{
		int a,b;
		ll c;
		scanf("%d%d%lld",&a,&b,&c);
		q[i].l=a^s;
		q[i].r=b^s;
		q[i].k=c^s;

		if(q[i].l<1) q[i].l=1;
		if(q[i].r>n) q[i].r=n;

		if(q[i].l>q[i].r) s=0;
		else
		{
			// update(1,1,n,q[i].l,q[i].r,q[i].k);
			s=query(1,1,n,q[i].l,q[i].r,q[i].k);
		}
		printf("%d\n", s);
	}
}