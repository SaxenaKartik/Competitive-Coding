//range query 

#include <bits/stdc++.h>
using namespace std;
#define RANGE 4*50005

int a[50005];
int tree[RANGE];
int prefixsum[RANGE];
int suffixsum[RANGE];
int maxsum[RANGE];
int sum[RANGE];


void build(int node,int start, int end)
{
	if(start>end)
		return;

	if(start==end)
	{
		tree[node]=prefixsum[node]=suffixsum[node]=maxsum[node]=sum[node]=a[start];
		return ;
	}	

	int mid=(start+end)>>1;

	build(2*node,start,mid);
	build(2*node+1, mid+1, end);

	sum[node]=sum[2*node]+sum[2*node+1]; //calculating total sum of range
	prefixsum[node]=max(prefixsum[2*node],sum[2*node]+prefixsum[2*node+1]); //max prefixsum
	suffixsum[node]=max(suffixsum[2*node+1],sum[2*node+1]+suffixsum[2*node]); //max suffixsum 

	maxsum[node]=max(max(maxsum[2*node],maxsum[2*node+1]),(suffixsum[2*node]+prefixsum[2*node+1]));
	// maxsum[node]=max(prefixsum[node],max(suffixsum[node],max(maxsum[2*node],max(maxsum[2*node+1],suffixsum[2*node]+prefixsum[2*node+1])))); //maxsum
	// maxsum[node]=max(maxsum[2*node],max(maxsum[2*node+1],suffixsum[2*node]+prefixsum[2*node+1])); //maxsum
	tree[node]=maxsum[node];
}

int query(int node, int start, int end, int l, int r)
{
	if(start==l && end==r)
	{
		maxsum[node]=tree[node];
		return node;
	}
	int p1=2*node;
	int p2=2*node+1;

	int mid=(start+end)>>1;
	
	if(r<=mid) return query(p1,start,mid,l,r);
	else if(l>mid) return query(p2,mid+1,end,l,r);
	else
	{
		int k1=query(p1,start,mid,l,mid);
		int k2=query(p2,mid+1,end,mid+1,r);

		sum[node]=sum[k1]+sum[k2]; //calculating total sum of range
		prefixsum[node]=max(prefixsum[k1],sum[k1]+prefixsum[k2]); //max prefixsum
		suffixsum[node]=max(suffixsum[k2],sum[k2]+suffixsum[k1]); //max suffixsum 
	
		maxsum[node]=max(max(maxsum[k1],maxsum[k2]),(suffixsum[k1]+prefixsum[k2]));

		// maxsum[node]=max(prefixsum[node],max(suffixsum[node],max(maxsum[p1],max(maxsum[p2],suffixsum[p1]+prefixsum[p2])))); //maxsum
		// maxsum[node]=max(maxsum[2*node],max(maxsum[2*node+1],suffixsum[2*node]+prefixsum[2*node+1])); //maxsum
		return node;

	}
}

int main()
{
	int n;

	scanf("%d",&n);

	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}

	build(1,1,n);

	int q;

	scanf("%d",&q);

	while(q--)
	{
		int x,y;

		scanf("%d %d",&x,&y);

		cout<<maxsum[query(1,1,n,x,y)]<<endl;
	}
}