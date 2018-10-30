//segment tree implementation
#include <bits/stdc++.h>
using namespace std;
#define INF 100005
#define ll long long

int tree[400005];
int a[100005];

void build(int node,int start,int end)
{
	
	if(start==end)
	{
		tree[node]=a[start];
	}

	else
	{
		int mid=(start+end)/2;
		build(2*node,start,mid);
		build(2*node+1,mid+1,end);
		if(tree[2*node]>=INF)
		{
			tree[node]=tree[2*node+1];
		}
		else if(tree[2*node+1]>=INF)
		{
			tree[node]=tree[2*node];
		}
		else
			tree[node]=min(tree[2*node],tree[2*node+1]);
	}
}

void update(int node,int start,int end,int x,int val)
{
	if(start==end)
	{
		a[x]=val;
		tree[node]=val;
	}
	else
	{
		int mid=(start+end)/2;
		if(start<=x && x<=mid)
		{
			update(2*node,start,mid,x,val);
		}
		else
		{
			update(2*node+1,mid+1,end,x,val);
		}
		tree[node]=min(tree[2*node],tree[2*node+1]);
	}
}

int query(int node,int start,int end,int l,int r)
{	
	if(r<start || end<l)
	{
		return INF;
	}
	if(l<=start && end<=r)
	{
		return tree[node];
	}
	int mid=(start+end)/2;
	int p1=query(2*node,start,mid,l,r);
	int p2=query(2*node+1,mid+1,end,l,r);
	return min(p1,p2);
}

int main()
{
	int n,q;
	cin>>n>>q;

	// int a[n];

	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	memset(tree,INF,sizeof(tree));
	build(1,1,n);

	char c;
	int x,y;

	/*for(int i=1;i<=2*n-1;i++)
	{	
		cout<<tree[i]<<endl;	
	}
*/

	while(q--)
	{
		cin>>c>>x>>y;
		if(c=='q')
		{
			int min=query(1,1,n,x,y);
			cout<<min<<endl;
		}
		else if(c=='u')
		{
			update(1,1,n,x,y);
		}
	}
	return 0;
}