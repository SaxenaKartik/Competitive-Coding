#include <bits/stdc++.h>
using namespace std;
#define ll long long 

ll n;
const int maxn=4e4+7;
vector<pair<int,int> > points(maxn);
map<int ,int> compress;

int tree[4*maxn];
int lazy[4*maxn];

void update(int node, int start ,int end , int l, int r, int val)
{
	if(lazy[node])
	{
		tree[node]=lazy[node];
		if(start!=end)
		{
			lazy[2*node]=lazy[node];
			lazy[2*node+1]=lazy[node];
		}
		lazy[node]=0;
	}

	if(start>r || end<l)
	{
		return ;
	}

	if(l<=start && end <=r)
	{
		tree[node]=val;
		if(start!=end)
		{
			lazy[2*node]=val;
			lazy[2*node+1]=val;
		}
		lazy[node]=0;
		return ;
	}

	int mid=(start+end)>>1;
	update(2*node,start,mid,l,r,val);
	update(2*node+1, mid+1,end,l,r,val);
	tree[node]=val;
}

int query(int node, int start, int end, int l, int r)
{
	if(lazy[node])
	{
		tree[node]=lazy[node];
		if(start!=end)
		{
			lazy[2*node]=lazy[node];
			lazy[2*node+1]=lazy[node];
		}
		lazy[node]=0;
	}

	if(start>r || end<l)
		return -1;
	if(l<=start && end <=r)
	{
		return tree[node];
	}
	int mid=(start+end)>>1;

	return max(query(2*node,start,mid,l,r),query(2*node+1,mid+1,end, l,r));
}


int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		compress.clear();
		points.clear();

		memset(tree,0,sizeof(tree));
		memset(lazy,0,sizeof(lazy));

		scanf("%lld", &n);
		for(int i=0;i<n;i++)
		{
			scanf("%d%d", &points[i].first, &points[i].second);
			compress[points[i].first]=compress[points[i].second]=1;
		}

		int a=0;
		for(auto &x:compress)
		{
			x.second=a++;
		}

		for(int i=0;i<n;i++)
		{
			update(1,0,maxn-1,compress[points[i].first],compress[points[i].second],i+1);
		}

		set<int> ans;
		for(int i=0;i<maxn-1;i++)
			ans.insert(query(1,0,maxn-1,i,i));	

		int k=ans.size();

		if(ans.find(0)!=ans.end())
				k--;
		printf("%d\n", k);
	}
	return 0;		
}	