#include <bits/stdc++.h>
using namespace std;
#define SIZE 1000005
int n;
string s;

struct trees
{
	int ans;
	int open;
	int close;
};

trees tree[SIZE<<3];

trees merge(trees a,trees b)
{
	trees res;
	int temp=min(a.open,b.close);
	res.ans=a.ans+b.ans+2*temp;
	res.open=a.open+b.open-temp;
	res.close=a.close+b.close-temp;
	return res;
}

void build(int node,int start,int end)
{
	if(start==end)
	{
		if(s[start-1]=='(')
		{
			tree[node].ans=0;
			tree[node].open=1;
			tree[node].close=0;
		}
		else
		{
			tree[node].ans=0;
			tree[node].open=0;
			tree[node].close=1;
		}
		return;
	}
	int mid=(start+end)>>1;
	build(2*node,start,mid);
	build(2*node+1,mid+1,end);
	tree[node]=merge(tree[2*node],tree[2*node+1]);
}

trees query(int node,int start,int end, int l , int r)
{
	if(start>end || start>r || end<l)
		return (trees){0,0,0};
	if(l<=start && end<=r)
	{
		return tree[node];
	}
	int mid=(start+end)>>1;
	return merge(query(2*node,start,mid,l,r),query(2*node+1,mid+1,end,l,r));
}

int main()
{
	cin>>s;
	n=s.length();

	build(1,1,n);

	/*for(int i=1;i<=2*n-1;i++)
	{
		printf("%d %d %d\n", tree[i].ans, tree[i].open, tree[i].close);
	}*/

	int m;
	scanf("%d",&m);

	for(int i=0;i<m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n", query(1,1,n,x,y).ans);
	}
}